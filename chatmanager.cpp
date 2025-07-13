#include "chatmanager.h"
#include "networkmanager.h"

ChatManager::ChatManager(NetworkManager *netMgr, AckManager *ackMgr, QObject *parent)
    : QObject{parent},
    m_networkManager(netMgr),
    m_ackManager(ackMgr)
{
}

void ChatManager::constructTextMessage(quint32 messageId, const QString &text){
    ChatMessage message;
    message.id = messageId; // нужно для изменения статуса в дальнейшем
    message.isOutgoing = true;
    message.sender = "Вы";
    message.status = ChatMessage::Status::Sending;
    message.text = text;
    message.timestamp = QDateTime::currentDateTime();
    emit newMessageForDisplay(message);
}

void ChatManager::processIncomingTextMessage(quint32 messageId, const QString *text, const QHostAddress &senderAddress){
    ChatMessage message;
    message.id = 0; // не требуется для входящих т.к. входящие сообщения никак не изменяются со временем
    message.isOutgoing = false;
    message.sender = senderAddress.toString();
    message.status = ChatMessage::Status::None;
    message.text = *text;
    message.timestamp = QDateTime::currentDateTime();
    emit newMessageForDisplay(message);
    emit incomingMessageProcessed(messageId); // для protocolHandler
}
