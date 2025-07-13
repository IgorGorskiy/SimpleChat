/****************************************************************************
** Meta object code from reading C++ file 'notificationmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../notificationmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notificationmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NotificationManager_t {
    QByteArrayData data[32];
    char stringdata0[512];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotificationManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotificationManager_t qt_meta_stringdata_NotificationManager = {
    {
QT_MOC_LITERAL(0, 0, 19), // "NotificationManager"
QT_MOC_LITERAL(1, 20, 20), // "fileTransferAccepted"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 10), // "transferId"
QT_MOC_LITERAL(4, 53, 8), // "accepted"
QT_MOC_LITERAL(5, 62, 20), // "fileTransferRejected"
QT_MOC_LITERAL(6, 83, 17), // "voiceCallAccepted"
QT_MOC_LITERAL(7, 101, 6), // "callId"
QT_MOC_LITERAL(8, 108, 12), // "QHostAddress"
QT_MOC_LITERAL(9, 121, 13), // "senderAddress"
QT_MOC_LITERAL(10, 135, 10), // "senderPort"
QT_MOC_LITERAL(11, 146, 17), // "voiceCallRejected"
QT_MOC_LITERAL(12, 164, 18), // "abortReceivingFile"
QT_MOC_LITERAL(13, 183, 18), // "abortUploadingFile"
QT_MOC_LITERAL(14, 202, 17), // "notificationAdded"
QT_MOC_LITERAL(15, 220, 14), // "notificationId"
QT_MOC_LITERAL(16, 235, 24), // "EventNotificationWidget*"
QT_MOC_LITERAL(17, 260, 6), // "widget"
QT_MOC_LITERAL(18, 267, 19), // "notificationUpdated"
QT_MOC_LITERAL(19, 287, 5), // "value"
QT_MOC_LITERAL(20, 293, 19), // "notificationRemoved"
QT_MOC_LITERAL(21, 313, 19), // "displayNotification"
QT_MOC_LITERAL(22, 333, 16), // "NotificationInfo"
QT_MOC_LITERAL(23, 350, 4), // "info"
QT_MOC_LITERAL(24, 355, 18), // "changeNotification"
QT_MOC_LITERAL(25, 374, 26), // "updateNotificationProgress"
QT_MOC_LITERAL(26, 401, 8), // "progress"
QT_MOC_LITERAL(27, 410, 18), // "removeNotification"
QT_MOC_LITERAL(28, 429, 20), // "handleWidgetAccepted"
QT_MOC_LITERAL(29, 450, 20), // "handleWidgetRejected"
QT_MOC_LITERAL(30, 471, 20), // "handleWidgetCanceled"
QT_MOC_LITERAL(31, 492, 19) // "handleWidgetAborted"

    },
    "NotificationManager\0fileTransferAccepted\0"
    "\0transferId\0accepted\0fileTransferRejected\0"
    "voiceCallAccepted\0callId\0QHostAddress\0"
    "senderAddress\0senderPort\0voiceCallRejected\0"
    "abortReceivingFile\0abortUploadingFile\0"
    "notificationAdded\0notificationId\0"
    "EventNotificationWidget*\0widget\0"
    "notificationUpdated\0value\0notificationRemoved\0"
    "displayNotification\0NotificationInfo\0"
    "info\0changeNotification\0"
    "updateNotificationProgress\0progress\0"
    "removeNotification\0handleWidgetAccepted\0"
    "handleWidgetRejected\0handleWidgetCanceled\0"
    "handleWidgetAborted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotificationManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  109,    2, 0x06 /* Public */,
       1,    1,  114,    2, 0x26 /* Public | MethodCloned */,
       5,    2,  117,    2, 0x06 /* Public */,
       5,    1,  122,    2, 0x26 /* Public | MethodCloned */,
       6,    3,  125,    2, 0x06 /* Public */,
      11,    3,  132,    2, 0x06 /* Public */,
      12,    1,  139,    2, 0x06 /* Public */,
      13,    1,  142,    2, 0x06 /* Public */,
      14,    2,  145,    2, 0x06 /* Public */,
      18,    2,  150,    2, 0x06 /* Public */,
      20,    1,  155,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  158,    2, 0x0a /* Public */,
      24,    2,  161,    2, 0x0a /* Public */,
      25,    2,  166,    2, 0x0a /* Public */,
      27,    1,  171,    2, 0x0a /* Public */,
      28,    1,  174,    2, 0x08 /* Private */,
      29,    1,  177,    2, 0x08 /* Private */,
      30,    1,  180,    2, 0x08 /* Private */,
      31,    1,  183,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 8, QMetaType::UShort,    7,    9,   10,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 8, QMetaType::UShort,    7,    9,   10,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 16,   15,   17,
    QMetaType::Void, QMetaType::UInt, QMetaType::Int,   15,   19,
    QMetaType::Void, QMetaType::UInt,   15,

 // slots: parameters
    QMetaType::UInt, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 22,   15,   23,
    QMetaType::Void, QMetaType::UInt, QMetaType::UChar,   15,   26,
    QMetaType::Void, QMetaType::UInt,   15,
    QMetaType::Void, QMetaType::UInt,   15,
    QMetaType::Void, QMetaType::UInt,   15,
    QMetaType::Void, QMetaType::UInt,   15,
    QMetaType::Void, QMetaType::UInt,   15,

       0        // eod
};

void NotificationManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NotificationManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileTransferAccepted((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->fileTransferAccepted((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->fileTransferRejected((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->fileTransferRejected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->voiceCallAccepted((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 5: _t->voiceCallRejected((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 6: _t->abortReceivingFile((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 7: _t->abortUploadingFile((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 8: _t->notificationAdded((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< EventNotificationWidget*(*)>(_a[2]))); break;
        case 9: _t->notificationUpdated((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->notificationRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 11: { quint32 _r = _t->displayNotification((*reinterpret_cast< const NotificationInfo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->changeNotification((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const NotificationInfo(*)>(_a[2]))); break;
        case 13: _t->updateNotificationProgress((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const quint8(*)>(_a[2]))); break;
        case 14: _t->removeNotification((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 15: _t->handleWidgetAccepted((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 16: _t->handleWidgetRejected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 17: _t->handleWidgetCanceled((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 18: _t->handleWidgetAborted((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EventNotificationWidget* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NotificationInfo >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NotificationInfo >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NotificationManager::*)(quint32 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::fileTransferAccepted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::fileTransferRejected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 , const QHostAddress & , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::voiceCallAccepted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 , const QHostAddress & , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::voiceCallRejected)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::abortReceivingFile)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::abortUploadingFile)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 , EventNotificationWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::notificationAdded)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::notificationUpdated)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (NotificationManager::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NotificationManager::notificationRemoved)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NotificationManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NotificationManager.data,
    qt_meta_data_NotificationManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NotificationManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotificationManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotificationManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NotificationManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void NotificationManager::fileTransferAccepted(quint32 _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void NotificationManager::fileTransferRejected(quint32 _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void NotificationManager::voiceCallAccepted(quint32 _t1, const QHostAddress & _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NotificationManager::voiceCallRejected(quint32 _t1, const QHostAddress & _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NotificationManager::abortReceivingFile(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void NotificationManager::abortUploadingFile(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void NotificationManager::notificationAdded(quint32 _t1, EventNotificationWidget * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void NotificationManager::notificationUpdated(quint32 _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void NotificationManager::notificationRemoved(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
