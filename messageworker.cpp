#include "messageworker.h"
#include "Structs.h"
#include <QThreadPool>
#include <QMessageBox>

MessageWorker::MessageWorker(const QVector<QByteArray> datagrams,
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

MessageWorker::~MessageWorker(){
}

void MessageWorker::run() { // Заменяем на run()
    QUdpSocket udpSocket;
    // назначаем на любой свободный порт
    if (!udpSocket.bind(0, QUdpSocket::ShareAddress)) {
        qDebug() << "Could not bind socket send datagram";
        emit errorOccurred(m_messageId, udpSocket.errorString());
        return;
    }
    quint16 totalPackets = m_datagrams.size();
    // for (const auto& datagram : m_datagrams)
    for (quint16 i = 0; i < totalPackets; i++) {

        // задержка вынесена наверх в надежде, что так мессаджворкер отправит сигнал об окончании своей работы быстрее,
        // чем будет получена квитанция о доставке данного сообщения. В целом работает, но не всегда)))))
        if (m_interval > 0) {
            QThread::msleep(m_interval);
        }
        //тест потери пакетов
        /*
        if(i == 1)
            continue;
        */
        qint64 bytesSent = udpSocket.writeDatagram(m_datagrams[i], m_address, m_port);

        if (bytesSent == -1) {
            emit errorOccurred(m_messageId, udpSocket.errorString());
            return;
        }

        emit progressPercentage(i*100/totalPackets);

    }
    emit finished(m_messageId);
    udpSocket.close();
}
