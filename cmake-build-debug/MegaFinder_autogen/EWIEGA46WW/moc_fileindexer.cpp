/****************************************************************************
** Meta object code from reading C++ file 'fileindexer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../fileindexer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileindexer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileIndexer_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileIndexer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileIndexer_t qt_meta_stringdata_FileIndexer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileIndexer"
QT_MOC_LITERAL(1, 12, 18), // "findTrigramsOfFile"
QT_MOC_LITERAL(2, 31, 14), // "QSet<uint64_t>"
QT_MOC_LITERAL(3, 46, 0), // ""
QT_MOC_LITERAL(4, 47, 4) // "file"

    },
    "FileIndexer\0findTrigramsOfFile\0"
    "QSet<uint64_t>\0\0file"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileIndexer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString,    4,

       0        // eod
};

void FileIndexer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileIndexer *_t = static_cast<FileIndexer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QSet<uint64_t> _r = _t->findTrigramsOfFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSet<uint64_t>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileIndexer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileIndexer.data,
      qt_meta_data_FileIndexer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FileIndexer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileIndexer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileIndexer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileIndexer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
