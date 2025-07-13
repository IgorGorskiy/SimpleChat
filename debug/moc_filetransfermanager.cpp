/****************************************************************************
** Meta object code from reading C++ file 'filetransfermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../filetransfermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filetransfermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileTransferManager_t {
    QByteArrayData data[25];
    char stringdata0[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileTransferManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileTransferManager_t qt_meta_stringdata_FileTransferManager = {
    {
QT_MOC_LITERAL(0, 0, 19), // "FileTransferManager"
QT_MOC_LITERAL(1, 20, 17), // "fileReadyToUpload"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 10), // "transferId"
QT_MOC_LITERAL(4, 50, 6), // "QFile&"
QT_MOC_LITERAL(5, 57, 4), // "file"
QT_MOC_LITERAL(6, 62, 18), // "defineTransferInfo"
QT_MOC_LITERAL(7, 81, 8), // "filePath"
QT_MOC_LITERAL(8, 90, 26), // "processFileTransferRequest"
QT_MOC_LITERAL(9, 117, 14), // "FileInfoHeader"
QT_MOC_LITERAL(10, 132, 8), // "fileInfo"
QT_MOC_LITERAL(11, 141, 8), // "fileName"
QT_MOC_LITERAL(12, 150, 12), // "QHostAddress"
QT_MOC_LITERAL(13, 163, 13), // "senderAddress"
QT_MOC_LITERAL(14, 177, 10), // "senderPort"
QT_MOC_LITERAL(15, 188, 29), // "processFileTransferPermission"
QT_MOC_LITERAL(16, 218, 10), // "permission"
QT_MOC_LITERAL(17, 229, 24), // "handleFileTransferAnswer"
QT_MOC_LITERAL(18, 254, 8), // "accepted"
QT_MOC_LITERAL(19, 263, 22), // "updateSentFileProgress"
QT_MOC_LITERAL(20, 286, 8), // "progress"
QT_MOC_LITERAL(21, 295, 26), // "updateReceivedFileProgress"
QT_MOC_LITERAL(22, 322, 21), // "processFileDownloaded"
QT_MOC_LITERAL(23, 344, 7), // "payload"
QT_MOC_LITERAL(24, 352, 14) // "processFileAck"

    },
    "FileTransferManager\0fileReadyToUpload\0"
    "\0transferId\0QFile&\0file\0defineTransferInfo\0"
    "filePath\0processFileTransferRequest\0"
    "FileInfoHeader\0fileInfo\0fileName\0"
    "QHostAddress\0senderAddress\0senderPort\0"
    "processFileTransferPermission\0permission\0"
    "handleFileTransferAnswer\0accepted\0"
    "updateSentFileProgress\0progress\0"
    "updateReceivedFileProgress\0"
    "processFileDownloaded\0payload\0"
    "processFileAck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileTransferManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   64,    2, 0x0a /* Public */,
       8,    4,   69,    2, 0x0a /* Public */,
      15,    2,   78,    2, 0x0a /* Public */,
      17,    2,   83,    2, 0x0a /* Public */,
      19,    2,   88,    2, 0x0a /* Public */,
      21,    2,   93,    2, 0x0a /* Public */,
      22,    2,   98,    2, 0x0a /* Public */,
      24,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    3,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, 0x80000000 | 12, QMetaType::UShort,   10,   11,   13,   14,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    3,   16,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    3,   18,
    QMetaType::Void, QMetaType::UInt, QMetaType::UChar,    3,   20,
    QMetaType::Void, QMetaType::UInt, QMetaType::UChar,    3,   20,
    QMetaType::Void, QMetaType::UInt, QMetaType::QByteArray,    3,   23,
    QMetaType::Void, QMetaType::UInt,    3,

       0        // eod
};

void FileTransferManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileTransferManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileReadyToUpload((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QFile(*)>(_a[2]))); break;
        case 1: _t->defineTransferInfo((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->processFileTransferRequest((*reinterpret_cast< const FileInfoHeader(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QHostAddress(*)>(_a[3])),(*reinterpret_cast< quint16(*)>(_a[4]))); break;
        case 3: _t->processFileTransferPermission((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->handleFileTransferAnswer((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->updateSentFileProgress((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 6: _t->updateReceivedFileProgress((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 7: _t->processFileDownloaded((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 8: _t->processFileAck((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FileInfoHeader >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileTransferManager::*)(quint32 , QFile & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileTransferManager::fileReadyToUpload)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileTransferManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileTransferManager.data,
    qt_meta_data_FileTransferManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileTransferManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileTransferManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileTransferManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileTransferManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FileTransferManager::fileReadyToUpload(quint32 _t1, QFile & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
