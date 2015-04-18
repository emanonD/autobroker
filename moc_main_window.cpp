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
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      33,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,
     168,   11,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     209,  203,   11,   11, 0x08,
     225,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0setToDate()\0choice()\0"
    "selectFile()\0viewPopup()\0saveInput()\0"
    "editUser()\0changeSave()\0callHistory()\0"
    "viewSpecific()\0detailsPopup()\0"
    "cancelCHPopup()\0cancelPopup()\0uploadP()\0"
    "uploadF()\0addCallPopup()\0index\0"
    "seeDetails(int)\0saveDPopup()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->setToDate(); break;
        case 1: _t->choice(); break;
        case 2: _t->selectFile(); break;
        case 3: _t->viewPopup(); break;
        case 4: _t->saveInput(); break;
        case 5: _t->editUser(); break;
        case 6: _t->changeSave(); break;
        case 7: _t->callHistory(); break;
        case 8: _t->viewSpecific(); break;
        case 9: _t->detailsPopup(); break;
        case 10: _t->cancelCHPopup(); break;
        case 11: _t->cancelPopup(); break;
        case 12: _t->uploadP(); break;
        case 13: _t->uploadF(); break;
        case 14: _t->addCallPopup(); break;
        case 15: _t->seeDetails((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->saveDPopup(); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
