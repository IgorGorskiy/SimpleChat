/********************************************************************************
** Form generated from reading UI file 'eventnotificationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTNOTIFICATIONWIDGET_H
#define UI_EVENTNOTIFICATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventNotificationWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *eventDescription;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAccept;
    QPushButton *btnReject;
    QProgressBar *progressBar;

    void setupUi(QWidget *EventNotificationWidget)
    {
        if (EventNotificationWidget->objectName().isEmpty())
            EventNotificationWidget->setObjectName(QString::fromUtf8("EventNotificationWidget"));
        EventNotificationWidget->resize(400, 200);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventNotificationWidget->sizePolicy().hasHeightForWidth());
        EventNotificationWidget->setSizePolicy(sizePolicy);
        EventNotificationWidget->setMinimumSize(QSize(400, 200));
        EventNotificationWidget->setMaximumSize(QSize(16777215, 200));
        EventNotificationWidget->setSizeIncrement(QSize(1, 0));
        EventNotificationWidget->setBaseSize(QSize(400, 150));
        QPalette palette;
        QBrush brush(QColor(2, 240, 18, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        EventNotificationWidget->setPalette(palette);
        verticalLayoutWidget = new QWidget(EventNotificationWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        eventDescription = new QLabel(verticalLayoutWidget);
        eventDescription->setObjectName(QString::fromUtf8("eventDescription"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(eventDescription->sizePolicy().hasHeightForWidth());
        eventDescription->setSizePolicy(sizePolicy1);
        eventDescription->setMinimumSize(QSize(360, 20));
        eventDescription->setMaximumSize(QSize(16777215, 60));
        eventDescription->setBaseSize(QSize(360, 20));

        verticalLayout->addWidget(eventDescription);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        btnAccept = new QPushButton(verticalLayoutWidget);
        btnAccept->setObjectName(QString::fromUtf8("btnAccept"));
        btnAccept->setMinimumSize(QSize(0, 40));
        btnAccept->setMaximumSize(QSize(16777215, 40));
        btnAccept->setBaseSize(QSize(0, 40));
        QPalette palette1;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush1);
        QBrush brush3(QColor(0, 255, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush4(QColor(255, 255, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        QBrush brush5(QColor(85, 0, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush6(QColor(255, 255, 127, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        btnAccept->setPalette(palette1);

        horizontalLayout->addWidget(btnAccept);

        btnReject = new QPushButton(verticalLayoutWidget);
        btnReject->setObjectName(QString::fromUtf8("btnReject"));
        btnReject->setMinimumSize(QSize(0, 40));
        btnReject->setMaximumSize(QSize(16777215, 40));
        btnReject->setSizeIncrement(QSize(1, 0));
        btnReject->setBaseSize(QSize(0, 40));

        horizontalLayout->addWidget(btnReject);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(progressBar);


        retranslateUi(EventNotificationWidget);

        QMetaObject::connectSlotsByName(EventNotificationWidget);
    } // setupUi

    void retranslateUi(QWidget *EventNotificationWidget)
    {
        EventNotificationWidget->setWindowTitle(QCoreApplication::translate("EventNotificationWidget", "Form", nullptr));
        eventDescription->setText(QCoreApplication::translate("EventNotificationWidget", "TextLabel", nullptr));
        btnAccept->setText(QCoreApplication::translate("EventNotificationWidget", "Accept", nullptr));
        btnReject->setText(QCoreApplication::translate("EventNotificationWidget", "Reject", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventNotificationWidget: public Ui_EventNotificationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTNOTIFICATIONWIDGET_H
