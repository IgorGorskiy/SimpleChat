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
#include "qthreadpool.h"
#include "messageworker.h"
#include "eventnotificationwidget.h"
#include "messagedelegate.h"
QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow;}
QT_END_NAMESPACE

// Custom protocol header structure

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChatWindow(ConnectionSettings con, QWidget *parent);
    ~ChatWindow();
private slots:
    void resizeEvent(QResizeEvent *event);
    void on_sendButton_clicked();
    void readPendingDatagrams();
    void on_packetSize_valueChanged(int value);
    void onRemoteAddressValueChanged(const QString& value);
    void onRemotePortValueChanged(const QString& value);
    void onMyPortValueChanged(const QString& value);
    void sendPing(QTime creationTime = QTime::currentTime(), bool isResponce = false);
    void processIncompleteMessage(quint32 messageId);
    void handleEventAccepted(EventType type, QByteArray &eventData);
    void handleEventRejected(EventType type, QByteArray &eventData);
    void checkPendingConfirmations();
    void onMessageError(quint32 messageId, QString error);
    void onMessageSent(quint32 messageId);
    void onPacketSent(qint16 totalPackets, quint16 packetId, EventNotificationWidget *eventWidget);
    void onSendFileButtonClicked();
private:
    MessageModel *m_messageModel;
    QThreadPool m_threadPool;
    QMap<quint32, QPair<QDateTime, QString>> m_pendingMessages;
    QMap<quint32, QPair<QString, EventNotificationWidget*>> m_fileTransfers; // Для отслеживания передачи файлов
    QMap<quint32, QPair<QString, EventNotificationWidget*>> ongoingDdownloads;
    QMap<quint32, quint32> displayingMessages; // ключ - id отправки, значение: id отображения
    ConnectionSettings connectionSettings;
    Ui::ChatWindow *ui;
    QUdpSocket *udpSocket;
    QTimer *updateTimer;

    int maxPacketSize = 512; // Default max packet size

    // Message assembly buffers
    QMap<quint32, IncompleteMessage> incompleteMessages;
    QMap<quint32, QTimer*> messageTimers;

    // Message counters
    quint32 nextMessageId = 1;
    quint32 nextReceivedMessageId = 0;

    QString formatMessage(const QString &message, bool isOutgoing);

    void bindSocket(const quint16 &port);
    void sendMessage(const QString &message);
    void displayMessage(const QString &text, bool isOutgoing, Message::Status status, quint32 transferId = NULL);
    void onMessageStatusChanged(quint32 displayId, Message::Status newStatus);
    void sendFile(quint32 messageId);
    void processDatagram(const QByteArray &datagram, const QHostAddress &sender, quint16 senderPort);
    QString getCurrentTimestamp();
    bool checkMessageCompletion(quint32 messageId, quint8 messageType);
    void sendAck(MessageHeader originalHeader, const QHostAddress &address, quint16 port);
    void processAck(const QString& sender, AckPacket ackPacket);
    void askToSendFile(const QString &filePath);
    void processFileTransferRequest(const QString &sender, QByteArray &eventData);
    void sendFileTransferPermission(const QString &sender, QByteArray &eventData, bool permission);
    void processFileTransferPermission(const QString &sender, QByteArray &eventData);
    void saveReceivedFile(const QString &sender, quint32 messageid, QByteArray &data);
    EventNotificationWidget* createEventNotification(const QString &sender,
                                           EventType type,
                                           const QString &details);

    class Commands
    {
    public:
        explicit Commands(ChatWindow* parent);
        void initializeCommands();
        void processCommand(QString& command);
    private:
        QMap<QString, std::function<void(const QString&)>> commandHandlers;
        void processClear();
        void processHelp();
        void processSetLocalPort(const QString& port);
        void processSetRemotePort(const QString& port);
        void processSetRemoteAddress(const QString& address);
        void processGetLocalPort();
        void processGetRemotePort();
        void processGetRemoteAddress();
        void processTestEvent();
        void processDisplayMessage(const QString& text);
        ChatWindow* m_parent;
    };

    Commands m_commands;
};

#endif // CHATWINDOW_H
