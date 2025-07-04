#ifndef EVENTNOTIFICATIONWIDGET_H
#define EVENTNOTIFICATIONWIDGET_H

#include <QWidget>
#include "Structs.h"

namespace Ui {
class EventNotificationWidget;
}

class EventNotificationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventNotificationWidget(QWidget *parent = nullptr);
    ~EventNotificationWidget();

    void setEventData(const QString &description,
                      const QString &sender,
                      EventType type);
    void showProgressBar(bool show);
    void showAcceptBtn(bool show);
    void showRejectBtn(bool show);
    void setProgressBarValue(uint value);

signals:
    void accepted(const QString &comment = "");
    void rejected(const QString &comment = "");

private slots:
    void onAcceptClicked();
    void onRejectClicked();

private:
    Ui::EventNotificationWidget *ui;
    QString currentSender;
    EventType currentType;
};

#endif // EVENTNOTIFICATIONWIDGET_H
