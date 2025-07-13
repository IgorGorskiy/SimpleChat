#include "messagecomposer.h"

MessageComposer::MessageComposer(QObject *parent)
    : QObject{parent}
{
}

void MessageComposer::createTextDatagrams(const QString text){
    QVector<QByteArray> datagrams;
    quint32 messageId = m_currentMessageId++;
    // Подготовка пакетов
    quint32 remainingBytes = text.toUtf8().size();
    quint32 offset = 0;
    quint16 packetNumber = 0;
    quint16 totalPackets = ceil((double)remainingBytes / (m_currentSettings.maxPacketSize - sizeof(MessageHeader)));

    while (remainingBytes > 0) {
        packetNumber++;
        quint32 chunkSize = qMin(remainingBytes, (quint32)(m_currentSettings.maxPacketSize - sizeof(MessageHeader)));
        QByteArray payload = text.toUtf8().mid(offset, chunkSize);

        MessageHeader header;
        header.messageId = messageId;
        header.totalPackets = totalPackets;
        header.packetNumber = packetNumber;
        header.payloadSize = chunkSize;
        header.messageType = TextMessage;
        header.packetInterval = m_currentSettings.packetInterval;

        QByteArray datagram(sizeof(MessageHeader) + chunkSize, ' ');
        memcpy(datagram.data(), &header, sizeof(MessageHeader));
        memcpy(datagram.data() + sizeof(MessageHeader), payload.constData(), chunkSize);

        datagrams.append(datagram);
        offset += chunkSize;
        remainingBytes -= chunkSize;
    }
    emit datagramsReadyForSending(messageId, datagrams, true);
    emit textMessageComposed(messageId, text);
}

void MessageComposer::createFileTransferRequestDatagrams(const QString filePath){

    quint32 messageId = m_currentMessageId++;

    QFileInfo fileInfo(filePath);
    FileInfoHeader fileInfoHeader;
    fileInfoHeader.fileSize = fileInfo.size();
    fileInfoHeader.filenameLength = fileInfo.fileName().length();
    fileInfoHeader.fileTransferMessageId = messageId;

    QByteArray fullMessage(sizeof(fileInfoHeader) + fileInfoHeader.filenameLength, '\0');
    memcpy(fullMessage.data(), &fileInfoHeader, sizeof(FileInfoHeader));
    memcpy(fullMessage.data() + sizeof(FileInfoHeader), fileInfo.fileName().toUtf8().constData(),
                                                        fileInfoHeader.filenameLength);

    quint32 remainingBytes = sizeof(fileInfoHeader) + fileInfoHeader.filenameLength;
    quint32 offset = 0;
    quint16 packetNumber = 0;
    quint16 totalPackets = ceil((double)remainingBytes / (m_currentSettings.maxPacketSize - sizeof(MessageHeader)));

    QVector<QByteArray> datagrams;
    while (remainingBytes > 0) {
        packetNumber++;
        quint32 chunkSize = qMin(remainingBytes, (quint32)(m_currentSettings.maxPacketSize - sizeof(MessageHeader)));
        QByteArray payload = fullMessage.mid(offset, chunkSize);

        MessageHeader header;
        header.messageId = messageId;
        header.totalPackets = totalPackets;
        header.packetNumber = packetNumber;
        header.payloadSize = chunkSize;
        header.messageType = MessageType::FileTransferRequest;
        header.packetInterval = m_currentSettings.packetInterval;

        QByteArray datagram(sizeof(MessageHeader) + chunkSize, ' ');
        memcpy(datagram.data(), &header, sizeof(MessageHeader));
        memcpy(datagram.data() + sizeof(MessageHeader), payload.constData(), chunkSize);

        datagrams.append(datagram);
        offset += chunkSize;
        remainingBytes -= chunkSize;
    }
    emit datagramsReadyForSending(messageId, datagrams, false);
    emit transferRequestReady(messageId, filePath);
}

void MessageComposer::createFileTransferPermissionDatagrams(quint32 transferId,
                                                               bool permission){
    QVector<QByteArray> datagrams;

    MessageHeader header;
    header.messageId = m_currentMessageId++;
    header.packetNumber = 1;
    header.totalPackets = 1;
    header.messageType = MessageType::FileTransferPermission;
    header.payloadSize = sizeof(transferId) + sizeof(permission);

    QByteArray datagram(sizeof(header) + header.payloadSize, ' ');
    memcpy(datagram.data(), &header, sizeof(MessageHeader));
    memcpy(datagram.data() + sizeof(MessageHeader), &transferId, sizeof(transferId));
    memcpy(datagram.data() + sizeof(MessageHeader) + sizeof(transferId), &permission, sizeof(permission));
    datagrams.append(datagram);
    emit datagramsReadyForSending(header.messageId, datagrams, false);
}

void MessageComposer::createFileDatagrams(quint32 transferId, QFile &file){
    QVector<QByteArray> datagrams;

    QFileInfo fileInfo(file);
    qint64 fileSize = fileInfo.size();
    quint32 remainingBytes = fileSize;
    quint16 totalPackets = ceil((double)remainingBytes / (m_currentSettings.maxPacketSize - sizeof(MessageHeader)));
    // запрос разрешения на передачу и сама передача имеют одинаковый messageId
    quint32 messageId = transferId;
    quint32 chunkSize = qMin(remainingBytes, (quint32)(m_currentSettings.maxPacketSize - sizeof(MessageHeader)));

    for (quint32 i = 0; i < totalPackets; i++) {
        QByteArray chunk = file.read(chunkSize);
        MessageHeader header;
        header.messageId = messageId;
        header.totalPackets = totalPackets;
        header.packetNumber = i + 1;
        header.payloadSize = chunk.size();
        header.messageType = MessageType::File;
        header.packetInterval = m_currentSettings.packetInterval;

        QByteArray datagram(sizeof(MessageHeader) + chunk.size(), ' ');
        memcpy(datagram.data(), &header, sizeof(MessageHeader));
        memcpy(datagram.data() + sizeof(MessageHeader), chunk.constData(), chunk.size());

        datagrams.append(datagram);
        remainingBytes -= chunkSize;
        chunkSize = qMin(remainingBytes, (quint32)(m_currentSettings.maxPacketSize - sizeof(MessageHeader)));
    }
    emit datagramsReadyForSending(messageId, datagrams, true);
}
void MessageComposer::createAckDatagrams(MessageHeader originalHeader){
    QVector<QByteArray> datagrams;

    MessageHeader header;
    header.messageId = m_currentMessageId++;
    header.packetNumber = 1;
    header.totalPackets = 1;
    header.messageType = MessageType::Ack;
    header.payloadSize = sizeof(originalHeader);

    QByteArray datagram(sizeof(header) + sizeof(originalHeader), ' ');
    memcpy(datagram.data(), &header, sizeof(MessageHeader));
    memcpy(datagram.data() + sizeof(MessageHeader), &originalHeader, sizeof(originalHeader));
    datagrams.append(datagram);
    emit datagramsReadyForSending(header.messageId, datagrams, false);
}
void MessageComposer::createPingDatagrams(){
    QVector<QByteArray> datagrams;

    MessageHeader header;
    header.messageId = m_currentMessageId++;
    header.packetNumber = 1;
    header.totalPackets = 1;
    header.messageType = MessageType::Ping;
    header.payloadSize = 0;

    QByteArray datagram(sizeof(header), ' ');
    memcpy(datagram.data(), &header, sizeof(header));
    datagrams.append(datagram);
    emit datagramsReadyForSending(header.messageId, datagrams, true);
}

void MessageComposer::createReQueryDatagrams(quint32 originalMessageId,
                                            const QVector<quint16> missingPacketNumbers){
    QVector<QByteArray> datagrams;
    int vectorSizeInBytes = missingPacketNumbers.size()*sizeof(quint16); // количество элементов * размер элементов
    QByteArray fullMessage(sizeof(originalMessageId) + vectorSizeInBytes, ' ');
    memcpy(fullMessage.data(), &originalMessageId, sizeof(originalMessageId));
    memcpy(fullMessage.data() + sizeof(originalMessageId), missingPacketNumbers.data(), vectorSizeInBytes);

    quint32 messageId = m_currentMessageId++;
    quint32 remainingBytes = fullMessage.size();
    quint32 offset = 0;
    quint16 packetNumber = 0;
    quint16 totalPackets = ceil((double)remainingBytes /
                                (m_currentSettings.maxPacketSize - sizeof(MessageHeader)));

    while (remainingBytes > 0) {
        packetNumber++;
        quint32 chunkSize = qMin(remainingBytes,
                            (quint32)(m_currentSettings.maxPacketSize - sizeof(MessageHeader)));
        QByteArray payload = fullMessage.mid(offset, chunkSize);

        MessageHeader header;
        header.messageId = messageId;
        header.totalPackets = totalPackets;
        header.packetNumber = packetNumber;
        header.payloadSize = chunkSize;
        header.messageType = MessageType::ReQuery;
        header.packetInterval = m_currentSettings.packetInterval;

        QByteArray datagram(sizeof(MessageHeader) + chunkSize, ' ');
        memcpy(datagram.data(), &header, sizeof(MessageHeader));
        memcpy(datagram.data() + sizeof(MessageHeader), payload.constData(), chunkSize);

        datagrams.append(datagram);
        offset += chunkSize;
        remainingBytes -= chunkSize;
    }
    emit datagramsReadyForSending(messageId, datagrams, false);
}


void MessageComposer::setComposerSettings(ComposerSettings settings){
    m_currentSettings = settings;
}

ComposerSettings MessageComposer::getComposerSettings(){
    return m_currentSettings;
}
