#include "messagemodel.h"

MessageModel::MessageModel(QObject *parent) : QAbstractListModel(parent) {}

int MessageModel::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : m_messages.size();
}

QVariant MessageModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_messages.size())
        return QVariant();

    const Message &msg = m_messages.at(index.row());

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
int MessageModel::addMessage(const Message &message) {
    beginInsertRows(QModelIndex(), m_messages.size(), m_messages.size());
    m_messages.append(message);
    endInsertRows();
    return m_messages.length() - 1;
}

void MessageModel::updateMessageStatus(quint32 id, Message::Status newStatus) {
    m_messages[id].status = newStatus;
    QModelIndex idx = index(id);
    emit dataChanged(idx, idx, {StatusRole});
}
