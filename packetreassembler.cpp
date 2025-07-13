#include "packetreassembler.h"

PacketReassembler::PacketReassembler(QObject *parent)
    : QObject{parent}
{}

void PacketReassembler::processIncomingDatagram(const QByteArray datagram,
                                                const QHostAddress &senderAddress, quint16 senderPort){
    if (datagram.size() < sizeof(MessageHeader)) {
        qDebug() << "Received datagram too small to contain header";
        return;
    }

    MessageHeader header;
    memcpy(&header, datagram.constData(), sizeof(MessageHeader));

    // Проверка правильности номера пакета
    if (header.packetNumber == 0 || header.packetNumber > header.totalPackets) {
        qDebug() << "Invalid packet number:" << header.packetNumber;
        return;
    }

    // Проверка payload size
    quint32 expectedSize = sizeof(MessageHeader) + header.payloadSize;
    if (datagram.size() != expectedSize) {
        qDebug() << "Payload size mismatch. Expected:" << expectedSize << "Actual:" << datagram.size();
        return;
    }

    if (!m_incompleteMessages.contains(header.messageId))
        initIncompleteMsg(header, senderAddress, senderPort);

    IncompleteMessage &msg = m_incompleteMessages[header.messageId];
    msg.assemblyTimer->start(); // сброс таймера

    QByteArray payload;
    payload.resize(header.payloadSize);
    payload = datagram.mid(sizeof(MessageHeader));

    if (!msg.packets.contains(header.packetNumber)) {
        msg.packets[header.packetNumber] = payload;
        msg.receivedPacketsCount++;
    }

    QByteArray fullMessage;
    // Проверяем, собрано ли все сообщение
    if (msg.receivedPacketsCount == msg.totalPackets){
        msg.assemblyTimer->stop();
        // Собираем полное сообщение
        for (int i = 1; i <= msg.totalPackets; ++i) {
            fullMessage += msg.packets[i];
        }
        // Удаляем из очереди
        m_incompleteMessages.remove(header.messageId);
        emit fullMessageReady(header, fullMessage, senderAddress, senderPort);
    }
    else{
        // отслеживание прогресса скачки файла. Последний пакет не идёт в учёт прогресса, что,
        // в прочем, не является проблемой т.к. при получении всех пакетов filetransfermanager обновит уведомление.
        if (header.messageType == MessageType::File)
            emit downloadProgress(header.messageId, msg.receivedPacketsCount*100/msg.totalPackets);
    }
}

void PacketReassembler::initIncompleteMsg(const MessageHeader header, const QHostAddress &senderAddress,
                                          quint16 senderPort){
    IncompleteMessage newMsg;
    quint32 messageId = header.messageId;
    newMsg.messageId = messageId;
    newMsg.totalPackets = header.totalPackets;
    newMsg.packetInterval = header.packetInterval;
    newMsg.senderAddress = senderAddress;
    newMsg.senderPort = senderPort;

    QTimer *timer = new QTimer(this);
    newMsg.assemblyTimer = timer;
    // 300 msecond tolerance на учёт пинга и других задержек
    newMsg.assemblyTimer->setInterval(newMsg.packetInterval + 300);
    newMsg.assemblyTimer->setSingleShot(true);
    connect(timer, &QTimer::timeout, [this, messageId](){
        processIncompleteMessage(messageId);});

    m_incompleteMessages.insert(header.messageId, newMsg);
}

void PacketReassembler::processIncompleteMessage(quint32 messageId)
{
    IncompleteMessage &msg = m_incompleteMessages[messageId];
    QVector <quint16> missingPacketsIds;
    for (int i = 1; i <= msg.totalPackets; i++){
        if (!msg.packets.contains(i))
            missingPacketsIds.append(i);
    }

    emit reQueryNeeded(messageId, missingPacketsIds); // Для MessageComposer
}
