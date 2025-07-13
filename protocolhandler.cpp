#include "protocolhandler.h"

ProtocolHandler::ProtocolHandler(QObject *parent)
    : QObject{parent}
{}

void ProtocolHandler::handleFullMessage(const MessageHeader &header, const QByteArray &payload,
                       const QHostAddress &senderAddress, quint16 senderPort){

    switch (header.messageType) {
    case MessageType::TextMessage:
        processTextMessage(header.messageId, payload, senderAddress);
        sendAck(header);
        break;
    case MessageType::File:
        processFileDownloaded(header.messageId, payload);
        sendAck(header);
        break;
    case MessageType::Ack:
        processAck(payload);
        break;
    case MessageType::FileTransferRequest:
        processFileTransferRequest(payload, senderAddress, senderPort);
        break;
    case MessageType::FileTransferPermission:
        processFileTransferPermission(payload);
        break;
    case MessageType::Ping:
        sendAck(header);
        break;
    case MessageType::ReQuery:
        processReQuery(payload);
        break;
    }
}

void ProtocolHandler::sendAck(MessageHeader originalHeader) {
    emit ackNeeded(originalHeader);
}


void ProtocolHandler::processTextMessage(quint32 messageId, const QByteArray &payload, const QHostAddress &senderAddress){
    // приходится лишний раз копировать данные т.к. заранее не знаем длину строки
    QString text = QString::fromUtf8(payload);
    QString* textPtr = new QString[text.size()];
    *textPtr = text;
    m_unprocessedTexts.insert(messageId, textPtr);
    emit textMessageRecieved(messageId, textPtr, senderAddress);
}

void ProtocolHandler::processFileDownloaded(quint32 messageId, const QByteArray &payload){
    emit fileDownloaded(messageId, payload);
}

void ProtocolHandler::processAck(const QByteArray &payload){
    MessageHeader originalHeader;
    memcpy(&originalHeader, payload.data(), sizeof(MessageHeader));
    quint32 messageId = originalHeader.messageId;
    emit ackReceived(messageId);
}

void ProtocolHandler::processFileTransferRequest(const QByteArray &payload, const QHostAddress &senderAddress,
                                                 quint16 senderPort){
    FileInfoHeader fileInfo;
    memcpy(&fileInfo, payload.data(), sizeof(FileInfoHeader));
    QString filename = QString::fromUtf8(payload.mid(sizeof(FileInfoHeader), fileInfo.filenameLength));
    emit fileTransferRequestReceived(fileInfo, filename, senderAddress, senderPort);
}

void ProtocolHandler::processFileTransferPermission(const QByteArray &payload){
    quint32 transferId;
    bool permission;
    memcpy(&transferId,payload.data() , sizeof(transferId));
    memcpy(&permission, payload.data() + sizeof(transferId), sizeof(permission));
    emit fileTransferPermissionReceived(transferId, permission);
}

void ProtocolHandler::handleTextProcessed(quint32 messageId){
    QString* textPtr = m_unprocessedTexts.value(messageId);
    delete[] textPtr;
    m_unprocessedTexts.remove(messageId);
}

void ProtocolHandler::processReQuery(const QByteArray &payload){
    // начало данных - originalMessageId, далее - вектор номеров пакетов
    quint32 originalMessageId;
    int vectorSizeInBytes = payload.size()-sizeof(originalMessageId);
    int vectorSize = vectorSizeInBytes/sizeof(quint16);
    QVector<quint16> missingPacketNumbers(vectorSize, 1);
    memcpy(&originalMessageId, payload.constData(), sizeof(originalMessageId));
    memcpy(missingPacketNumbers.data(), payload.constData() + sizeof(originalMessageId), vectorSizeInBytes);
    emit reQueryReceived(originalMessageId, missingPacketNumbers);
}
