#include "ackmanager.h"

AckManager::AckManager(QObject *parent)
    : QObject{parent}
{}

void AckManager::trackOutgoingMessage(const QVector<QByteArray> &datagrams){
    MessageHeader header;
    memcpy(&header, datagrams[0].data(), sizeof(MessageHeader));
    OutgoingMessageState msg;
    msg.originalDatagrams = datagrams;
    msg.retryCount = 0;
    msg.sentTime = QDateTime::currentDateTime();
    msg.transmitInterval = header.packetInterval;
    msg.type = header.messageType;
    msg.messageId = header.messageId;
    m_pendingAcks.insert(header.messageId, msg);
}

void AckManager::processIncomingAck(quint32 messageId){
    OutgoingMessageState msg = m_pendingAcks.value(messageId);
    switch (msg.type)
    {
    case MessageType::TextMessage:
        emit textMessageDelivered(messageId);
        break;
    case MessageType::File:
        emit fileAckRecieved(messageId);
        break;
    case MessageType::Ping:
        QDateTime now = QDateTime::currentDateTime();
        emit pingMeasured(msg.sentTime.msecsTo(now));
        break;
    }
    m_pendingAcks.remove(messageId);
}

void AckManager::processIncomingReQuery(quint32 originalMessageId, QVector<quint16> missingPacketNumbers){
    if (!m_pendingAcks.contains(originalMessageId))
        return;
    OutgoingMessageState &msg = m_pendingAcks[originalMessageId];
    QVector<QByteArray> missingDatagrams;
    // при упаковке датаграмм они распологаются в порядке возрастания номера пакета
    // также учитываем, что номера пакетов начинаются с 1, а в векторе originalDatagrams первая датаграмма имеет индекс 0
    // поэтому i-1
    for(int i = 0; i < missingPacketNumbers.length(); i++)
        missingDatagrams.append(msg.originalDatagrams[missingPacketNumbers[i]-1]);
    // можем пропустить MessageComposer т.к. датаграммы уже готовы к отправке
    emit missingDatagramsReadyForSending(originalMessageId, missingDatagrams);
}

void AckManager::checkAckTimeouts(){
    QDateTime now = QDateTime::currentDateTime();
    QList<quint32> toRemove;

    for (auto it = m_pendingAcks.begin(); it != m_pendingAcks.end(); ++it) {
        if (it.value().sentTime.msecsTo(now) > 5000) { // 5 секунд таймаут
            if(it.value().type == MessageType::TextMessage)
                emit textMessageError(it.value().messageId);
            toRemove << it.key();
        }
    }

    for (auto id : toRemove) {
        m_pendingAcks.remove(id);
    }
    toRemove.clear();
}
