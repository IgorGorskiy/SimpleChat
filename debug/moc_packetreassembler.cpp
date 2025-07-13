/****************************************************************************
** Meta object code from reading C++ file 'packetreassembler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../packetreassembler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packetreassembler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketReassembler_t {
    QByteArrayData data[18];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PacketReassembler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PacketReassembler_t qt_meta_stringdata_PacketReassembler = {
    {
QT_MOC_LITERAL(0, 0, 17), // "PacketReassembler"
QT_MOC_LITERAL(1, 18, 16), // "fullMessageReady"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "MessageHeader"
QT_MOC_LITERAL(4, 50, 6), // "header"
QT_MOC_LITERAL(5, 57, 7), // "payload"
QT_MOC_LITERAL(6, 65, 12), // "QHostAddress"
QT_MOC_LITERAL(7, 78, 13), // "senderAddress"
QT_MOC_LITERAL(8, 92, 10), // "senderPort"
QT_MOC_LITERAL(9, 103, 13), // "reQueryNeeded"
QT_MOC_LITERAL(10, 117, 17), // "originalMessageId"
QT_MOC_LITERAL(11, 135, 16), // "QVector<quint16>"
QT_MOC_LITERAL(12, 152, 20), // "missingPacketNumbers"
QT_MOC_LITERAL(13, 173, 16), // "downloadProgress"
QT_MOC_LITERAL(14, 190, 9), // "messageId"
QT_MOC_LITERAL(15, 200, 18), // "progressPercentage"
QT_MOC_LITERAL(16, 219, 23), // "processIncomingDatagram"
QT_MOC_LITERAL(17, 243, 8) // "datagram"

    },
    "PacketReassembler\0fullMessageReady\0\0"
    "MessageHeader\0header\0payload\0QHostAddress\0"
    "senderAddress\0senderPort\0reQueryNeeded\0"
    "originalMessageId\0QVector<quint16>\0"
    "missingPacketNumbers\0downloadProgress\0"
    "messageId\0progressPercentage\0"
    "processIncomingDatagram\0datagram"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketReassembler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       9,    2,   43,    2, 0x06 /* Public */,
      13,    2,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    3,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 6, QMetaType::UShort,    4,    5,    7,    8,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 11,   10,   12,
    QMetaType::Void, QMetaType::UInt, QMetaType::UChar,   14,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 6, QMetaType::UShort,   17,    7,    8,

       0        // eod
};

void PacketReassembler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketReassembler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fullMessageReady((*reinterpret_cast< const MessageHeader(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QHostAddress(*)>(_a[3])),(*reinterpret_cast< quint16(*)>(_a[4]))); break;
        case 1: _t->reQueryNeeded((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QVector<quint16>(*)>(_a[2]))); break;
        case 2: _t->downloadProgress((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 3: _t->processIncomingDatagram((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MessageHeader >(); break;
            }
            break;
        case 1:
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
            using _t = void (PacketReassembler::*)(const MessageHeader & , const QByteArray , const QHostAddress & , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketReassembler::fullMessageReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PacketReassembler::*)(quint32 , const QVector<quint16> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketReassembler::reQueryNeeded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PacketReassembler::*)(quint32 , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketReassembler::downloadProgress)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PacketReassembler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PacketReassembler.data,
    qt_meta_data_PacketReassembler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PacketReassembler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketReassembler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketReassembler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PacketReassembler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PacketReassembler::fullMessageReady(const MessageHeader & _t1, const QByteArray _t2, const QHostAddress & _t3, quint16 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PacketReassembler::reQueryNeeded(quint32 _t1, const QVector<quint16> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PacketReassembler::downloadProgress(quint32 _t1, quint8 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
