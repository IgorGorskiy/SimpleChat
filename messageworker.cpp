#include "messageworker.h"
#include "Structs.h"
#include <QThreadPool>
#include <QMessageBox>

MessageWorker::MessageWorker(const QVector<QByteArray>& datagrams,
                             const QHostAddress& address,
                             quint16 port,
                             int transmitInterval,
                             QObject *parent)
    : QObject(parent),
    m_datagrams(datagrams),
    m_address(address),
    m_port(port),
    m_interval(transmitInterval)
{
    // Извлекаем ID сообщения из первого пакета
    if (!datagrams.isEmpty()) {
        MessageHeader header;
        memcpy(&header, datagrams.first().constData(), sizeof(MessageHeader));
        m_messageId = header.messageId;
    }

    // Устанавливаем автоудаление после выполнения
    setAutoDelete(true);
}

void MessageWorker::run() { // Заменяем на run()
    QUdpSocket udpSocket;
    // ищем свободный порт
    for (quint16 port = 12349; port < 65000; port++){
        if (!udpSocket.bind(port, QUdpSocket::ShareAddress)) {
            qDebug() << "Could not bind to port to send datagram. Port: " + QString::number(port);
        }
        else {break;}
    }
    quint16 totalPackets = m_datagrams.size();
    // for (const auto& datagram : m_datagrams)
    for (quint16 i = 0; i < totalPackets; i++) {
        qint64 bytesSent = udpSocket.writeDatagram(m_datagrams[i], m_address, m_port);

        if (bytesSent == -1) {
            emit errorOccurred(m_messageId, udpSocket.errorString());
            return;
        }

        emit packetSent(i);

        if (m_interval > 0) {
            QThread::msleep(m_interval);
        }
    }

    emit finished(m_messageId);
    udpSocket.close();
}
