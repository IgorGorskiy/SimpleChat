/****************************************************************************
** Meta object code from reading C++ file 'ChatWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ChatWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatWindow_t {
    QByteArrayData data[28];
    char stringdata0[438];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatWindow_t qt_meta_stringdata_ChatWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChatWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "readPendingDatagrams"
QT_MOC_LITERAL(4, 55, 26), // "on_packetSize_valueChanged"
QT_MOC_LITERAL(5, 82, 5), // "value"
QT_MOC_LITERAL(6, 88, 27), // "onRemoteAddressValueChanged"
QT_MOC_LITERAL(7, 116, 24), // "onRemotePortValueChanged"
QT_MOC_LITERAL(8, 141, 20), // "onMyPortValueChanged"
QT_MOC_LITERAL(9, 162, 8), // "sendPing"
QT_MOC_LITERAL(10, 171, 12), // "creationTime"
QT_MOC_LITERAL(11, 184, 10), // "isResponce"
QT_MOC_LITERAL(12, 195, 24), // "processIncompleteMessage"
QT_MOC_LITERAL(13, 220, 9), // "messageId"
QT_MOC_LITERAL(14, 230, 19), // "handleEventAccepted"
QT_MOC_LITERAL(15, 250, 9), // "EventType"
QT_MOC_LITERAL(16, 260, 4), // "type"
QT_MOC_LITERAL(17, 265, 11), // "QByteArray&"
QT_MOC_LITERAL(18, 277, 9), // "eventData"
QT_MOC_LITERAL(19, 287, 19), // "handleEventRejected"
QT_MOC_LITERAL(20, 307, 26), // "handleDeliveryConfirmation"
QT_MOC_LITERAL(21, 334, 25), // "checkPendingConfirmations"
QT_MOC_LITERAL(22, 360, 14), // "onMessageError"
QT_MOC_LITERAL(23, 375, 5), // "error"
QT_MOC_LITERAL(24, 381, 13), // "onMessageSent"
QT_MOC_LITERAL(25, 395, 12), // "onPacketSent"
QT_MOC_LITERAL(26, 408, 5), // "bytes"
QT_MOC_LITERAL(27, 414, 23) // "onSendFileButtonClicked"

    },
    "ChatWindow\0on_sendButton_clicked\0\0"
    "readPendingDatagrams\0on_packetSize_valueChanged\0"
    "value\0onRemoteAddressValueChanged\0"
    "onRemotePortValueChanged\0onMyPortValueChanged\0"
    "sendPing\0creationTime\0isResponce\0"
    "processIncompleteMessage\0messageId\0"
    "handleEventAccepted\0EventType\0type\0"
    "QByteArray&\0eventData\0handleEventRejected\0"
    "handleDeliveryConfirmation\0"
    "checkPendingConfirmations\0onMessageError\0"
    "error\0onMessageSent\0onPacketSent\0bytes\0"
    "onSendFileButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    1,  106,    2, 0x08 /* Private */,
       6,    1,  109,    2, 0x08 /* Private */,
       7,    1,  112,    2, 0x08 /* Private */,
       8,    1,  115,    2, 0x08 /* Private */,
       9,    2,  118,    2, 0x08 /* Private */,
       9,    1,  123,    2, 0x28 /* Private | MethodCloned */,
       9,    0,  126,    2, 0x28 /* Private | MethodCloned */,
      12,    1,  127,    2, 0x08 /* Private */,
      14,    2,  130,    2, 0x08 /* Private */,
      19,    2,  135,    2, 0x08 /* Private */,
      20,    1,  140,    2, 0x08 /* Private */,
      21,    0,  143,    2, 0x08 /* Private */,
      22,    2,  144,    2, 0x08 /* Private */,
      24,    1,  149,    2, 0x08 /* Private */,
      25,    2,  152,    2, 0x08 /* Private */,
      27,    0,  157,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QTime, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::QTime,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void, QMetaType::UInt,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   13,   23,
    QMetaType::Void, QMetaType::UInt,   13,
    QMetaType::Void, QMetaType::LongLong, QMetaType::UInt,   26,   13,
    QMetaType::Void,

       0        // eod
};

void ChatWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sendButton_clicked(); break;
        case 1: _t->readPendingDatagrams(); break;
        case 2: _t->on_packetSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onRemoteAddressValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onRemotePortValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onMyPortValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->sendPing((*reinterpret_cast< QTime(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->sendPing((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 8: _t->sendPing(); break;
        case 9: _t->processIncompleteMessage((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 10: _t->handleEventAccepted((*reinterpret_cast< EventType(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 11: _t->handleEventRejected((*reinterpret_cast< EventType(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 12: _t->handleDeliveryConfirmation((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 13: _t->checkPendingConfirmations(); break;
        case 14: _t->onMessageError((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->onMessageSent((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 16: _t->onPacketSent((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 17: _t->onSendFileButtonClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ChatWindow.data,
    qt_meta_data_ChatWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChatWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
