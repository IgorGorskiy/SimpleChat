#include "networkmanager.h"
#include "ackmanager.h"

NetworkManager::NetworkManager(AckManager *ackMgr, ConnectionSettings settings, QObject *parent)
    : QObject{parent},
    m_ackManager(ackMgr),
    m_udpSocket(new QUdpSocket(this)),
    m_currentSettings(settings)
{
    bindSocket(m_currentSettings.localPort);
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &NetworkManager::readPendingDatagrams);
    m_threadPool.setMaxThreadCount(2);
}

bool NetworkManager::bindSocket(quint16 newPort)
{
    m_udpSocket->close();
    if (!m_udpSocket->bind(newPort, QUdpSocket::ShareAddress)) {
        emit socketError(m_udpSocket->error(), "Не удалось назначить сокет на порт");
        return false;
    }
    m_currentSettings.localPort = newPort;
    return true;
}

void NetworkManager::sendDatagrams(quint32 messageId, const QVector<QByteArray> datagrams, bool ackRequired){
    // филиал костыльного программирования
    MessageHeader header;
    memcpy(&header, datagrams[0].constData(), sizeof(header));

    if (ackRequired)
        m_ackManager->trackOutgoingMessage(datagrams);

    MessageWorker *worker = new MessageWorker(
        {datagrams},
        m_currentSettings.remoteAddress,
        m_currentSettings.remotePort,
        header.packetInterval
        );
    m_threadPool.start(worker);

    // У каждого модуля свой отведённый сигнал -
    // подключать несколько внешних модулей к одному сигналу данного модуля не рекомендуется

    // если файл - отслеживаем прогресс
    if (header.messageType == MessageType::File)
        connect(worker, &MessageWorker::progressPercentage, this, [this, messageId](quint8 progress){
                                                        emit uploadProgress(messageId, progress);});

    // если текстовое сообщение - отображаем статус "отправлено" при завершении отправки
    if (header.messageType == MessageType::TextMessage)
        connect(worker, &MessageWorker::finished, this, [this](quint32 messageId){
                                    emit textMessageSent(messageId, ChatMessage::Status::Sent);});

    connect(worker, &MessageWorker::errorOccurred, this, [this](quint32 messageId, QString error){
        emit errorOccurred(messageId, error);});
}

void NetworkManager::setConnectionSettings(const ConnectionSettings &settings){
    if(settings.localPort != m_currentSettings.localPort)
        bindSocket(settings.localPort);
    if(settings.maxThreads != m_currentSettings.maxThreads)
        m_threadPool.setMaxThreadCount(settings.maxThreads);
    qDebug() << m_threadPool.maxThreadCount();
    m_currentSettings = settings;
}

void NetworkManager::readPendingDatagrams(){
    while (m_udpSocket->hasPendingDatagrams()) {
        // память будет освобождена в processIncomingDatagram()
        QByteArray datagram(m_udpSocket->pendingDatagramSize(), ' ');
        QHostAddress sender;
        quint16 senderPort;
        m_udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        emit datagramReady(datagram, sender, senderPort); // для packetReassembler
    }
}

ConnectionSettings NetworkManager::getConnectionSettings(){
    return m_currentSettings;
}
