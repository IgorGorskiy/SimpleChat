#ifndef PACKETREASSEMBLER_H
#define PACKETREASSEMBLER_H

#include <QObject>
#include <QMap>
#include <QTimer>
#include "Structs.h"

class PacketReassembler : public QObject
{
    Q_OBJECT

public:
    explicit PacketReassembler(QObject *parent = nullptr);

public slots:
    // Слот для приема сырых дейтаграмм от NetworkManager
    void processIncomingDatagram(const QByteArray datagram, const QHostAddress &senderAddress, quint16 senderPort);

signals:
    // Исходящие сигналы для ProtocolHandler, AckManager
    void fullMessageReady(const MessageHeader &header, const QByteArray payload,
                          const QHostAddress &senderAddress, quint16 senderPort);
    void reQueryNeeded(quint32 originalMessageId, const QVector<quint16> &missingPacketNumbers); // для messageComposer
    void downloadProgress(quint32 messageId, quint8 progressPercentage);

private slots:

private:
    QMap<quint32, IncompleteMessage> m_incompleteMessages; // messageId -> IncompleteMessage
    QTimer *m_timeoutTimer; // Для очистки неполных сообщений по таймауту

    void processIncompleteMessage(quint32 messageId);
    void initIncompleteMsg(const MessageHeader header, const QHostAddress &senderAddress,
                           quint16 senderPort);
};

#endif // PACKETREASSEMBLER_H
