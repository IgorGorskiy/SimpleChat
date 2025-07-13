QT       += core gui
QT += network
QT += core gui sql
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ackmanager.cpp \
    chatmanager.cpp \
    commandprocessor.cpp \
    databasemanager.cpp \
    eventnotificationwidget.cpp \
    filetransfermanager.cpp \
    main.cpp \
    ChatWindow.cpp \
    messagecomposer.cpp \
    messagedelegate.cpp \
    messagemodel.cpp \
    messageworker.cpp \
    networkmanager.cpp \
    notificationmanager.cpp \
    packetreassembler.cpp \
    protocolhandler.cpp

HEADERS += \
    ChatWindow.h \
    Constants.h \
    Structs.h \
    ackmanager.h \
    chatmanager.h \
    commandprocessor.h \
    databasemanager.h \
    eventnotificationwidget.h \
    filetransfermanager.h \
    messagecomposer.h \
    messagedelegate.h \
    messagemodel.h \
    messageworker.h \
    networkmanager.h \
    notificationmanager.h \
    packetreassembler.h \
    protocolhandler.h

FORMS += \
    chatwindow.ui \
    eventnotificationwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
