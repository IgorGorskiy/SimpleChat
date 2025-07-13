#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include "qdatetime.h"
#include <QAbstractListModel>
#include <QVector>
#include "Structs.h"
#include "qlistview.h"

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

    explicit MessageModel(QListView *listView, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int addMessage(const ChatMessage &message);
public slots:
    void updateMessageStatus(quint32 sentMsgId, ChatMessage::Status newStatus);

signals:
    void messageReadyForDB(ChatMessage message);

private:
    QListView *m_listView;
    QVector<ChatMessage> m_messages;
    QMap<quint32, quint32> outgoingMessages; // ключ - id отправки, значение: id отображения
};
#endif // MESSAGEMODEL_H
