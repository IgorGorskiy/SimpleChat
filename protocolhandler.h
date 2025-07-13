#ifndef PROTOCOLHANDLER_H
#define PROTOCOLHANDLER_H

#include <QObject>
#include "Structs.h"

// Forward declarations

class ProtocolHandler : public QObject
{
    Q_OBJECT

public:
    explicit ProtocolHandler(QObject *parent = nullptr);

public slots:
    // Слот для приема полностью собранных сообщений от PacketReassembler
    void handleFullMessage(const MessageHeader &header, const QByteArray &payload,
                           const QHostAddress &senderAddress, quint16 senderPort);
    void handleTextProcessed(quint32 messageId);

signals:

    void reQueryReceived(quint32 originalMessageId, QVector<quint16> missingPacketNumbers);
    void ackNeeded(MessageHeader originalHeader);
    void textMessageRecieved(quint32 messageId, const QString *text, const QHostAddress &senderAddress);
    void fileDownloaded(quint32 messageId, const QByteArray &payload);
    void ackReceived(quint32 originalMessageId);
    void fileTransferRequestReceived(FileInfoHeader fileInfo, QString fileName,
                                     const QHostAddress &senderAddress, quint16 senderPort);
    void fileTransferPermissionReceived(quint32 transferId, bool permission);
private:
    // Храним указатели на большие данные для передачи этих указателей в сигналах
    // ключ - messageId
    QMap<quint32, QString*> m_unprocessedTexts;

    void sendAck(MessageHeader originalHeader);
    void processTextMessage(quint32 messageId, const QByteArray &payload, const QHostAddress &senderAddress);
    void processFileDownloaded(quint32 messageId, const QByteArray &payload);
    void processAck(const QByteArray &payload);
    void processFileTransferRequest(const QByteArray &payload, const QHostAddress &senderAddress,
                                    quint16 senderPort);
    void processFileTransferPermission(const QByteArray &payload);
    void processReQuery(const QByteArray &payload);
};

#endif // PROTOCOLHANDLER_H
