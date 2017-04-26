/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
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
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      39,   35,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,
     226,  220,   11,   11, 0x08,
     265,  252,   11,   11, 0x08,
     292,  220,   11,   11, 0x08,
     325,  220,   11,   11, 0x08,
     359,   11,   11,   11, 0x08,
     376,   11,   11,   11, 0x08,
     398,   11,   11,   11, 0x08,
     415,   11,  411,   11, 0x08,
     429,   11,   11,   11, 0x08,
     440,   11,   11,   11, 0x08,
     452,   11,   11,   11, 0x08,
     480,   11,   11,   11, 0x08,
     495,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0reloadUsersAndGroups()\0"
    "tab\0tabChanged(int)\0aboutUserManager()\0"
    "folderSizeCheckBoxClicked()\0"
    "addGroupBtnClicked()\0set_Pass_Menu()\0"
    "searchUserBtnClicked()\0addUserBtnClicked()\0"
    "searchGroupBtnClicked()\0UserDetails()\0"
    "index\0GroupDetails(QModelIndex)\0"
    "tree,columns\0beautyTree(QTreeView*,int)\0"
    "getSelectedUserInfo(QModelIndex)\0"
    "getSelectedGroupInfo(QModelIndex)\0"
    "clearEditBoxes()\0calculateFolderSize()\0"
    "deleteUser()\0int\0deleteGroup()\0"
    "EditUser()\0editGroup()\0"
    "getEditDetails(QModelIndex)\0openSettings()\0"
    "createBackup()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->reloadUsersAndGroups(); break;
        case 1: _t->tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->aboutUserManager(); break;
        case 3: _t->folderSizeCheckBoxClicked(); break;
        case 4: _t->addGroupBtnClicked(); break;
        case 5: _t->set_Pass_Menu(); break;
        case 6: _t->searchUserBtnClicked(); break;
        case 7: _t->addUserBtnClicked(); break;
        case 8: _t->searchGroupBtnClicked(); break;
        case 9: _t->UserDetails(); break;
        case 10: _t->GroupDetails((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->beautyTree((*reinterpret_cast< QTreeView*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->getSelectedUserInfo((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->getSelectedGroupInfo((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->clearEditBoxes(); break;
        case 15: _t->calculateFolderSize(); break;
        case 16: _t->deleteUser(); break;
        case 17: { int _r = _t->deleteGroup();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 18: _t->EditUser(); break;
        case 19: _t->editGroup(); break;
        case 20: _t->getEditDetails((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 21: _t->openSettings(); break;
        case 22: _t->createBackup(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
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
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
