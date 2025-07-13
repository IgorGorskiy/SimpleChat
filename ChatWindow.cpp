#include "ChatWindow.h"
#include "eventnotificationwidget.h"
#include "ui_ChatWindow.h"

#include <QMessageBox>
#include <QScrollBar>

ChatWindow::ChatWindow(ConnectionSettings con, QWidget *parent)
    : QMainWindow(parent),
    connectionSettings(con),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    connectionSettings = con;

    // в идеале бы вообще не держать адреса менеджеров в других менеджерах, но идеал не всегда достижим)))
    m_dbManager = new DatabaseManager();
    m_messageComposer = new MessageComposer();
    m_ackManager = new AckManager();
    m_networkManager = new NetworkManager(m_ackManager, con);
    m_chatManager = new ChatManager(m_networkManager, m_ackManager);
    m_notificationManager = new NotificationManager(ui->eventsContainerLayout);
    m_fileTransferManager = new FileTransferManager(m_notificationManager);
    m_protocolHandler = new ProtocolHandler();
    m_packetReassembler = new PacketReassembler();

    ui->tabWidget->setTabText(0, "Чат");
    ui->tabWidget->setTabText(1, "Уведомления");
    ui->tabWidget->setTabText(2, "Настройки");
    //ui->eventsContainerLayout->setAlignment(Qt::AlignTop);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->myPort->setText(QString::number(connectionSettings.localPort));
    ui->myAddress->setText(connectionSettings.localAddress.toString());
    ui->remotePort->setText(QString::number(connectionSettings.remotePort));
    ui->remoteAddress->setText(connectionSettings.remoteAddress.toString());
    connect(ui->sendFileButton, &QPushButton::clicked, this,
            &ChatWindow::onSendFileButtonClicked);
    connect(ui->myPort, &QLineEdit::editingFinished, this,
            [this](){ChatWindow::onMyPortValueChanged(ui->myPort->text());});
    connect(ui->remotePort, &QLineEdit::editingFinished, this,
            [this](){ChatWindow::onRemotePortValueChanged(ui->remotePort->text());});
    connect(ui->remoteAddress, &QLineEdit::editingFinished, this,
            [this](){ChatWindow::onRemoteAddressValueChanged(ui->remoteAddress->text());});

    connect(ui->transmitInterval, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
            &ChatWindow::onTransmitIntervalvalueChanged);
    connect(ui->packetSize, &QSlider::valueChanged, this,
            &ChatWindow::on_packetSize_valueChanged);


    // Настраиваем отображение чата
    m_messageModel = new MessageModel(ui->listView, this);
    ui->listView->setModel(m_messageModel);
    ui->listView->setItemDelegate(new MessageDelegate(this));
    ui->listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->listView->setSpacing(5);
    ui->listView->setStyleSheet("background: #F5F5F5; border: none;");
    ui->listView->setResizeMode(QListView::Adjust); // Автоподстройка
    ui->listView->setWordWrap(true); // Перенос слов
    ui->listView->setUniformItemSizes(false); // Разные размеры элементов

    composerSettings.maxPacketSize = ui->packetSize->value();
    composerSettings.packetInterval = ui->transmitInterval->value();
    m_messageComposer->setComposerSettings(composerSettings);

    connect(ui->checkConnection, &QPushButton::clicked, this, [this](){ui->pingInfo->setText("Ожидание ответа");});
    connect(ui->checkConnection, &QPushButton::clicked, this, [this](){m_messageComposer->createPingDatagrams();});
    connect(ui->connectToDB, &QPushButton::clicked, this, &ChatWindow::onConnectToBD);

    initManagerConnections();
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::initManagerConnections(){
    connect(m_ackManager, &AckManager::textMessageDelivered, m_messageModel, &MessageModel::updateMessageStatus);
    connect(m_ackManager, &AckManager::textMessageError, m_messageModel, &MessageModel::updateMessageStatus);
    connect(m_ackManager, &AckManager::fileAckRecieved, m_fileTransferManager, &FileTransferManager::processFileAck);
    connect(m_ackManager, &AckManager::pingMeasured, this, [this](int ping){
        ui->pingInfo->setText("Задержка: " + QString::number(ping));});
    connect(m_ackManager, &AckManager::missingDatagramsReadyForSending, m_networkManager,
            &NetworkManager::sendDatagrams);


    connect(m_chatManager, &ChatManager::incomingMessageProcessed, m_protocolHandler,
            &ProtocolHandler::handleTextProcessed);
    connect(m_chatManager, &ChatManager::newMessageForDisplay, m_messageModel, &MessageModel::addMessage);
    connect(m_chatManager, &ChatManager::messageStatusUpdate, m_messageModel,
            &MessageModel::updateMessageStatus);

    connect(m_fileTransferManager, &FileTransferManager::fileReadyToUpload, m_messageComposer,
            &MessageComposer::createFileDatagrams);

    connect(m_messageComposer, &MessageComposer::datagramsReadyForSending, m_networkManager,
            &NetworkManager::sendDatagrams);
    connect(m_messageComposer, &MessageComposer::textMessageComposed, m_chatManager,
            &ChatManager::constructTextMessage);
    connect(m_messageComposer, &MessageComposer::transferRequestReady, m_fileTransferManager,
            &FileTransferManager::defineTransferInfo);

    connect(m_networkManager, &NetworkManager::datagramReady, m_packetReassembler,
            &PacketReassembler::processIncomingDatagram);
    connect(m_networkManager, &NetworkManager::uploadProgress, m_fileTransferManager,
            &FileTransferManager::updateSentFileProgress);
    connect(m_networkManager, &NetworkManager::textMessageSent, m_messageModel,
            &MessageModel::updateMessageStatus);
    connect(m_networkManager, &NetworkManager::socketError, this,
            [this](){QMessageBox::critical(this, "Error", "Не удалось забиндить сокет");});

    connect(m_notificationManager, &NotificationManager::fileTransferAccepted, m_messageComposer,
            &MessageComposer::createFileTransferPermissionDatagrams);
    connect(m_notificationManager, &NotificationManager::fileTransferAccepted, m_fileTransferManager,
            &FileTransferManager::handleFileTransferAnswer);
    connect(m_notificationManager, &NotificationManager::fileTransferRejected, m_messageComposer,
            &MessageComposer::createFileTransferPermissionDatagrams);
    connect(m_notificationManager, &NotificationManager::fileTransferRejected, m_fileTransferManager,
            &FileTransferManager::handleFileTransferAnswer);

    connect(m_packetReassembler, &PacketReassembler::fullMessageReady, m_protocolHandler,
            &ProtocolHandler::handleFullMessage);
    connect(m_packetReassembler, &PacketReassembler::reQueryNeeded, m_messageComposer,
            &MessageComposer::createReQueryDatagrams);
    connect(m_packetReassembler, &PacketReassembler::downloadProgress, m_fileTransferManager,
            &FileTransferManager::updateReceivedFileProgress);

    connect(m_protocolHandler, &ProtocolHandler::reQueryReceived, m_ackManager,
            &AckManager::processIncomingReQuery);
    connect(m_protocolHandler, &ProtocolHandler::ackNeeded, m_messageComposer,
            &MessageComposer::createAckDatagrams);
    connect(m_protocolHandler, &ProtocolHandler::textMessageRecieved, m_chatManager,
            &ChatManager::processIncomingTextMessage);
    connect(m_protocolHandler, &ProtocolHandler::ackReceived, m_ackManager,
            &AckManager::processIncomingAck);
    connect(m_protocolHandler, &ProtocolHandler::fileDownloaded, m_fileTransferManager,
            &FileTransferManager::processFileDownloaded);
    connect(m_protocolHandler, &ProtocolHandler::fileTransferRequestReceived, m_fileTransferManager,
            &FileTransferManager::processFileTransferRequest);
    connect(m_protocolHandler, &ProtocolHandler::fileTransferPermissionReceived, m_fileTransferManager,
            &FileTransferManager::processFileTransferPermission);
}

void ChatWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    ui->listView->doItemsLayout(); // Пересчет layout
}

void ChatWindow::on_sendButton_clicked()
{
    QString message = ui->messageInput->toPlainText().trimmed();
    if (message.isEmpty())  {return;}

    m_messageComposer->createTextDatagrams(message);

    ui->messageInput->clear();
}

void ChatWindow::onSendFileButtonClicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл для отправки",
                                                    QDir::homePath(),
                                                    "Все файлы (*.*)");
    if (!filePath.isEmpty()) {
        m_messageComposer->createFileTransferRequestDatagrams(filePath);
    }
}

void ChatWindow::onRemoteAddressValueChanged(const QString& value){
    connectionSettings = m_networkManager->getConnectionSettings();
    connectionSettings.remoteAddress.setAddress(value);
    m_networkManager->setConnectionSettings(connectionSettings);
}
void ChatWindow::onRemotePortValueChanged(const QString& value){
    connectionSettings = m_networkManager->getConnectionSettings();
    connectionSettings.remotePort = value.toUInt();
    m_networkManager->setConnectionSettings(connectionSettings);
}
void ChatWindow::onMyPortValueChanged(const QString& value){
    connectionSettings = m_networkManager->getConnectionSettings();
    connectionSettings.localPort = value.toUInt();
    m_networkManager->setConnectionSettings(connectionSettings);
}

QString ChatWindow::getCurrentTimestamp()
{
    return QDateTime::currentDateTime().toString("hh:mm:ss");
}

void ChatWindow::on_packetSize_valueChanged(int value)
{
    composerSettings = m_messageComposer->getComposerSettings();
    composerSettings.maxPacketSize = value;
    m_messageComposer->setComposerSettings(composerSettings);
    ui->packetSizeLabel->setText(QString("Max Packet Size: %1 bytes").arg(value));
}

void ChatWindow::onTransmitIntervalvalueChanged(int value){
    composerSettings = m_messageComposer->getComposerSettings();
    composerSettings.maxPacketSize = value;
    m_messageComposer->setComposerSettings(composerSettings);
}

void ChatWindow::onConnectToBD(){
    QString dbName = ui->dbName->text();
    QString dbUser = ui->dbUser->text();
    QString dbPassword = ui->dbPassword->text();
    if(dbName == "" || dbUser == "" || dbPassword == ""){
        ui->dbStatus->setText("Одно из полей не заполнено, " +
                (dbConnected ? "сохраняется подключение к " + ChatWindow::dbName : "подключение не установлено"));
        return;
    }

    if(m_dbManager->connectToDatabase(dbName, dbUser, dbPassword))
    {
        ui->dbStatus->setText("Успешное подключение к базе " + dbName);
        ui->dbName->clear();
        ui->dbUser->clear();
        ui->dbPassword->clear();
        connect(m_messageModel, &MessageModel::messageReadyForDB, m_dbManager, &DatabaseManager::saveMessage);
        dbConnected = true;
        ChatWindow::dbName = dbName;
    }
    else
        ui->dbStatus->setText("Не удалось подключиться к базе " + dbName);
}
