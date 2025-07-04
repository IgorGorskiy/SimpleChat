#include "ChatWindow.h"
#include "eventnotificationwidget.h"
#include "ui_ChatWindow.h"

#include <QMessageBox>
#include <QScrollBar>

ChatWindow::ChatWindow(ConnectionSettings con, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ChatWindow),
    m_commands(this)
{
    connectionSettings = con;
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Чат");
    ui->tabWidget->setTabText(1, "Уведомления");
    ui->tabWidget->setTabText(2, "Настройки");
    //ui->eventsContainerLayout->setAlignment(Qt::AlignTop);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->myPort->setText(QString::number(connectionSettings.localPort));
    ui->remotePort->setText(QString::number(connectionSettings.remotePort));
    ui->remoteAddress->setText(connectionSettings.remoteAddress.toString());
    connect(ui->sendFileButton, &QPushButton::clicked, this, &ChatWindow::onSendFileButtonClicked);
    ui->myAddress->setText(connectionSettings.localAddress.toString());
    connect(ui->myPort, &QLineEdit::editingFinished, this, [this](){ChatWindow::onMyPortValueChanged(ui->myPort->text());});
    connect(ui->remotePort, &QLineEdit::editingFinished, this, [this](){ChatWindow::onRemotePortValueChanged(ui->remotePort->text());});
    connect(ui->remoteAddress, &QLineEdit::editingFinished, this, [this](){ChatWindow::onRemoteAddressValueChanged(ui->remoteAddress->text());});
    connect(ui->checkConnection, &QPushButton::clicked, this, [this](){ChatWindow::sendPing();});
    //checkConnection
    m_commands.initializeCommands();

    // Настраиваем отображение чата
    ui->chatDisplay->setReadOnly(true);
    ui->chatDisplay->setTextInteractionFlags(Qt::TextSelectableByMouse);
    // Initialize UDP socket
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, &QUdpSocket::readyRead, this, &ChatWindow::readPendingDatagrams);
    bindSocket(connectionSettings.localPort);
    // Set default packet size
    ui->packetSize->setValue(maxPacketSize);

    // Initialize timer
    updateTimer = new QTimer(this);
    updateTimer->setInterval(1000);
    updateTimer->start();

    m_threadPool.setMaxThreadCount(5); // Максимум 5 одновременных отправок

    // Таймер для проверки подтверждений
    QTimer *confirmationTimer = new QTimer(this);
    connect(confirmationTimer, &QTimer::timeout, this, &ChatWindow::checkPendingConfirmations);
    confirmationTimer->start(1000); // Проверка каждую секунду
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::bindSocket(const quint16 &newPort)
{
    udpSocket->close();
    if (!udpSocket->bind(newPort, QUdpSocket::ShareAddress)) {
        QMessageBox::critical(this, "Error", "Could not bind to port " + QString::number(connectionSettings.localPort));
        close();
        return;
    }
    connectionSettings.localPort = newPort;
}

ChatWindow::Commands::Commands(ChatWindow* parent)
    : m_parent(parent) {}

void ChatWindow::Commands::initializeCommands()
{
    commandHandlers = {
        {"/help", [this](const QString&) { processHelp(); }},
        {"/clear", [this](const QString&) { processClear(); }},
        {"/setlocalport", [this](const QString& args) { processSetLocalPort(args); }},
        {"/setremoteport", [this](const QString& args) { processSetRemotePort(args); }},
        {"/setremoteaddress", [this](const QString& args) { processSetRemoteAddress(args); }},
        {"/getlocalport", [this](const QString&) { processGetLocalPort(); }},
        {"/getremoteport", [this](const QString&) { processGetRemotePort(); }},
        {"/getremoteaddress", [this](const QString&) { processGetRemoteAddress(); }},
        {"/testevent", [this](const QString&) { processTestEvent(); }}
    };
}

// Реализации обработчиков команд

void ChatWindow::Commands::processCommand(QString& command)
{
    command = command.trimmed();
    if (!command.startsWith('/')) {
        return; // Не команда
    }

    QStringList parts = command.split(' ', Qt::SkipEmptyParts);
    QString cmd = parts.first().toLower();
    QString args = parts.size() > 1 ? command.mid(cmd.length()).trimmed() : "";

    if (commandHandlers.contains(cmd)) {
        commandHandlers[cmd](args);
    } else {
        m_parent->displayMessage("Неизвестная команда. Введите /help для списка команд");
    }
}

void ChatWindow::Commands::processSetLocalPort(const QString& port)
{
    quint16 newPort = port.toUInt();
    m_parent->bindSocket(newPort);
    m_parent->displayMessage("local port: " + QString::number(m_parent->connectionSettings.localPort));
}
void ChatWindow::Commands::processSetRemotePort(const QString& port)
{
    quint16 newPort = port.toUInt();
    m_parent->connectionSettings.remotePort = newPort;
    m_parent->displayMessage("remote port: " + QString::number(m_parent->connectionSettings.remotePort));
}
void ChatWindow::Commands::processSetRemoteAddress(const QString& address)
{
    m_parent->connectionSettings.remoteAddress.setAddress(address);
    m_parent->displayMessage("remote address: " + m_parent->connectionSettings.remoteAddress.toString());
}
void ChatWindow::Commands::processGetLocalPort()
{
    m_parent->displayMessage("local port: " + QString::number(m_parent->connectionSettings.localPort));
}
void ChatWindow::Commands::processGetRemotePort()
{
    m_parent->displayMessage("remote port: " + QString::number(m_parent->connectionSettings.remotePort));
}
void ChatWindow::Commands::processGetRemoteAddress()
{
    m_parent->displayMessage("remote address: " + m_parent->connectionSettings.remoteAddress.toString());
}
void ChatWindow::Commands::processHelp()
{
    QString helpText =  "Доступные команды:\n"
                        "/help - эта справка\n"
                        "/clear - очистить чат\n"
                        "/setlocalport [порт] - задать локальный порт\n"
                        "/setremoteport [порт] - задать порт получателя\n"
                        "/setremoteaddress [адрес] - задать адрес получателя\n"
                        "/getlocalport [порт] - узнать текущий локальный порт\n"
                        "/getremoteport [порт] - узнать текущий порт получателя\n"
                        "/getremoteaddress [адрес] - узнать текущий адрес получателя\n"
                        "/testevent - вызвать тестовое событие";
    m_parent->displayMessage(helpText, true);
}
void ChatWindow::Commands::processClear() {
    m_parent->ui->chatDisplay->clear();
}
void ChatWindow::Commands::processTestEvent(){
    m_parent->createEventNotification("me", EventType::FileTransferRequestRecieved, "хочешь файл?");
}

void ChatWindow::on_sendButton_clicked()
{
    QString message = ui->messageInput->toPlainText().trimmed();
    if (message.isEmpty())  {return;}

    if (message.startsWith('/'))    {m_commands.processCommand(message);}
    else    {sendMessage(message);}

    ui->messageInput->clear();
}

void ChatWindow::onSendFileButtonClicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл для отправки",
                                                    QDir::homePath(),
                                                    "Все файлы (*.*)");
    if (!filePath.isEmpty()) {
        askToSendFile(filePath);
    }
}

void ChatWindow::sendPing(QTime creationTime, bool isResponce){
    MessageHeader pingHeader;
    pingHeader.messageId = nextMessageId++;
    pingHeader.packetNumber = 1;
    pingHeader.totalPackets = 1;
    if (isResponce)
        pingHeader.messageType = MessageType::PingAnswer;
    else{
        pingHeader.messageType = MessageType::Ping;
        ui->pingInfo->setText("Ожидание ответа...");
    }
    auto payload = creationTime;
    pingHeader.payloadSize = sizeof(payload);
    QByteArray datagram;
    datagram.resize(sizeof(pingHeader) + sizeof(payload));
    memcpy(datagram.data(), &pingHeader, sizeof(pingHeader));
    memcpy(datagram.data() + sizeof(pingHeader), &payload, sizeof(payload));
    udpSocket->writeDatagram(datagram, connectionSettings.remoteAddress, connectionSettings.remotePort);
}
void ChatWindow::onRemoteAddressValueChanged(const QString& value){ connectionSettings.remoteAddress.setAddress(value);}
void ChatWindow::onRemotePortValueChanged(const QString& value){connectionSettings.remotePort = value.toUInt();}
void ChatWindow::onMyPortValueChanged(const QString& value){ChatWindow::bindSocket(value.toUInt());}

void ChatWindow::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        processDatagram(datagram, sender, senderPort);
    }
}

void ChatWindow::processDatagram(const QByteArray &datagram, const QHostAddress &sender, quint16 senderPort)
{
    if (datagram.size() < sizeof(MessageHeader)) {
        qDebug() << "Received datagram too small to contain header";
        return;
    }

    MessageHeader header;
    memcpy(&header, datagram.constData(), sizeof(MessageHeader));

    // Verify packet number is valid
    if (header.packetNumber == 0 || header.packetNumber > header.totalPackets) {
        qDebug() << "Invalid packet number:" << header.packetNumber;
        return;
    }

    // Verify payload size
    quint32 expectedSize = sizeof(MessageHeader) + header.payloadSize;
    if (datagram.size() != expectedSize) {
        qDebug() << "Payload size mismatch. Expected:" << expectedSize << "Actual:" << datagram.size();
        return;
    }
    //лютый костыль - обновляем прогресс-бар скачки файла
    if (header.messageType == MessageType::FileChunk){
        if(ongoingDdownloads.contains(header.messageId))
            ongoingDdownloads.value(header.messageId).second->setProgressBarValue(
                100*header.packetNumber/header.totalPackets);
    }

    IncompleteMessage &msg = incompleteMessages[header.messageId];
    msg.messageId = header.messageId;
    msg.totalPackets = header.totalPackets;
    msg.lastPacketTime = QDateTime::currentDateTime();

    QByteArray payload;
    payload.resize(header.payloadSize);
    payload = datagram.mid(sizeof(MessageHeader));

    if (!msg.packets.contains(header.packetNumber)) {
        msg.packets[header.packetNumber] = payload;
        msg.receivedPackets++;
    }

    QByteArray fullMessage;
    // Проверяем, собрано ли все сообщение
    if (checkMessageCompletion(header.messageId, header.messageType)){

        // Собираем полное сообщение
        for (int i = 1; i <= msg.totalPackets; ++i) {
            fullMessage += msg.packets[i];
        }
        // Удаляем из очереди
        incompleteMessages.remove(header.messageId);
        QTime time;
        switch (header.messageType) {
        case MessageType::TextMessage:
            // Отображаем сообщение
            displayMessage(QString::fromUtf8(fullMessage), false);
            sendAck(header, connectionSettings.remoteAddress, connectionSettings.remotePort);
            break;
        case MessageType::FileChunk:
            sendAck(header, connectionSettings.remoteAddress, connectionSettings.remotePort);
            saveReceivedFile(sender.toString(), header.messageId, fullMessage);
            break;
        case MessageType::Ack:
            AckPacket ackPacket;
            memcpy(&ackPacket, fullMessage, sizeof(AckPacket));
            processAck(sender.toString(), ackPacket);
            break;
        case MessageType::FileTransferRequest:
            processFileTransferRequest(sender.toString(), fullMessage);
            break;
        case MessageType::FileTransferPermission:
            processFileTransferPermission(sender.toString(), fullMessage);
        case MessageType::Ping:
            memcpy(&time, fullMessage.data(), sizeof(time));
            sendPing(time, true);
            break;
        case MessageType::PingAnswer:
            quint16 ping;
            memcpy(&time, fullMessage.data(), sizeof(time));
            ping = time.msecsTo(QTime::currentTime());
            ui->pingInfo->setText("Задержка: " + QString::number(ping) + " миллисекунд");
            break;
        }
    }
}

void ChatWindow::sendAck(MessageHeader originalHeader, const QHostAddress &address, quint16 port) {
    MessageHeader ackHeader;
    ackHeader.messageType = MessageType::Ack; // Квитанция
    ackHeader.messageId = nextMessageId++;
    ackHeader.packetNumber = 1;
    ackHeader.totalPackets = 1;
    ackHeader.payloadSize = sizeof(AckPacket);
    AckPacket payload;
    payload.originalHeader = originalHeader;
    payload.checkSum = 0; // заглушка

    QByteArray ackDatagram(sizeof(MessageHeader) + sizeof(payload), '\0');
    memcpy(ackDatagram.data(), &ackHeader, sizeof(MessageHeader));
    memcpy(ackDatagram.data() + sizeof(MessageHeader), &payload, sizeof(AckPacket));

    // Используем пул потоков для отправки квитанции
    MessageWorker *worker = new MessageWorker(
        {ackDatagram},
        address,
        port,
        0 // Нет задержки для ACK
        );

    m_threadPool.start(worker);
}

void ChatWindow::processAck(const QString& sender, AckPacket ackPacket){
    quint32 messageId = ackPacket.originalHeader.messageId;
    switch (ackPacket.originalHeader.messageType)
    {
    case MessageType::TextMessage:
    if (m_pendingMessages.contains(messageId)) {
        QString message = m_pendingMessages.value(messageId).second;
        m_pendingMessages.remove(messageId);
        displayMessage("[Delivered] " + message, true);
    }

    case MessageType::FileChunk:
    if (m_fileTransfers.contains(messageId)) {
        QString filePath = m_fileTransfers.value(messageId).first;
        displayMessage("[File delivered] " + filePath, true);
        EventNotificationWidget *widget = m_fileTransfers.value(messageId).second;
        QString description = tr("%1 получил ваш файл:\n%2").arg(sender, filePath);
        widget->setEventData(description, sender, EventType::FileDelivered);
        widget->showAcceptBtn(true);
        widget->showRejectBtn(false);
        widget->showProgressBar(false);
        connect(widget, &EventNotificationWidget::accepted, this,
                [this, messageId](){m_fileTransfers.remove(messageId);
                });
    }
    }
}

bool ChatWindow::checkMessageCompletion(quint32 messageId, quint8 messageType) {
    if (!incompleteMessages.contains(messageId)){
        QMessageBox::critical(this, "Error", "checkMessageCompletion called, but no incomplete messages found");
        close();
        return false;
    }

    IncompleteMessage &msg = incompleteMessages[messageId];

    if (msg.receivedPackets == msg.totalPackets) {
        // Удаляем таймер истечения ожидания сборки (если создали ранее)
        if (messageTimers.contains(messageId)){
        messageTimers[messageId]->stop();
        messageTimers.remove(messageId);
        }
        return true;
    }
    else{
        // Устанавливаем/обновляем таймер истечения ожидания сборки
        if (!messageTimers.contains(messageId))
        {
            QTimer *timer = new QTimer(this);
            timer->setInterval(1000); // 1 second timeout
            timer->setSingleShot(true);
            connect(timer, &QTimer::timeout, [this, &messageId](){processIncompleteMessage(messageId);});
            timer->start();
            messageTimers[messageId] = timer;
        }
        else
            messageTimers[messageId]->start();
        return false;
    }
}

void ChatWindow::processIncompleteMessage(quint32 messageId)
{

}

void ChatWindow::sendMessage(const QString &message)
{
    // Подготовка пакетов
    QVector<QByteArray> datagrams;
    quint32 messageId = nextMessageId++;
    quint32 remainingBytes = message.toUtf8().size();
    quint32 offset = 0;
    quint16 packetNumber = 0;
    quint16 totalPackets = ceil((double)remainingBytes / (maxPacketSize - sizeof(MessageHeader)));

    while (remainingBytes > 0) {
        packetNumber++;
        quint32 chunkSize = qMin(remainingBytes, (quint32)(maxPacketSize - sizeof(MessageHeader)));
        QByteArray payload = message.toUtf8().mid(offset, chunkSize);

        MessageHeader header;
        header.messageId = messageId;
        header.totalPackets = totalPackets;
        header.packetNumber = packetNumber;
        header.payloadSize = chunkSize;
        header.messageType = TextMessage;

        QByteArray datagram;
        datagram.resize(sizeof(MessageHeader) + chunkSize);
        memcpy(datagram.data(), &header, sizeof(MessageHeader));
        memcpy(datagram.data() + sizeof(MessageHeader), payload.constData(), chunkSize);
        //qDebug() << QString::fromUtf8(datagram.data() + sizeof(MessageHeader));
        //udpSocket->writeDatagram(datagram, connectionSettings.remoteAddress, connectionSettings.remotePort);

        datagrams.append(datagram);
        offset += chunkSize;
        remainingBytes -= chunkSize;
    }

    // Создаем и запускаем воркер
    MessageWorker *worker = new MessageWorker(
        datagrams,
        connectionSettings.remoteAddress,
        connectionSettings.remotePort,
        ui->transmitInterval->value()
        );

    // Подключаем сигналы
    //connect(worker, &MessageWorker::packetSent, this, &ChatWindow::onPacketSent);
    connect(worker, &MessageWorker::finished, this, &ChatWindow::onMessageSent);
    connect(worker, &MessageWorker::errorOccurred, this, &ChatWindow::onMessageError);

    // Сохраняем сообщение как ожидающее подтверждения
    m_pendingMessages.insert(messageId, {QDateTime::currentDateTime(), message});

    // Запускаем в отдельном потоке
    m_threadPool.start(worker);

    // Отображаем статус
    displayMessage("[Sending...] " + message, true);
}

void ChatWindow::askToSendFile(const QString &filePath)
{
    QFileInfo fileInfo(filePath);
    FileInfoHeader fileInfoHeader;
    fileInfoHeader.fileSize = fileInfo.size();
    fileInfoHeader.fileTransferMessageId = nextMessageId++;
    QByteArray fileName = fileInfo.fileName().toUtf8();
    fileInfoHeader.filenameLength = fileName.size();
    MessageHeader requestHeader;
    requestHeader.messageType = MessageType::FileTransferRequest; // Запрос разрешения на отправку
    requestHeader.messageId = nextMessageId++;
    requestHeader.packetNumber = 1;
    requestHeader.totalPackets = 1;
    requestHeader.payloadSize = sizeof(FileInfoHeader) + fileInfoHeader.filenameLength;
    // payload: FileInfoHeader & fileName

    QByteArray requestDatagram(sizeof(MessageHeader) + requestHeader.payloadSize, '\0');
    memcpy(requestDatagram.data(), &requestHeader, sizeof(MessageHeader));
    memcpy(requestDatagram.data() + sizeof(MessageHeader), &fileInfoHeader, sizeof(FileInfoHeader));
    memcpy(requestDatagram.data() + sizeof(MessageHeader) + sizeof(FileInfoHeader), fileName.data(), fileInfoHeader.filenameLength);

    m_fileTransfers.insert(fileInfoHeader.fileTransferMessageId, {filePath, nullptr});
    // Используем пул потоков для отправки запроса
    MessageWorker *worker = new MessageWorker(
        {requestDatagram},
        connectionSettings.remoteAddress,
        connectionSettings.remotePort,
        0 // Нет задержки для запроса на отправку файла
        );

    m_threadPool.start(worker);
}

void ChatWindow::sendFileTransferPermission(const QString &sender, QByteArray &eventData, bool permission)
{
    FileInfoHeader fileInfoHeader;
    memcpy(&fileInfoHeader, eventData.data(), sizeof(FileInfoHeader));
    fileInfoHeader.permissionGiven = permission; // назначаем разрешение на отправку
    memcpy(eventData.data(), &fileInfoHeader, sizeof(FileInfoHeader));
    QString fileName = QString::fromUtf8(eventData.mid(sizeof(FileInfoHeader), fileInfoHeader.filenameLength));
    QString fileSizeKB = QString::number(fileInfoHeader.fileSize/1024);
    QString details = tr("Название: %1, размер:%2 KB").arg(fileName, fileSizeKB);
    if(permission){ // добавляем файл в "текущие загрузки"
        QString fileName = QString::fromUtf8(eventData.mid(sizeof(FileInfoHeader), fileInfoHeader.filenameLength));
        if (!ongoingDdownloads.contains(fileInfoHeader.fileTransferMessageId)){
            EventNotificationWidget *downloadEvent = createEventNotification(sender, EventType::FileDownloading, details);
            ongoingDdownloads.insert(fileInfoHeader.fileTransferMessageId, {fileName, downloadEvent});
        }
    }
    MessageHeader permissionHeader;
    permissionHeader.messageType = MessageType::FileTransferPermission; // разрешение на отправку
    permissionHeader.messageId = nextMessageId++;
    permissionHeader.packetNumber = 1;
    permissionHeader.totalPackets = 1;
    permissionHeader.payloadSize = sizeof(FileInfoHeader) + fileInfoHeader.filenameLength;
    // payload: FileInfoHeader & fileName
    QByteArray datagram(sizeof(MessageHeader) + sizeof(FileInfoHeader) + fileInfoHeader.filenameLength, '\0');
    memcpy(datagram.data(), &permissionHeader, sizeof(MessageHeader));
    memcpy(datagram.data() + sizeof(MessageHeader), eventData, sizeof(FileInfoHeader) + fileInfoHeader.filenameLength);

    // Используем пул потоков для отправки запроса
    MessageWorker *worker = new MessageWorker(
        {datagram},
        connectionSettings.remoteAddress,
        connectionSettings.remotePort,
        0 // Нет задержки для запроса на отправку файла
        );

    m_threadPool.start(worker);
}

void ChatWindow::sendFile(quint32 messageId) {
    if (!m_fileTransfers.contains(messageId))
        return;

    QString filePath = m_fileTransfers.value(messageId).first;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        displayMessage("File open error: " + file.errorString(), true);
        return;
    }


    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();
    qint64 fileSize = fileInfo.size();

    quint32 chunkSize = 1024 * 32; // 32KB
    quint32 totalPackets = ceil((double)fileSize / chunkSize);

    // Чтение файла по частям
    QVector<QByteArray> datagrams;
    for (quint32 i = 0; i < totalPackets; i++) {
        QByteArray chunk = file.read(chunkSize);

        MessageHeader header;
        header.messageId = messageId;
        header.totalPackets = totalPackets;
        header.packetNumber = i + 1;
        header.payloadSize = chunk.size();
        header.messageType = FileChunk;

        QByteArray datagram;
        datagram.resize(sizeof(MessageHeader) + chunk.size());
        memcpy(datagram.data(), &header, sizeof(MessageHeader));
        memcpy(datagram.data() + sizeof(MessageHeader), chunk.constData(), chunk.size());

        datagrams.append(datagram);
    }

    file.close();

    // Запускаем отправку в отдельном потоке
    MessageWorker *worker = new MessageWorker(
        datagrams,
        connectionSettings.remoteAddress,
        connectionSettings.remotePort,
        ui->transmitInterval->value()
        );

    EventNotificationWidget *eventWidget = m_fileTransfers.value(messageId).second;
    connect(worker, &MessageWorker::packetSent, this,
            [this, totalPackets, eventWidget](quint16 packetId) {
        onPacketSent(totalPackets, packetId, eventWidget);
    });

    connect(worker, &MessageWorker::finished, this, [this, messageId](quint32) {
        displayMessage("[File sent] " + m_fileTransfers.value(messageId).first, true);
    });

    connect(worker, &MessageWorker::errorOccurred, this, [this, messageId](quint32, QString error) {
        displayMessage("[File error] " + m_fileTransfers.value(messageId).first + ": " + error, true);
        m_fileTransfers.remove(messageId);
    });

    m_threadPool.start(worker);

    displayMessage("[Sending file] " + fileName, true);
}

void ChatWindow::onPacketSent(qint16 totalPackets, quint16 packetId, EventNotificationWidget *eventWidget) {
    // Можно обновлять прогресс-бар для файлов
    int progress = ((packetId + 1) * 100) / totalPackets;
    eventWidget->setProgressBarValue(progress);
    if (packetId + 1 == totalPackets)
        eventWidget->setProgressBarValue(100);
        // Обновляем прогресс в UI
}

void ChatWindow::processFileTransferRequest(const QString &sender, QByteArray &eventData){
    EventType type = EventType::FileTransferRequestRecieved;
    FileInfoHeader header;
    memcpy(&header, eventData, sizeof(FileInfoHeader));
    QString fileName = QString::fromUtf8(eventData.mid(sizeof(FileInfoHeader), header.filenameLength));
    QString fileSizeKB = QString::number(header.fileSize/1024);
    QString details = tr("Название: %1, размер:%2 KB").arg(fileName, fileSizeKB);

    QByteArray *eventDataCopy = new QByteArray(eventData);
    QString *senderCopy = new QString(sender);
    EventNotificationWidget *widget = createEventNotification(sender, type, details);
    connect(widget, &EventNotificationWidget::accepted, this,
                [this, senderCopy, eventDataCopy](){sendFileTransferPermission(*senderCopy, *eventDataCopy, true);
                delete eventDataCopy;});
    connect(widget, &EventNotificationWidget::rejected, this,
            [this, senderCopy, eventDataCopy](){sendFileTransferPermission(*senderCopy, *eventDataCopy, false);
            delete eventDataCopy;});
}

void ChatWindow::processFileTransferPermission(const QString &sender, QByteArray &eventData){
    FileInfoHeader header;
    memcpy(&header, eventData, sizeof(FileInfoHeader));
    if (!m_fileTransfers.contains(header.fileTransferMessageId))
        return;
    QString fileName = QString::fromUtf8(eventData.mid(sizeof(FileInfoHeader), header.filenameLength));
    QString fileSizeKB = QString::number(header.fileSize/1024);
    QString details = tr("Название файла: %1, размер:%2 KB").arg(fileName, fileSizeKB);
    EventType event;
    if (!header.permissionGiven){
        event = EventType::FileTransferDeclined;
    }
    else{
        event = EventType::FileTransferStarted;
    }
    EventNotificationWidget *widget = createEventNotification(sender, event, details);
    if (header.permissionGiven){
        if (m_fileTransfers.value(header.fileTransferMessageId).second != nullptr){
            QMessageBox::critical(this, "Error", "SendingFile Notification exists before sending process started");
            close();
        }
        auto& filetransfer = m_fileTransfers[header.fileTransferMessageId];
        filetransfer.second = widget;
        sendFile(header.fileTransferMessageId);
        /* //Прервать передачу файла при нажатии Reject
        connect(widget, &EventNotificationWidget::rejected, this,
                [this, &eventData](){sendFileTransferPermission(eventData, false);});
*/
    }
}

void ChatWindow::onMessageSent(quint32 messageId) {
    // Сообщение полностью отправлено, ожидаем подтверждения
    if (m_pendingMessages.contains(messageId)) {
        auto &messageData = m_pendingMessages[messageId];
        messageData.first = QDateTime::currentDateTime(); // Обновляем время
        displayMessage("[Sent] " + messageData.second, true);
    }
}

void ChatWindow::onMessageError(quint32 messageId, QString error) {
    if (m_pendingMessages.contains(messageId)) {
        QString message = m_pendingMessages.value(messageId).second;
        m_pendingMessages.remove(messageId);
        displayMessage("[Error] " + message + " (" + error + ")", true);
    }
}

void ChatWindow::checkPendingConfirmations() {
    QDateTime now = QDateTime::currentDateTime();
    QList<quint32> toRemove;

    for (auto it = m_pendingMessages.begin(); it != m_pendingMessages.end(); ++it) {
        if (it.value().first.msecsTo(now) > 5000) { // 5 секунд таймаут
            displayMessage("[Timeout] " + it.value().second, true);
            toRemove << it.key();
        }
    }

    for (auto id : toRemove) {
        m_pendingMessages.remove(id);
    }
}

void ChatWindow::displayMessage(const QString &message, bool isOutgoing)
{
    QString sender = isOutgoing ? "Вы" : "Собеседник";
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString messageData = QString("<div>"
                                  "<span style='color: #666;'>[%1] <b>%2:</b></span>"
                                  "</div>")
                              .arg(timestamp,
                                   sender);

    ui->chatDisplay->append(messageData);
    ui->chatDisplay->append(message + "\n");
    ui->chatDisplay->verticalScrollBar()->setValue(ui->chatDisplay->verticalScrollBar()->maximum());
}

QString ChatWindow::getCurrentTimestamp()
{
    return QDateTime::currentDateTime().toString("hh:mm:ss");
}

void ChatWindow::on_packetSize_valueChanged(int value)
{
    maxPacketSize = value;
    ui->packetSizeLabel->setText(QString("Max Packet Size: %1 bytes").arg(value));
}

EventNotificationWidget* ChatWindow::createEventNotification(const QString &sender,
                                       EventType type,
                                       const QString &details) {
    // Создаем виджет
    EventNotificationWidget *widget = new EventNotificationWidget(this);

    // Формируем описание
    QString description;
    switch(type) {
    case EventType::FileTransferRequestRecieved:
        description = tr("%1 хочет отправить файл\n%2").arg(sender, details);
        widget->showProgressBar(false);
        break;
    case EventType::FileTransferStarted:
        description = tr("%1 принял запрос на отправку файла. Идёт передача файла.\n%2").arg(sender, details);
        widget->showAcceptBtn(false);
        widget->showProgressBar(true);
        widget->setProgressBarValue(0);
        break;
    case EventType::FileTransferDeclined:
        description = tr("%1 отклонил запрос на отправку файла.\n%2").arg(sender, details);
        widget->showProgressBar(false);
        widget->showRejectBtn(false);
        break;
    case EventType::FileDownloading:
        description = tr("%1 передаёт вам файл.\n%2").arg(sender, details);
        widget->showProgressBar(true);
        widget->showAcceptBtn(false);
        widget->showRejectBtn(false);
        break;
    case EventType::VoiceCall:
        description = tr("%1 звонит вам").arg(sender);
        widget->showProgressBar(false);
        break;
    }

    // Настраиваем
    widget->setEventData(description, sender, type);

    // Подключаем сигналы
    // Добавляем в интерфейс
    ui->eventsContainerLayout->addWidget(widget);
    // Оповещаем пользователя
    //blinkTab(1); // Мигаем второй вкладкой
    QApplication::alert(this);
    return widget;
}

void ChatWindow::saveReceivedFile(const QString &sender, quint32 messageId, QByteArray &data) {
    QString downloadsDir = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    QString filePath = downloadsDir + "/" + ongoingDdownloads.value(messageId).first;

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(data);
        file.close();
        displayMessage(QString("Файл получен: %1").arg(filePath), false);
    } else {
        displayMessage("Ошибка сохранения файла", false);
    }
    // оповещение о завершении скачки
    EventNotificationWidget* widget = ongoingDdownloads.value(messageId).second;
    QString description = tr("Полученный файл от %1 успешно сохранён по пути:\n%2").arg(sender, filePath);
    widget->setEventData(description, sender, EventType::FileInstalled);
    widget->showProgressBar(false);
    widget->showRejectBtn(false);
    widget->showAcceptBtn(true);
    adjustSize();
    ongoingDdownloads.remove(messageId); // Сбрасываем состояние
}

void ChatWindow::handleEventAccepted(EventType type, QByteArray &eventData){

}

void ChatWindow::handleEventRejected(EventType type, QByteArray &eventData){

}
