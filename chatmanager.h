#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include <QObject>
#include <QHostAddress>
#include "Structs.h"

// Forward declarations
class NetworkManager; // Нужен для получения настроек соединения
class AckManager;
class MessageModel;

class ChatManager : public QObject
{
    Q_OBJECT

public:
    explicit ChatManager(NetworkManager *netMgr, AckManager *ackMgr, QObject *parent = nullptr);

public slots:
    void constructTextMessage(quint32 messageId, const QString &text); // вызывается после сборки датаграмм композером

    // Слоты для обработки входящих сообщений от ProtocolHandler
    void processIncomingTextMessage(quint32 messageId, const QString *text, const QHostAddress &senderAddress);

signals:
    // Сигналы для ChatWindow / MessageModel
    void incomingMessageProcessed(quint32 messageId); // для protocolHandler
    void newMessageForDisplay(const ChatMessage &message);
    void messageStatusUpdate(quint32 messageId, ChatMessage::Status status);

private:
    NetworkManager *m_networkManager;
    AckManager *m_ackManager;
    MessageModel *m_messageModel;
};

#endif // CHATMANAGER_H
