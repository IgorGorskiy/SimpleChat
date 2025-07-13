#include "notificationmanager.h"

NotificationManager::NotificationManager(QVBoxLayout *layout, QObject *parent)
    : QObject{parent},
    m_layout(layout)
{}

quint32 NotificationManager::displayNotification(const NotificationInfo &info){
    EventNotificationWidget *widget = new EventNotificationWidget();
    quint32 notificationId = m_nextNotificationId++;
    widget->setProgressBarValue(0);
    widget->showProgressBar(info.showProgressBar);
    widget->showAcceptBtn(info.showAcceptButton);
    widget->showRejectBtn(info.showRejectButton);
    widget->showCancelBtn(info.showCancelButton);
    widget->showAbortBtn(info.showAbortButton);
    widget->setEventData(info.description, info.senderName, info.eventType);

    connect(widget, &EventNotificationWidget::accepted, this,
            [this, notificationId](){handleWidgetAccepted(notificationId);});
    connect(widget, &EventNotificationWidget::rejected, this,
            [this, notificationId](){handleWidgetRejected(notificationId);});
    connect(widget, &EventNotificationWidget::aborted, this,
            [this, notificationId](){handleWidgetAborted(notificationId);});
    connect(widget, &EventNotificationWidget::canceled, this,
            [this, notificationId](){handleWidgetCanceled(notificationId);});

    // Добавляем в интерфейс
    //emit notificationAdded(notificationId, widget);
    m_layout->addWidget(widget);
    m_activeNotifications.insert(notificationId, widget);
    m_widgetToInfoMap.insert(widget, info);
    return notificationId;
}

void NotificationManager::handleWidgetAccepted(quint32 notificationId){
    EventNotificationWidget *widget = m_activeNotifications.value(notificationId);
    NotificationInfo info = m_widgetToInfoMap.value(widget);
    switch(info.eventType)
    {
    // здесь data - это id трансфера
    case EventType::FileTransferRequestRecieved:
        emit fileTransferAccepted(info.data.toInt());
        break;
    default:
        qDebug() << "Кнопка принять доступна, но для неё нет действий";
        break;
    }
}

void NotificationManager::handleWidgetRejected(quint32 notificationId){
    EventNotificationWidget *widget = m_activeNotifications.value(notificationId);
    NotificationInfo info = m_widgetToInfoMap.value(widget);
    switch(info.eventType)
    {
    case EventType::FileTransferRequestRecieved:
        emit fileTransferRejected(info.data.toInt());
        removeNotification(notificationId);
        break;
    default:
        qDebug() << "Кнопка отклонить доступна, но для неё нет действий";
        break;
    }
}

void NotificationManager::handleWidgetCanceled(quint32 notificationId){
    removeNotification(notificationId);
}

void NotificationManager::handleWidgetAborted(quint32 notificationId){
    EventNotificationWidget *widget = m_activeNotifications.value(notificationId);
    NotificationInfo info = m_widgetToInfoMap.value(widget);
    switch(info.eventType)
    {
    // здесь data - это id трансфера
    case EventType::FileTransferStarted:
        emit abortUploadingFile(info.data.toInt());
        removeNotification(notificationId);
        break;
    case EventType::FileDownloading:
        emit abortReceivingFile(info.data.toInt());
        removeNotification(notificationId);
        break;
    default:
        qDebug() << "Кнопка прервать доступна, но для неё нет действий";
        break;
    }
}

NotificationInfo NotificationManager::getInfo(quint32 notificationId){
    EventNotificationWidget *widget = m_activeNotifications.value(notificationId);
    NotificationInfo info = m_widgetToInfoMap.value(widget);
    return info;
}

void NotificationManager::changeNotification(quint32 notificationId, const NotificationInfo &newInfo){
    EventNotificationWidget *widget = m_activeNotifications.value(notificationId);
    NotificationInfo &info = m_widgetToInfoMap[widget];
    info = newInfo;
    widget->showAcceptBtn(info.showAcceptButton);
    widget->showRejectBtn(info.showRejectButton);
    widget->showCancelBtn(info.showCancelButton);
    widget->showAbortBtn(info.showAbortButton);
    widget->showProgressBar(info.showProgressBar);
    widget->setEventData(info.description, info.senderName, info.eventType);
}

void NotificationManager::updateNotificationProgress(quint32 notificationId, const quint8 &progress){
    EventNotificationWidget *widget = m_activeNotifications.value(notificationId);
    widget->setProgressBarValue(progress);
}

void NotificationManager::removeNotification(quint32 notificationId){
    EventNotificationWidget *widget = m_activeNotifications.value(notificationId);
    m_widgetToInfoMap.remove(widget);
    m_activeNotifications.remove(notificationId);
    widget->deleteNotification();
}
