#include "messagemodel.h"

MessageModel::MessageModel(QListView *listView, QObject *parent)
    : QAbstractListModel(parent),
    m_listView(listView)
{}

int MessageModel::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : m_messages.size();
}

QVariant MessageModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_messages.size())
        return QVariant();

    const ChatMessage &msg = m_messages.at(index.row());

    switch (role) {
    case IdRole: return msg.id;
    case TextRole: return msg.text;
    case SenderRole: return msg.sender;
    case TimestampRole: return msg.timestamp;
    case IsOutgoingRole: return msg.isOutgoing;
    case StatusRole: return msg.status;
    default: return QVariant();
    }
}

QHash<int, QByteArray> MessageModel::roleNames() const {
    return {
        {IdRole, "messageId"},
        {TextRole, "messageText"},
        {SenderRole, "senderName"},
        {TimestampRole, "timeStamp"},
        {IsOutgoingRole, "isOutgoing"},
        {StatusRole, "messageStatus"}
    };
}

// возвращает id отображённого сообщения
int MessageModel::addMessage(const ChatMessage &message) {
    beginInsertRows(QModelIndex(), m_messages.size(), m_messages.size());
    m_messages.append(message);
    endInsertRows();

    // Прокручиваем к новому сообщению
    QTimer::singleShot(100, [this]() {
        m_listView->scrollToBottom();
    });

    int displayId = m_messages.length() - 1;
    if(message.isOutgoing)
        outgoingMessages.insert(message.id, displayId);
    else
        emit messageReadyForDB(message);
    return displayId;
}

void MessageModel::updateMessageStatus(quint32 sentMsgId, ChatMessage::Status newStatus) {
    int displayId = outgoingMessages.value(sentMsgId);
    // это на случай, если статус "отправлено" придёт позже статуса "доставлено"
    if(m_messages[displayId].status == ChatMessage::Status::Delivered)
        return;

    m_messages[displayId].status = newStatus;
    if(newStatus == ChatMessage::Status::Delivered)
        emit messageReadyForDB(m_messages[displayId]);
    QModelIndex idx = index(displayId);
    emit dataChanged(idx, idx, {StatusRole});
}
