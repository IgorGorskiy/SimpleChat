#ifndef ACKMANAGER_H
#define ACKMANAGER_H

#include <QObject>
#include <QMap>
#include <QTimer>
#include <QQueue>
#include "Structs.h"

class AckManager : public QObject
{
    Q_OBJECT

public:
    explicit AckManager(QObject *parent = nullptr);

public slots:
    void trackOutgoingMessage(const QVector<QByteArray> &datagrams); // Вызывается NetworkManager
    void processIncomingAck(quint32 messageId);
    void processIncomingReQuery(quint32 originalMessageId, QVector<quint16> missingPacketNumbers);

signals:
    void textMessageDelivered(quint32 messageId, ChatMessage::Status  status = ChatMessage::Delivered); // Для MessageModel
    void textMessageError(quint32 messageId, ChatMessage::Status  status = ChatMessage::Error); // Для MessageModel
    void requestResendDatagrams(quint32 messageId, const QVector<QByteArray> &datagrams,
                                const QHostAddress &address, quint16 port, int transmitInterval); // Для NetworkManager
    void fileAckRecieved(quint32 messageId);
    void pingMeasured(int ping);

    // аналогичен сигналу из messageComposer, но здесь ack не нужен т.к. сообщение уже отслеживается
    void missingDatagramsReadyForSending(quint32 messageId, const QVector<QByteArray> datagrams, bool ackRequired = false);

private slots:
    void checkAckTimeouts(); // Проверка таймаутов ACK

private:

    struct OutgoingMessageState {
        quint32 messageId;
        MessageType type;
        QDateTime sentTime;
        int retryCount;
        QVector<QByteArray> originalDatagrams; // Сохраняем для повторной отправки
        int transmitInterval;
    };

    QMap<quint32, OutgoingMessageState> m_pendingAcks; // Сообщения, ожидающие ACK

    QTimer *m_ackTimeoutTimer; // Таймер для проверки таймаутов

    void resendMessage(quint32 messageId);
};

#endif // ACKMANAGER_H
