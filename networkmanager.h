#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QUdpSocket>
#include <QThreadPool>
#include <QMap>
#include "Structs.h"
#include "messageworker.h" // MessageWorker остается, но его запуск контролирует NetworkManager

class AckManager;

class NetworkManager : public QObject
{
    Q_OBJECT

public:
    explicit NetworkManager(AckManager *ackMgr, ConnectionSettings settings, QObject *parent = nullptr);

    void setConnectionSettings(const ConnectionSettings &settings);
    ConnectionSettings getConnectionSettings();
    // Методы для отправки пакетов/дейтаграмм (вызываются другими менеджерами)
public slots:
    void sendDatagrams(quint32 messageId, const QVector<QByteArray> datagrams, bool ackRequired);

signals:
    void datagramReady(QByteArray datagram, QHostAddress sender, quint16 senderPort);
    void socketError(QUdpSocket::SocketError error, const QString &message);
    void uploadProgress(quint32 messageId, quint8 progressPercentage);
    void textMessageSent(quint32 messageId, ChatMessage::Status status);
    void errorOccurred(quint32 messageId, QString error);

private slots:
    void readPendingDatagrams();

private:
    AckManager *m_ackManager;
    QUdpSocket *m_udpSocket;
    QThreadPool m_threadPool;
    ConnectionSettings m_currentSettings;
    bool bindSocket(quint16 port);
};

#endif // NETWORKMANAGER_H
