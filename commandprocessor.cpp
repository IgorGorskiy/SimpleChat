#include "commandprocessor.h"
#include "networkmanager.h"
#include "chatmanager.h"
#include "messagemodel.h"

CommandProcessor::CommandProcessor(ChatManager *chatMgr,
                                   NetworkManager *netMgr,
                                   MessageModel *msgModel,
                                   QObject *parent)
    : QObject{parent}
{

}

// нужно переделать под систему менеджеров

/*
void CommandProcessor::initializeCommands(){
    m_commandHandlers = {
        {"/help", [this](const QString&) { handleHelpCommand(); }},
        {"/clear", [this](const QString&) { processClear(); }},
        {"/setlocalport", [this](const QString& args) { processSetLocalPort(args); }},
        {"/setremoteport", [this](const QString& args) { processSetRemotePort(args); }},
        {"/setremoteaddress", [this](const QString& args) { processSetRemoteAddress(args); }},
        {"/getlocalport", [this](const QString&) { processGetLocalPort(); }},
        {"/getremoteport", [this](const QString&) { processGetRemotePort(); }},
        {"/getremoteaddress", [this](const QString&) { processGetRemoteAddress(); }},
        {"/testevent", [this](const QString&) { processTestEvent(); }},
        {"/say", [this](const QString& args) { processDisplayMessage(args); }}
    };
}

void CommandProcessor::processCommand(QString& command)
{
    command = command.trimmed();
    if (!command.startsWith('/')) {
        return; // Не команда
    }

    QStringList parts = command.split(' ', Qt::SkipEmptyParts);
    QString cmd = parts.first().toLower();
    QString args = parts.size() > 1 ? command.mid(cmd.length()).trimmed() : "";

    if (m_commandHandlers.contains(cmd)) {
        m_commandHandlers[cmd](args);
    } else {
        //m_parent->displayMessage("Неизвестная команда. Введите /help для списка команд", true, Message::CommandOutput);
    }
}

void CommandProcessor::handleSetLocalPortCommand(const QString& port)
{
    quint16 newPort = port.toUInt();
    m_networkManager->bindSocket(newPort);
    m_parent->displayMessage("local port: " + QString::number(m_parent->connectionSettings.localPort), true, Message::CommandOutput);
}
void CommandProcessor::handleSetRemotePortCommand(const QString& port)
{
    quint16 newPort = port.toUInt();
    m_parent->connectionSettings.remotePort = newPort;
    m_parent->displayMessage("remote port: " + QString::number(m_parent->connectionSettings.remotePort), true, Message::CommandOutput);
}
void CommandProcessor::processSetRemoteAddress(const QString& address)
{
    m_parent->connectionSettings.remoteAddress.setAddress(address);
    m_parent->displayMessage("remote address: " + m_parent->connectionSettings.remoteAddress.toString(), true, Message::CommandOutput);
}
void CommandProcessor::processGetLocalPort()
{
    m_parent->displayMessage("local port: " + QString::number(m_parent->connectionSettings.localPort), true, Message::CommandOutput);
}
void CommandProcessor::processGetRemotePort()
{
    m_parent->displayMessage("remote port: " + QString::number(m_parent->connectionSettings.remotePort), true, Message::CommandOutput);
}
void CommandProcessor::processGetRemoteAddress()
{
    m_parent->displayMessage("remote address: " + m_parent->connectionSettings.remoteAddress.toString(), true, Message::CommandOutput);
}
void CommandProcessor::handleHelpCommand()
{
    QString helpText =  "Доступные команды:\n"
                       "/help - эта справка\n"
                       "/clear - очистить чат\n"
                       "/setlocalport [порт] - задать локальный порт\n"
                       "/setremoteport [порт] - задать порт получателя\n"
                       "/setremoteaddress [адрес] - задать адрес получателя\n"
                       "/getlocalport [порт] - узнать текущий локальный порт\n"
                       "/getremoteport [порт] - узнать текущий порт получателя\n"
                       "/getremoteaddress [адрес] - узнать текущий адрес получателя\n"
                       "/testevent - вызвать тестовое событие"
                       "/say [текст] - отобразить сообщение";
    m_parent->displayMessage(helpText, true, Message::CommandOutput);
}
void CommandProcessor::handleClearCommand() {
    //m_parent->ui->chatDisplay->clear();
}
void CommandProcessor::processTestEvent(){
    m_parent->createEventNotification("me", EventType::FileTransferRequestRecieved, "хочешь файл?");
}

void CommandProcessor::processDisplayMessage(const QString& text){
    QString messageId = QUuid::createUuid().toString();
    m_parent->displayMessage(text, false, Message::CommandOutput);
}
*/
