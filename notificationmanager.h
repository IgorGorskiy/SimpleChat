#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QObject>
#include <QVBoxLayout>
#include <QMap>
#include "Structs.h"
#include "eventnotificationwidget.h"

class NotificationManager : public QObject
{
    Q_OBJECT

public:
    explicit NotificationManager(QVBoxLayout *layout, QObject *parent = nullptr);
    NotificationInfo getInfo(quint32 notificationId);

public slots:
    // Метод для запроса отображения нового уведомления
    quint32 displayNotification(const NotificationInfo &info);
    // Методы для обновления существующих уведомлений (например, прогресс-бара)
    void changeNotification(quint32 notificationId, const NotificationInfo &info);
    void updateNotificationProgress(quint32 notificationId, const quint8 &progress);
    void removeNotification(quint32 notificationId); // Для программного удаления

signals:

    void fileTransferAccepted(quint32 transferId, bool accepted = true); // для filetransfermanager и messagecomposer
    void fileTransferRejected(quint32 transferId, bool accepted = false);
    void voiceCallAccepted(quint32 callId, const QHostAddress &senderAddress, quint16 senderPort);
    void voiceCallRejected(quint32 callId, const QHostAddress &senderAddress, quint16 senderPort);
    void abortReceivingFile(quint32 transferId);
    void abortUploadingFile(quint32 transferId);

    // Сигналы для ChatWindow (чтобы он сам обновил UI)
    void notificationAdded(quint32 notificationId, EventNotificationWidget* widget); // Если ChatWindow нужно знать о добавленных
    void notificationUpdated(quint32 notificationId, int value);
    void notificationRemoved(quint32 notificationId);

private slots:
    // Слоты для обработки действий пользователя в EventNotificationWidget
    void handleWidgetAccepted(quint32 notificationId); // Изменены сигнатуры, т.к. EventNotificationWidget не должен знать о EventType/ID
    void handleWidgetRejected(quint32 notificationId);
    void handleWidgetCanceled(quint32 notificationId);
    void handleWidgetAborted(quint32 notificationId);

private:
    QVBoxLayout *m_layout;
    QMap<quint32, EventNotificationWidget*> m_activeNotifications; // notificationId -> widget
    QMap<EventNotificationWidget*, NotificationInfo> m_widgetToInfoMap; // для обратного маппинга

    quint32 m_nextNotificationId = 1; // Генератор уникальных ID для уведомлений

    // Вспомогательный метод для получения NotificationInfo из виджета
    NotificationInfo getInfoFromWidget(EventNotificationWidget *widget);
};

#endif // NOTIFICATIONMANAGER_H
