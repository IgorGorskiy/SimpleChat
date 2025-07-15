#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QListView>
#include <QUuid>
#include "Structs.h"
#include "eventnotificationwidget.h"
#include "messagedelegate.h"

#include "databasemanager.h"
#include "ackmanager.h"
#include "chatmanager.h"
#include "commandprocessor.h"
#include "filetransfermanager.h"
#include "messagecomposer.h"
#include "networkmanager.h"
#include "notificationmanager.h"
#include "packetreassembler.h"
#include "protocolhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow;}
QT_END_NAMESPACE

// Custom protocol header structure

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChatWindow(ConnectionSettings con,
               QWidget *parent);
    ~ChatWindow();
private slots:
    void resizeEvent(QResizeEvent *event);
    void on_sendButton_clicked();
    void on_packetSize_valueChanged(int value);
    void onTransmitIntervalValueChanged(int value);
    void onMaxThreadsvalueChanged(int value);
    void onRemoteAddressValueChanged(const QString& value);
    void onRemotePortValueChanged(const QString& value);
    void onMyPortValueChanged(const QString& value);
    void onSendFileButtonClicked();
    void onConnectToBD();
private:
    MessageModel *m_messageModel;
    QMap<quint32, quint32> displayingMessages; // ключ - id отправки, значение: id отображения
    ConnectionSettings connectionSettings;
    ComposerSettings composerSettings;
    bool dbConnected = false;
    QString dbName;

    DatabaseManager *m_dbManager;
    AckManager *m_ackManager;
    ChatManager *m_chatManager;
    CommandProcessor *m_commandProcessor;
    FileTransferManager *m_fileTransferManager;
    MessageComposer *m_messageComposer;
    NetworkManager *m_networkManager;
    NotificationManager *m_notificationManager;
    PacketReassembler *m_packetReassembler;
    ProtocolHandler *m_protocolHandler;

    Ui::ChatWindow *ui;
    QTimer *updateTimer;

    int maxPacketSize = 512; // Default max packet size

    void initManagerConnections();
    QString getCurrentTimestamp();
};

#endif // CHATWINDOW_H
