#include "eventnotificationwidget.h"
#include "ui_eventnotificationwidget.h"

EventNotificationWidget::EventNotificationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EventNotificationWidget)
{
    ui->setupUi(this);

    // Подключаем сигналы кнопок
    connect(ui->btnAccept, &QPushButton::clicked,
            this, &EventNotificationWidget::onAcceptClicked);
    connect(ui->btnReject, &QPushButton::clicked,
            this, &EventNotificationWidget::onRejectClicked);

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

    // Можно добавить тип-специфичные настройки
    if (type == EventType::FileTransferRequestRecieved) {
        ui->btnAccept->setIcon(QIcon(":/icons/accept-file.png"));
    }
}

void EventNotificationWidget::showProgressBar(bool show) {
    ui->progressBar->setVisible(show);
    //adjustSize(); // Пересчитываем размеры
}

void EventNotificationWidget::setProgressBarValue(uint value) {
    ui->progressBar->setValue(value);
}

void EventNotificationWidget::showAcceptBtn(bool show) {
    ui->btnAccept->setVisible(show);
    //adjustSize(); // Пересчитываем размеры
}

void EventNotificationWidget::showRejectBtn(bool show) {
    ui->btnReject->setVisible(show);
    //adjustSize(); // Пересчитываем размеры
}

void EventNotificationWidget::onAcceptClicked() {
    emit accepted();
    this->deleteLater(); // Самоуничтожение после обработки
}

void EventNotificationWidget::onRejectClicked() {
    emit rejected();
    this->deleteLater();
}

EventNotificationWidget::~EventNotificationWidget()
{
    delete ui;
}
