/****************************************************************************
** Meta object code from reading C++ file 'trigramsRepository.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../trgrmlib/headers/trigramsRepository.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSet>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trigramsRepository.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrigramsRepository_t {
    QByteArrayData data[10];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrigramsRepository_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrigramsRepository_t qt_meta_stringdata_TrigramsRepository = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TrigramsRepository"
QT_MOC_LITERAL(1, 19, 19), // "intertuptionRequest"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 8), // "fileDone"
QT_MOC_LITERAL(4, 49, 13), // "findDirByPath"
QT_MOC_LITERAL(5, 63, 4), // "path"
QT_MOC_LITERAL(6, 68, 6), // "insert"
QT_MOC_LITERAL(7, 75, 3), // "dir"
QT_MOC_LITERAL(8, 79, 29), // "QMap<QString,QSet<uint64_t> >"
QT_MOC_LITERAL(9, 109, 5) // "tdata"

    },
    "TrigramsRepository\0intertuptionRequest\0"
    "\0fileDone\0findDirByPath\0path\0insert\0"
    "dir\0QMap<QString,QSet<uint64_t> >\0"
    "tdata"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrigramsRepository[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   38,    2, 0x0a /* Public */,
       6,    2,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::QString, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    7,    9,

       0        // eod
};

void TrigramsRepository::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrigramsRepository *_t = static_cast<TrigramsRepository *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->intertuptionRequest(); break;
        case 1: _t->fileDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { QString _r = _t->findDirByPath((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->insert((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QSet<uint64_t> >(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrigramsRepository::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsRepository::intertuptionRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrigramsRepository::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsRepository::fileDone)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TrigramsRepository::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TrigramsRepository.data,
      qt_meta_data_TrigramsRepository,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TrigramsRepository::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrigramsRepository::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrigramsRepository.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TrigramsRepository::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TrigramsRepository::intertuptionRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TrigramsRepository::fileDone(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
