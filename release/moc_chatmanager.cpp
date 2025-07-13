/****************************************************************************
** Meta object code from reading C++ file 'chatmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chatmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatManager_t {
    QByteArrayData data[16];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatManager_t qt_meta_stringdata_ChatManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ChatManager"
QT_MOC_LITERAL(1, 12, 24), // "incomingMessageProcessed"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "messageId"
QT_MOC_LITERAL(4, 48, 20), // "newMessageForDisplay"
QT_MOC_LITERAL(5, 69, 11), // "ChatMessage"
QT_MOC_LITERAL(6, 81, 7), // "message"
QT_MOC_LITERAL(7, 89, 19), // "messageStatusUpdate"
QT_MOC_LITERAL(8, 109, 19), // "ChatMessage::Status"
QT_MOC_LITERAL(9, 129, 6), // "status"
QT_MOC_LITERAL(10, 136, 20), // "constructTextMessage"
QT_MOC_LITERAL(11, 157, 4), // "text"
QT_MOC_LITERAL(12, 162, 26), // "processIncomingTextMessage"
QT_MOC_LITERAL(13, 189, 14), // "const QString*"
QT_MOC_LITERAL(14, 204, 12), // "QHostAddress"
QT_MOC_LITERAL(15, 217, 13) // "senderAddress"

    },
    "ChatManager\0incomingMessageProcessed\0"
    "\0messageId\0newMessageForDisplay\0"
    "ChatMessage\0message\0messageStatusUpdate\0"
    "ChatMessage::Status\0status\0"
    "constructTextMessage\0text\0"
    "processIncomingTextMessage\0const QString*\0"
    "QHostAddress\0senderAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       7,    2,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   50,    2, 0x0a /* Public */,
      12,    3,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 8,    3,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    3,   11,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 13, 0x80000000 | 14,    3,   11,   15,

       0        // eod
};

void ChatManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->incomingMessageProcessed((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->newMessageForDisplay((*reinterpret_cast< const ChatMessage(*)>(_a[1]))); break;
        case 2: _t->messageStatusUpdate((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< ChatMessage::Status(*)>(_a[2]))); break;
        case 3: _t->constructTextMessage((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->processIncomingTextMessage((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QString*(*)>(_a[2])),(*reinterpret_cast< const QHostAddress(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ChatMessage >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatManager::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatManager::incomingMessageProcessed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChatManager::*)(const ChatMessage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatManager::newMessageForDisplay)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChatManager::*)(quint32 , ChatMessage::Status );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatManager::messageStatusUpdate)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ChatManager.data,
    qt_meta_data_ChatManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChatManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ChatManager::incomingMessageProcessed(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatManager::newMessageForDisplay(const ChatMessage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChatManager::messageStatusUpdate(quint32 _t1, ChatMessage::Status _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
