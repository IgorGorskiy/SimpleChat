#include "eventnotificationwidget.h"
#include "ui_eventnotificationwidget.h"

EventNotificationWidget::EventNotificationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EventNotificationWidget)
{
    ui->setupUi(this);

    connect(ui->btnAccept, &QPushButton::clicked,
            this, &EventNotificationWidget::onAcceptClicked);
    connect(ui->btnReject, &QPushButton::clicked,
            this, &EventNotificationWidget::onRejectClicked);
    connect(ui->btnCancel, &QPushButton::clicked,
            this, &EventNotificationWidget::onCancelClicked);
    connect(ui->btnAbort, &QPushButton::clicked,
            this, &EventNotificationWidget::onAbortClicked);

    // Стилизация
    setStyleSheet("border: 1px solid #ccc; border-radius: 5px; padding: 10px;");
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    //this->setStyleSheet("background-color:grey;");
}

void EventNotificationWidget::setEventData(const QString &description,
                                           const QString &sender,
                                           EventType type) {
    ui->eventDescription->setText(description);
    currentSender = sender;
    currentType = type;
}

void EventNotificationWidget::showProgressBar(bool show) {
    ui->progressBar->setVisible(show);
}

void EventNotificationWidget::setProgressBarValue(uint value) {
    ui->progressBar->setValue(value);
}

void EventNotificationWidget::showAcceptBtn(bool show) {
    ui->btnAccept->setVisible(show);
}

void EventNotificationWidget::showRejectBtn(bool show) {
    ui->btnReject->setVisible(show);
}
void EventNotificationWidget::showAbortBtn(bool show){
    ui->btnAbort->setVisible(show);
}
void EventNotificationWidget::showCancelBtn(bool show){
    ui->btnCancel->setVisible(show);
}

void EventNotificationWidget::onAcceptClicked() {
    emit accepted();
}

void EventNotificationWidget::onRejectClicked() {
    emit rejected();
}

void EventNotificationWidget::onCancelClicked() {
    emit canceled();
    deleteNotification();
}

void EventNotificationWidget::onAbortClicked() {
    emit aborted();
}

EventNotificationWidget::~EventNotificationWidget()
{
    delete ui;
}

void EventNotificationWidget::deleteNotification() {
    this->deleteLater();
}
