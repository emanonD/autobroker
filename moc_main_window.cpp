/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     118,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     141,   11,   11,   11, 0x08,
     162,  156,   11,   11, 0x08,
     181,  156,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0selectFile()\0viewPopup()\0"
    "saveInput()\0saveInput2()\0deleteLead()\0"
    "deleteCustomer()\0editUser()\0editCustomer()\0"
    "reminder()\0showPopup()\0newUserPopup()\0"
    "index\0popUpModifier(int)\0popUpModifier2(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->selectFile(); break;
        case 1: _t->viewPopup(); break;
        case 2: _t->saveInput(); break;
        case 3: _t->saveInput2(); break;
        case 4: _t->deleteLead(); break;
        case 5: _t->deleteCustomer(); break;
        case 6: _t->editUser(); break;
        case 7: _t->editCustomer(); break;
        case 8: _t->reminder(); break;
        case 9: _t->showPopup(); break;
        case 10: _t->newUserPopup(); break;
        case 11: _t->popUpModifier((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->popUpModifier2((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
