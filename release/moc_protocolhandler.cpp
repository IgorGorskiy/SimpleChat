/****************************************************************************
** Meta object code from reading C++ file 'protocolhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../protocolhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocolhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtocolHandler_t {
    QByteArrayData data[29];
    char stringdata0[410];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProtocolHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProtocolHandler_t qt_meta_stringdata_ProtocolHandler = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProtocolHandler"
QT_MOC_LITERAL(1, 16, 15), // "reQueryReceived"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "originalMessageId"
QT_MOC_LITERAL(4, 51, 16), // "QVector<quint16>"
QT_MOC_LITERAL(5, 68, 20), // "missingPacketNumbers"
QT_MOC_LITERAL(6, 89, 9), // "ackNeeded"
QT_MOC_LITERAL(7, 99, 13), // "MessageHeader"
QT_MOC_LITERAL(8, 113, 14), // "originalHeader"
QT_MOC_LITERAL(9, 128, 19), // "textMessageRecieved"
QT_MOC_LITERAL(10, 148, 9), // "messageId"
QT_MOC_LITERAL(11, 158, 14), // "const QString*"
QT_MOC_LITERAL(12, 173, 4), // "text"
QT_MOC_LITERAL(13, 178, 12), // "QHostAddress"
QT_MOC_LITERAL(14, 191, 13), // "senderAddress"
QT_MOC_LITERAL(15, 205, 14), // "fileDownloaded"
QT_MOC_LITERAL(16, 220, 7), // "payload"
QT_MOC_LITERAL(17, 228, 11), // "ackReceived"
QT_MOC_LITERAL(18, 240, 27), // "fileTransferRequestReceived"
QT_MOC_LITERAL(19, 268, 14), // "FileInfoHeader"
QT_MOC_LITERAL(20, 283, 8), // "fileInfo"
QT_MOC_LITERAL(21, 292, 8), // "fileName"
QT_MOC_LITERAL(22, 301, 10), // "senderPort"
QT_MOC_LITERAL(23, 312, 30), // "fileTransferPermissionReceived"
QT_MOC_LITERAL(24, 343, 10), // "transferId"
QT_MOC_LITERAL(25, 354, 10), // "permission"
QT_MOC_LITERAL(26, 365, 17), // "handleFullMessage"
QT_MOC_LITERAL(27, 383, 6), // "header"
QT_MOC_LITERAL(28, 390, 19) // "handleTextProcessed"

    },
    "ProtocolHandler\0reQueryReceived\0\0"
    "originalMessageId\0QVector<quint16>\0"
    "missingPacketNumbers\0ackNeeded\0"
    "MessageHeader\0originalHeader\0"
    "textMessageRecieved\0messageId\0"
    "const QString*\0text\0QHostAddress\0"
    "senderAddress\0fileDownloaded\0payload\0"
    "ackReceived\0fileTransferRequestReceived\0"
    "FileInfoHeader\0fileInfo\0fileName\0"
    "senderPort\0fileTransferPermissionReceived\0"
    "transferId\0permission\0handleFullMessage\0"
    "header\0handleTextProcessed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtocolHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    1,   64,    2, 0x06 /* Public */,
       9,    3,   67,    2, 0x06 /* Public */,
      15,    2,   74,    2, 0x06 /* Public */,
      17,    1,   79,    2, 0x06 /* Public */,
      18,    4,   82,    2, 0x06 /* Public */,
      23,    2,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    4,   96,    2, 0x0a /* Public */,
      28,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 11, 0x80000000 | 13,   10,   12,   14,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,   10,   16,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, 0x80000000 | 19, QMetaType::QString, 0x80000000 | 13, QMetaType::UShort,   20,   21,   14,   22,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,   24,   25,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::QByteArray, 0x80000000 | 13, QMetaType::UShort,   27,   16,   14,   22,
    QMetaType::Void, QMetaType::UInt,   10,

       0        // eod
};

void ProtocolHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProtocolHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reQueryReceived((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QVector<quint16>(*)>(_a[2]))); break;
        case 1: _t->ackNeeded((*reinterpret_cast< MessageHeader(*)>(_a[1]))); break;
        case 2: _t->textMessageRecieved((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QString*(*)>(_a[2])),(*reinterpret_cast< const QHostAddress(*)>(_a[3]))); break;
        case 3: _t->fileDownloaded((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 4: _t->ackReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: _t->fileTransferRequestReceived((*reinterpret_cast< FileInfoHeader(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< const QHostAddress(*)>(_a[3])),(*reinterpret_cast< quint16(*)>(_a[4]))); break;
        case 6: _t->fileTransferPermissionReceived((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->handleFullMessage((*reinterpret_cast< const MessageHeader(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QHostAddress(*)>(_a[3])),(*reinterpret_cast< quint16(*)>(_a[4]))); break;
        case 8: _t->handleTextProcessed((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint16> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MessageHeader >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FileInfoHeader >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MessageHeader >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProtocolHandler::*)(quint32 , QVector<quint16> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHandler::reQueryReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProtocolHandler::*)(MessageHeader );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHandler::ackNeeded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProtocolHandler::*)(quint32 , const QString * , const QHostAddress & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHandler::textMessageRecieved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProtocolHandler::*)(quint32 , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHandler::fileDownloaded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ProtocolHandler::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHandler::ackReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ProtocolHandler::*)(FileInfoHeader , QString , const QHostAddress & , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHandler::fileTransferRequestReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ProtocolHandler::*)(quint32 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolHandler::fileTransferPermissionReceived)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProtocolHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ProtocolHandler.data,
    qt_meta_data_ProtocolHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProtocolHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtocolHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtocolHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProtocolHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ProtocolHandler::reQueryReceived(quint32 _t1, QVector<quint16> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProtocolHandler::ackNeeded(MessageHeader _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProtocolHandler::textMessageRecieved(quint32 _t1, const QString * _t2, const QHostAddress & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProtocolHandler::fileDownloaded(quint32 _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ProtocolHandler::ackReceived(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ProtocolHandler::fileTransferRequestReceived(FileInfoHeader _t1, QString _t2, const QHostAddress & _t3, quint16 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ProtocolHandler::fileTransferPermissionReceived(quint32 _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
