/****************************************************************************
** Meta object code from reading C++ file 'messagecomposer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../messagecomposer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagecomposer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageComposer_t {
    QByteArrayData data[15];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageComposer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageComposer_t qt_meta_stringdata_MessageComposer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MessageComposer"
QT_MOC_LITERAL(1, 16, 24), // "datagramsReadyForSending"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 9), // "messageId"
QT_MOC_LITERAL(4, 52, 19), // "QVector<QByteArray>"
QT_MOC_LITERAL(5, 72, 9), // "datagrams"
QT_MOC_LITERAL(6, 82, 11), // "ackRequired"
QT_MOC_LITERAL(7, 94, 19), // "textMessageComposed"
QT_MOC_LITERAL(8, 114, 4), // "text"
QT_MOC_LITERAL(9, 119, 20), // "transferRequestReady"
QT_MOC_LITERAL(10, 140, 10), // "transferId"
QT_MOC_LITERAL(11, 151, 8), // "filePath"
QT_MOC_LITERAL(12, 160, 19), // "setComposerSettings"
QT_MOC_LITERAL(13, 180, 16), // "ComposerSettings"
QT_MOC_LITERAL(14, 197, 8) // "settings"

    },
    "MessageComposer\0datagramsReadyForSending\0"
    "\0messageId\0QVector<QByteArray>\0datagrams\0"
    "ackRequired\0textMessageComposed\0text\0"
    "transferRequestReady\0transferId\0"
    "filePath\0setComposerSettings\0"
    "ComposerSettings\0settings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageComposer[] = {

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
       1,    3,   34,    2, 0x06 /* Public */,
       7,    2,   41,    2, 0x06 /* Public */,
       9,    2,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, QMetaType::Bool,    3,    5,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    3,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   10,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void MessageComposer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageComposer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->datagramsReadyForSending((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->textMessageComposed((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->transferRequestReady((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->setComposerSettings((*reinterpret_cast< ComposerSettings(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
            using _t = void (MessageComposer::*)(quint32 , const QVector<QByteArray> , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageComposer::datagramsReadyForSending)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MessageComposer::*)(quint32 , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageComposer::textMessageComposed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MessageComposer::*)(quint32 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageComposer::transferRequestReady)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MessageComposer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MessageComposer.data,
    qt_meta_data_MessageComposer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MessageComposer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageComposer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageComposer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MessageComposer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MessageComposer::datagramsReadyForSending(quint32 _t1, const QVector<QByteArray> _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageComposer::textMessageComposed(quint32 _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MessageComposer::transferRequestReady(quint32 _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
