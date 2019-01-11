/****************************************************************************
** Meta object code from reading C++ file 'dirlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dirlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dirlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DirList_t {
    QByteArrayData data[11];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DirList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DirList_t qt_meta_stringdata_DirList = {
    {
QT_MOC_LITERAL(0, 0, 7), // "DirList"
QT_MOC_LITERAL(1, 8, 10), // "addFileDir"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "dir"
QT_MOC_LITERAL(4, 24, 9), // "deleteDir"
QT_MOC_LITERAL(5, 34, 11), // "fileClicked"
QT_MOC_LITERAL(6, 46, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 63, 4), // "item"
QT_MOC_LITERAL(8, 68, 13), // "keyPressEvent"
QT_MOC_LITERAL(9, 82, 10), // "QKeyEvent*"
QT_MOC_LITERAL(10, 93, 5) // "event"

    },
    "DirList\0addFileDir\0\0dir\0deleteDir\0"
    "fileClicked\0QTreeWidgetItem*\0item\0"
    "keyPressEvent\0QKeyEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DirList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void DirList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DirList *_t = static_cast<DirList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addFileDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->deleteDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fileClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DirList::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_DirList.data,
      qt_meta_data_DirList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DirList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DirList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DirList.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int DirList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
