/****************************************************************************
** Meta object code from reading C++ file 'networkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../networkmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetworkManager_t {
    QByteArrayData data[23];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkManager_t qt_meta_stringdata_NetworkManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "NetworkManager"
QT_MOC_LITERAL(1, 15, 13), // "datagramReady"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "datagram"
QT_MOC_LITERAL(4, 39, 12), // "QHostAddress"
QT_MOC_LITERAL(5, 52, 6), // "sender"
QT_MOC_LITERAL(6, 59, 10), // "senderPort"
QT_MOC_LITERAL(7, 70, 11), // "socketError"
QT_MOC_LITERAL(8, 82, 23), // "QUdpSocket::SocketError"
QT_MOC_LITERAL(9, 106, 5), // "error"
QT_MOC_LITERAL(10, 112, 7), // "message"
QT_MOC_LITERAL(11, 120, 14), // "uploadProgress"
QT_MOC_LITERAL(12, 135, 9), // "messageId"
QT_MOC_LITERAL(13, 145, 18), // "progressPercentage"
QT_MOC_LITERAL(14, 164, 15), // "textMessageSent"
QT_MOC_LITERAL(15, 180, 19), // "ChatMessage::Status"
QT_MOC_LITERAL(16, 200, 6), // "status"
QT_MOC_LITERAL(17, 207, 13), // "errorOccurred"
QT_MOC_LITERAL(18, 221, 13), // "sendDatagrams"
QT_MOC_LITERAL(19, 235, 19), // "QVector<QByteArray>"
QT_MOC_LITERAL(20, 255, 9), // "datagrams"
QT_MOC_LITERAL(21, 265, 11), // "ackRequired"
QT_MOC_LITERAL(22, 277, 20) // "readPendingDatagrams"

    },
    "NetworkManager\0datagramReady\0\0datagram\0"
    "QHostAddress\0sender\0senderPort\0"
    "socketError\0QUdpSocket::SocketError\0"
    "error\0message\0uploadProgress\0messageId\0"
    "progressPercentage\0textMessageSent\0"
    "ChatMessage::Status\0status\0errorOccurred\0"
    "sendDatagrams\0QVector<QByteArray>\0"
    "datagrams\0ackRequired\0readPendingDatagrams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       7,    2,   56,    2, 0x06 /* Public */,
      11,    2,   61,    2, 0x06 /* Public */,
      14,    2,   66,    2, 0x06 /* Public */,
      17,    2,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    3,   76,    2, 0x0a /* Public */,
      22,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4, QMetaType::UShort,    3,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::UInt, QMetaType::UChar,   12,   13,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 15,   12,   16,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   12,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 19, QMetaType::Bool,   12,   20,   21,
    QMetaType::Void,

       0        // eod
};

void NetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetworkManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->datagramReady((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 1: _t->socketError((*reinterpret_cast< QUdpSocket::SocketError(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->uploadProgress((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 3: _t->textMessageSent((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< ChatMessage::Status(*)>(_a[2]))); break;
        case 4: _t->errorOccurred((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->sendDatagrams((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->readPendingDatagrams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QByteArray> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetworkManager::*)(QByteArray , QHostAddress , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::datagramReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(QUdpSocket::SocketError , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::socketError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(quint32 , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::uploadProgress)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(quint32 , ChatMessage::Status );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::textMessageSent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NetworkManager::*)(quint32 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::errorOccurred)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetworkManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NetworkManager.data,
    qt_meta_data_NetworkManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetworkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetworkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void NetworkManager::datagramReady(QByteArray _t1, QHostAddress _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkManager::socketError(QUdpSocket::SocketError _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkManager::uploadProgress(quint32 _t1, quint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkManager::textMessageSent(quint32 _t1, ChatMessage::Status _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetworkManager::errorOccurred(quint32 _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
