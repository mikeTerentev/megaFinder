/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_main_window_t {
    QByteArrayData data[24];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_window_t qt_meta_stringdata_main_window = {
    {
QT_MOC_LITERAL(0, 0, 11), // "main_window"
QT_MOC_LITERAL(1, 12, 13), // "stopSearching"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "stopIndexing"
QT_MOC_LITERAL(4, 40, 10), // "updateFile"
QT_MOC_LITERAL(5, 51, 4), // "path"
QT_MOC_LITERAL(6, 56, 15), // "updateDirectory"
QT_MOC_LITERAL(7, 72, 3), // "dir"
QT_MOC_LITERAL(8, 76, 13), // "changePattern"
QT_MOC_LITERAL(9, 90, 4), // "find"
QT_MOC_LITERAL(10, 95, 11), // "fileClicked"
QT_MOC_LITERAL(11, 107, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(12, 124, 6), // "widget"
QT_MOC_LITERAL(13, 131, 8), // "openFile"
QT_MOC_LITERAL(14, 140, 18), // "addPreprocessedDir"
QT_MOC_LITERAL(15, 159, 6), // "curDir"
QT_MOC_LITERAL(16, 166, 16), // "addFileDirectory"
QT_MOC_LITERAL(17, 183, 4), // "prev"
QT_MOC_LITERAL(18, 188, 14), // "foundDuplicate"
QT_MOC_LITERAL(19, 203, 14), // "finishedSearch"
QT_MOC_LITERAL(20, 218, 40), // "QVector<QPair<QString,QList<Q..."
QT_MOC_LITERAL(21, 259, 4), // "info"
QT_MOC_LITERAL(22, 264, 17), // "show_about_dialog"
QT_MOC_LITERAL(23, 282, 4) // "next"

    },
    "main_window\0stopSearching\0\0stopIndexing\0"
    "updateFile\0path\0updateDirectory\0dir\0"
    "changePattern\0find\0fileClicked\0"
    "QTreeWidgetItem*\0widget\0openFile\0"
    "addPreprocessedDir\0curDir\0addFileDirectory\0"
    "prev\0foundDuplicate\0finishedSearch\0"
    "QVector<QPair<QString,QList<QString> > >\0"
    "info\0show_about_dialog\0next"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   96,    2, 0x0a /* Public */,
       6,    1,   99,    2, 0x0a /* Public */,
       8,    0,  102,    2, 0x0a /* Public */,
       9,    0,  103,    2, 0x0a /* Public */,
      10,    1,  104,    2, 0x0a /* Public */,
      13,    1,  107,    2, 0x0a /* Public */,
      14,    1,  110,    2, 0x0a /* Public */,
      16,    1,  113,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x2a /* Public | MethodCloned */,
      17,    0,  117,    2, 0x0a /* Public */,
      18,    1,  118,    2, 0x0a /* Public */,
      19,    1,  121,    2, 0x0a /* Public */,
      22,    0,  124,    2, 0x08 /* Private */,
      23,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void main_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        main_window *_t = static_cast<main_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopSearching(); break;
        case 1: _t->stopIndexing(); break;
        case 2: _t->updateFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->changePattern(); break;
        case 5: _t->find(); break;
        case 6: _t->fileClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->addPreprocessedDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->addFileDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->addFileDirectory(); break;
        case 11: _t->prev(); break;
        case 12: _t->foundDuplicate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->finishedSearch((*reinterpret_cast< QVector<QPair<QString,QList<QString> > >(*)>(_a[1]))); break;
        case 14: _t->show_about_dialog(); break;
        case 15: _t->next(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (main_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&main_window::stopSearching)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (main_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&main_window::stopIndexing)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject main_window::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_main_window.data,
      qt_meta_data_main_window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *main_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_main_window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int main_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void main_window::stopSearching()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void main_window::stopIndexing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
