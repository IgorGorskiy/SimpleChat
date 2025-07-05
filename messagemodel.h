#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include "qdatetime.h"
#include <QAbstractListModel>
#include <QVector>

struct Message {
    QString id;
    QString text;
    QString sender;
    QDateTime timestamp;
    bool isOutgoing;
    enum Status { Sending, Sent, Delivered, Error, CommandOutput, None } status;
};

class MessageModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        TextRole,
        SenderRole,
        TimestampRole,
        IsOutgoingRole,
        StatusRole
    };

    explicit MessageModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int addMessage(const Message &message);
    void updateMessageStatus(quint32 id, Message::Status newStatus);

private:
    QVector<Message> m_messages;
};
#endif // MESSAGEMODEL_H
