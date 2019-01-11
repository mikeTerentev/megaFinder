/****************************************************************************
** Meta object code from reading C++ file 'trigramssearcher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../trigramssearcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trigramssearcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrigramsSearcher_t {
    QByteArrayData data[15];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrigramsSearcher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrigramsSearcher_t qt_meta_stringdata_TrigramsSearcher = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TrigramsSearcher"
QT_MOC_LITERAL(1, 17, 12), // "filesCounted"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "fileDone"
QT_MOC_LITERAL(4, 40, 14), // "finishedSearch"
QT_MOC_LITERAL(5, 55, 40), // "QVector<QPair<QString,QList<Q..."
QT_MOC_LITERAL(6, 96, 18), // "addPreprocessedDir"
QT_MOC_LITERAL(7, 115, 14), // "foundDuplicate"
QT_MOC_LITERAL(8, 130, 12), // "fileIndexing"
QT_MOC_LITERAL(9, 143, 8), // "finished"
QT_MOC_LITERAL(10, 152, 11), // "finishedAll"
QT_MOC_LITERAL(11, 164, 8), // "indexDir"
QT_MOC_LITERAL(12, 173, 15), // "getFileTrigrams"
QT_MOC_LITERAL(13, 189, 14), // "QSet<uint64_t>"
QT_MOC_LITERAL(14, 204, 4) // "find"

    },
    "TrigramsSearcher\0filesCounted\0\0fileDone\0"
    "finishedSearch\0QVector<QPair<QString,QList<QString> > >\0"
    "addPreprocessedDir\0foundDuplicate\0"
    "fileIndexing\0finished\0finishedAll\0"
    "indexDir\0getFileTrigrams\0QSet<uint64_t>\0"
    "find"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrigramsSearcher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    1,   77,    2, 0x06 /* Public */,
       4,    1,   80,    2, 0x06 /* Public */,
       6,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
       8,    1,   89,    2, 0x06 /* Public */,
       9,    0,   92,    2, 0x06 /* Public */,
       9,    1,   93,    2, 0x06 /* Public */,
      10,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 13,
    QMetaType::Void,

       0        // eod
};

void TrigramsSearcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrigramsSearcher *_t = static_cast<TrigramsSearcher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filesCounted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->fileDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->finishedSearch((*reinterpret_cast< QVector<QPair<QString,QList<QString> > >(*)>(_a[1]))); break;
        case 3: _t->addPreprocessedDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->foundDuplicate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->fileIndexing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->finished(); break;
        case 7: _t->finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->finishedAll((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->indexDir(); break;
        case 10: { QSet<uint64_t> _r = _t->getFileTrigrams();
            if (_a[0]) *reinterpret_cast< QSet<uint64_t>*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->find(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrigramsSearcher::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::filesCounted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::fileDone)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)(QVector<QPair<QString,QList<QString>> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::finishedSearch)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::addPreprocessedDir)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::foundDuplicate)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::fileIndexing)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::finished)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::finished)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TrigramsSearcher::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrigramsSearcher::finishedAll)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TrigramsSearcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TrigramsSearcher.data,
      qt_meta_data_TrigramsSearcher,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TrigramsSearcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrigramsSearcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrigramsSearcher.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TrigramsSearcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TrigramsSearcher::filesCounted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrigramsSearcher::fileDone(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrigramsSearcher::finishedSearch(QVector<QPair<QString,QList<QString>> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TrigramsSearcher::addPreprocessedDir(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TrigramsSearcher::foundDuplicate(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TrigramsSearcher::fileIndexing(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TrigramsSearcher::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TrigramsSearcher::finished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TrigramsSearcher::finishedAll(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
