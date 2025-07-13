#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <QObject>
#include <functional> // Для std::function
#include <QMap>
#include "Structs.h"

// Forward declarations
class ChatManager;
class NetworkManager;
class MessageModel; // Для команд, которые взаимодействуют с моделью сообщений

class CommandProcessor : public QObject
{
    Q_OBJECT

public:
    explicit CommandProcessor(ChatManager *chatMgr,
                              NetworkManager *netMgr,
                              MessageModel *msgModel,
                              QObject *parent = nullptr);

    void processCommand(QString &commandText);

signals:
    void commandOutput(const QString &text, bool isError = false); // Для вывода результата в UI
    void connectionSettingsChanged(const ConnectionSettings &settings); // Для обновления настроек в NetworkManager

private:
    ChatManager *m_chatManager;
    NetworkManager *m_networkManager;
    MessageModel *m_messageModel;

    QMap<QString, std::function<void(const QString&)>> m_commandHandlers;

    void initializeCommands();

    // Методы-обработчики для конкретных команд
    void handleHelpCommand();
    void handleClearCommand();
    void handleSetLocalPortCommand(const QString &args);
    void handleSetRemotePortCommand(const QString &args);
    void handleSetRemoteAddressCommand(const QString &args);
    void handleTestEventCommand(const QString &args); // Удалить, если используется только для отладки
};

#endif // COMMANDPROCESSOR_H
