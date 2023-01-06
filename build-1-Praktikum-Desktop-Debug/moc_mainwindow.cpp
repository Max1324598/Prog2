/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../1-Praktikum/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[16];
    char stringdata5[15];
    char stringdata6[15];
    char stringdata7[14];
    char stringdata8[16];
    char stringdata9[16];
    char stringdata10[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "buttonOneMove"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 13),  // "buttonTwoMove"
        QT_MOC_LITERAL(40, 15),  // "buttonThreeMove"
        QT_MOC_LITERAL(56, 14),  // "buttonFourMove"
        QT_MOC_LITERAL(71, 14),  // "buttonFiveMove"
        QT_MOC_LITERAL(86, 13),  // "buttonSixMove"
        QT_MOC_LITERAL(100, 15),  // "buttonSevenMove"
        QT_MOC_LITERAL(116, 15),  // "buttonEightMove"
        QT_MOC_LITERAL(132, 14)   // "buttonNineMove"
    },
    "MainWindow",
    "buttonOneMove",
    "",
    "buttonTwoMove",
    "buttonThreeMove",
    "buttonFourMove",
    "buttonFiveMove",
    "buttonSixMove",
    "buttonSevenMove",
    "buttonEightMove",
    "buttonNineMove"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    0,   69,    2, 0x0a,    2 /* Public */,
       4,    0,   70,    2, 0x0a,    3 /* Public */,
       5,    0,   71,    2, 0x0a,    4 /* Public */,
       6,    0,   72,    2, 0x0a,    5 /* Public */,
       7,    0,   73,    2, 0x0a,    6 /* Public */,
       8,    0,   74,    2, 0x0a,    7 /* Public */,
       9,    0,   75,    2, 0x0a,    8 /* Public */,
      10,    0,   76,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'buttonOneMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonTwoMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonThreeMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonFourMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonFiveMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonSixMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonSevenMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonEightMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buttonNineMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->buttonOneMove(); break;
        case 1: _t->buttonTwoMove(); break;
        case 2: _t->buttonThreeMove(); break;
        case 3: _t->buttonFourMove(); break;
        case 4: _t->buttonFiveMove(); break;
        case 5: _t->buttonSixMove(); break;
        case 6: _t->buttonSevenMove(); break;
        case 7: _t->buttonEightMove(); break;
        case 8: _t->buttonNineMove(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
