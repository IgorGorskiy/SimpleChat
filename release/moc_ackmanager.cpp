/****************************************************************************
** Meta object code from reading C++ file 'ackmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ackmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ackmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AckManager_t {
    QByteArrayData data[26];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AckManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AckManager_t qt_meta_stringdata_AckManager = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AckManager"
QT_MOC_LITERAL(1, 11, 20), // "textMessageDelivered"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 9), // "messageId"
QT_MOC_LITERAL(4, 43, 19), // "ChatMessage::Status"
QT_MOC_LITERAL(5, 63, 6), // "status"
QT_MOC_LITERAL(6, 70, 16), // "textMessageError"
QT_MOC_LITERAL(7, 87, 22), // "requestResendDatagrams"
QT_MOC_LITERAL(8, 110, 19), // "QVector<QByteArray>"
QT_MOC_LITERAL(9, 130, 9), // "datagrams"
QT_MOC_LITERAL(10, 140, 12), // "QHostAddress"
QT_MOC_LITERAL(11, 153, 7), // "address"
QT_MOC_LITERAL(12, 161, 4), // "port"
QT_MOC_LITERAL(13, 166, 16), // "transmitInterval"
QT_MOC_LITERAL(14, 183, 15), // "fileAckRecieved"
QT_MOC_LITERAL(15, 199, 12), // "pingMeasured"
QT_MOC_LITERAL(16, 212, 4), // "ping"
QT_MOC_LITERAL(17, 217, 31), // "missingDatagramsReadyForSending"
QT_MOC_LITERAL(18, 249, 11), // "ackRequired"
QT_MOC_LITERAL(19, 261, 20), // "trackOutgoingMessage"
QT_MOC_LITERAL(20, 282, 18), // "processIncomingAck"
QT_MOC_LITERAL(21, 301, 22), // "processIncomingReQuery"
QT_MOC_LITERAL(22, 324, 17), // "originalMessageId"
QT_MOC_LITERAL(23, 342, 16), // "QVector<quint16>"
QT_MOC_LITERAL(24, 359, 20), // "missingPacketNumbers"
QT_MOC_LITERAL(25, 380, 16) // "checkAckTimeouts"

    },
    "AckManager\0textMessageDelivered\0\0"
    "messageId\0ChatMessage::Status\0status\0"
    "textMessageError\0requestResendDatagrams\0"
    "QVector<QByteArray>\0datagrams\0"
    "QHostAddress\0address\0port\0transmitInterval\0"
    "fileAckRecieved\0pingMeasured\0ping\0"
    "missingDatagramsReadyForSending\0"
    "ackRequired\0trackOutgoingMessage\0"
    "processIncomingAck\0processIncomingReQuery\0"
    "originalMessageId\0QVector<quint16>\0"
    "missingPacketNumbers\0checkAckTimeouts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AckManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       1,    1,   84,    2, 0x26 /* Public | MethodCloned */,
       6,    2,   87,    2, 0x06 /* Public */,
       6,    1,   92,    2, 0x26 /* Public | MethodCloned */,
       7,    5,   95,    2, 0x06 /* Public */,
      14,    1,  106,    2, 0x06 /* Public */,
      15,    1,  109,    2, 0x06 /* Public */,
      17,    3,  112,    2, 0x06 /* Public */,
      17,    2,  119,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  124,    2, 0x0a /* Public */,
      20,    1,  127,    2, 0x0a /* Public */,
      21,    2,  130,    2, 0x0a /* Public */,
      25,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 8, 0x80000000 | 10, QMetaType::UShort, QMetaType::Int,    3,    9,   11,   12,   13,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 8, QMetaType::Bool,    3,    9,   18,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 8,    3,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 23,   22,   24,
    QMetaType::Void,

       0        // eod
};

void AckManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AckManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textMessageDelivered((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< ChatMessage::Status(*)>(_a[2]))); break;
        case 1: _t->textMessageDelivered((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->textMessageError((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< ChatMessage::Status(*)>(_a[2]))); break;
        case 3: _t->textMessageError((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->requestResendDatagrams((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[2])),(*reinterpret_cast< const QHostAddress(*)>(_a[3])),(*reinterpret_cast< quint16(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: _t->fileAckRecieved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 6: _t->pingMeasured((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->missingDatagramsReadyForSending((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: _t->missingDatagramsReadyForSending((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[2]))); break;
        case 9: _t->trackOutgoingMessage((*reinterpret_cast< const QVector<QByteArray>(*)>(_a[1]))); break;
        case 10: _t->processIncomingAck((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 11: _t->processIncomingReQuery((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QVector<quint16>(*)>(_a[2]))); break;
        case 12: _t->checkAckTimeouts(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QByteArray> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QByteArray> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QByteArray> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QByteArray> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint16> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AckManager::*)(quint32 , ChatMessage::Status );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AckManager::textMessageDelivered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AckManager::*)(quint32 , ChatMessage::Status );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AckManager::textMessageError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AckManager::*)(quint32 , const QVector<QByteArray> & , const QHostAddress & , quint16 , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AckManager::requestResendDatagrams)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AckManager::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AckManager::fileAckRecieved)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AckManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AckManager::pingMeasured)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (AckManager::*)(quint32 , const QVector<QByteArray> , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AckManager::missingDatagramsReadyForSending)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AckManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AckManager.data,
    qt_meta_data_AckManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AckManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AckManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AckManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AckManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void AckManager::textMessageDelivered(quint32 _t1, ChatMessage::Status _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void AckManager::textMessageError(quint32 _t1, ChatMessage::Status _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void AckManager::requestResendDatagrams(quint32 _t1, const QVector<QByteArray> & _t2, const QHostAddress & _t3, quint16 _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AckManager::fileAckRecieved(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AckManager::pingMeasured(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AckManager::missingDatagramsReadyForSending(quint32 _t1, const QVector<QByteArray> _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
