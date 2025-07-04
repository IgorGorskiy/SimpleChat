#ifndef MESSAGEWORKER_H
#define MESSAGEWORKER_H

#include "qrunnable.h"
#include <QObject>
#include <QUdpSocket>
#include <QVector>

class MessageWorker : public QObject, public QRunnable {
    Q_OBJECT
public:
    explicit MessageWorker(const QVector<QByteArray>& datagrams,
                           const QHostAddress& address,
                           quint16 port,
                           int transmitInterval,
                           QObject *parent = nullptr);

    void run() override; // Переопределяем метод run() вместо process()

    quint32 messageId() const { return m_messageId; }

signals:
    void packetSent(qint16 packetId);
    void finished(quint32 messageId);
    void errorOccurred(quint32 messageId, QString error);

private:
    QVector<QByteArray> m_datagrams;
    QHostAddress m_address;
    quint16 m_port;
    int m_interval;
    quint32 m_messageId;
};
#endif // MESSAGEWORKER_H
