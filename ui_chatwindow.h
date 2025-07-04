/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QTextEdit *chatDisplay;
    QSlider *packetSize;
    QLabel *packetSizeLabel;
    QTextEdit *messageInput;
    QPushButton *sendButton;
    QPushButton *sendFileButton;
    QWidget *tab_2;
    QVBoxLayout *vboxLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *eventsContainerLayout;
    QWidget *tab_3;
    QVBoxLayout *vboxLayout1;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLineEdit *myAddress;
    QLabel *label_7;
    QLineEdit *myPort;
    QLabel *label_6;
    QLineEdit *remoteAddress;
    QLabel *label_5;
    QLineEdit *remotePort;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *checkConnection;
    QLineEdit *pingInfo;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout2;
    QLabel *label_2;
    QSpinBox *transmitInterval;
    QLabel *label_3;
    QSpinBox *maxThreads;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QString::fromUtf8("ChatWindow"));
        ChatWindow->resize(600, 500);
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        chatDisplay = new QTextEdit(tab_1);
        chatDisplay->setObjectName(QString::fromUtf8("chatDisplay"));
        chatDisplay->setGeometry(QRect(10, 10, 551, 241));
        chatDisplay->setReadOnly(true);
        packetSize = new QSlider(tab_1);
        packetSize->setObjectName(QString::fromUtf8("packetSize"));
        packetSize->setGeometry(QRect(10, 260, 381, 27));
        packetSize->setMinimum(128);
        packetSize->setMaximum(2048);
        packetSize->setSingleStep(64);
        packetSize->setPageStep(128);
        packetSize->setValue(512);
        packetSize->setOrientation(Qt::Horizontal);
        packetSize->setTickPosition(QSlider::TicksBelow);
        packetSize->setTickInterval(128);
        packetSizeLabel = new QLabel(tab_1);
        packetSizeLabel->setObjectName(QString::fromUtf8("packetSizeLabel"));
        packetSizeLabel->setGeometry(QRect(410, 270, 311, 20));
        messageInput = new QTextEdit(tab_1);
        messageInput->setObjectName(QString::fromUtf8("messageInput"));
        messageInput->setGeometry(QRect(10, 299, 561, 111));
        sendButton = new QPushButton(tab_1);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(0, 420, 321, 31));
        sendFileButton = new QPushButton(tab_1);
        sendFileButton->setObjectName(QString::fromUtf8("sendFileButton"));
        sendFileButton->setGeometry(QRect(330, 420, 231, 31));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        vboxLayout = new QVBoxLayout(tab_2);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(450, 0));
        scrollArea->setMaximumSize(QSize(450, 16777215));
        scrollArea->setBaseSize(QSize(450, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 448, 431));
        eventsContainerLayout = new QVBoxLayout(scrollAreaWidgetContents);
        eventsContainerLayout->setObjectName(QString::fromUtf8("eventsContainerLayout"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        vboxLayout->addWidget(scrollArea);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        vboxLayout1 = new QVBoxLayout(tab_3);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        vboxLayout1->addWidget(label_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        myAddress = new QLineEdit(tab_3);
        myAddress->setObjectName(QString::fromUtf8("myAddress"));
        myAddress->setReadOnly(true);
        myAddress->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(myAddress);

        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        myPort = new QLineEdit(tab_3);
        myPort->setObjectName(QString::fromUtf8("myPort"));

        verticalLayout_2->addWidget(myPort);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        remoteAddress = new QLineEdit(tab_3);
        remoteAddress->setObjectName(QString::fromUtf8("remoteAddress"));

        verticalLayout_2->addWidget(remoteAddress);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        remotePort = new QLineEdit(tab_3);
        remotePort->setObjectName(QString::fromUtf8("remotePort"));

        verticalLayout_2->addWidget(remotePort);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkConnection = new QPushButton(tab_3);
        checkConnection->setObjectName(QString::fromUtf8("checkConnection"));

        horizontalLayout_2->addWidget(checkConnection);

        pingInfo = new QLineEdit(tab_3);
        pingInfo->setObjectName(QString::fromUtf8("pingInfo"));
        pingInfo->setReadOnly(true);

        horizontalLayout_2->addWidget(pingInfo);


        verticalLayout_2->addLayout(horizontalLayout_2);


        vboxLayout1->addLayout(verticalLayout_2);

        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));

        vboxLayout1->addWidget(label);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout2 = new QVBoxLayout(groupBox);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        vboxLayout2->addWidget(label_2);

        transmitInterval = new QSpinBox(groupBox);
        transmitInterval->setObjectName(QString::fromUtf8("transmitInterval"));
        transmitInterval->setMinimum(0);
        transmitInterval->setMaximum(1000);
        transmitInterval->setValue(10);

        vboxLayout2->addWidget(transmitInterval);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        vboxLayout2->addWidget(label_3);

        maxThreads = new QSpinBox(groupBox);
        maxThreads->setObjectName(QString::fromUtf8("maxThreads"));
        maxThreads->setMinimum(0);
        maxThreads->setMaximum(10);
        maxThreads->setValue(2);

        vboxLayout2->addWidget(maxThreads);


        vboxLayout1->addWidget(groupBox);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);

        ChatWindow->setCentralWidget(centralwidget);

        retranslateUi(ChatWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "UDP Chat", nullptr));
        packetSizeLabel->setText(QCoreApplication::translate("ChatWindow", "Max Packet Size: 512 bytes", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        sendFileButton->setText(QCoreApplication::translate("ChatWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("ChatWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ChatWindow", "Tab 2", nullptr));
        label_4->setText(QCoreApplication::translate("ChatWindow", "Connection settings", nullptr));
        label_8->setText(QCoreApplication::translate("ChatWindow", "\320\234\320\276\320\271 \320\260\320\264\321\200\320\265\321\201", nullptr));
        label_7->setText(QCoreApplication::translate("ChatWindow", "\320\234\320\276\320\271 \320\277\320\276\321\200\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("ChatWindow", "\320\220\320\264\321\200\320\265\321\201 \320\277\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("ChatWindow", "\320\237\320\276\321\200\321\202 \320\277\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\217", nullptr));
        checkConnection->setText(QCoreApplication::translate("ChatWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("ChatWindow", "Transmission Settings", nullptr));
        label_2->setText(QCoreApplication::translate("ChatWindow", "Packet interval (ms):", nullptr));
        label_3->setText(QCoreApplication::translate("ChatWindow", "Max threads:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("ChatWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
