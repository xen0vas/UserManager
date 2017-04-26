/****************************************************************************
** Meta object code from reading C++ file 'userproperties.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userproperties.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userproperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserProperties[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      31,   15,   15,   15, 0x0a,
      53,   15,   15,   15, 0x0a,
      67,   15,   15,   15, 0x0a,
      81,   15,   15,   15, 0x0a,
      98,   92,   15,   15, 0x0a,
     125,   92,   15,   15, 0x0a,
     152,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UserProperties[] = {
    "UserProperties\0\0fillEasyList()\0"
    "easyCheckboxClicked()\0addUserBase()\0"
    "setPassword()\0disCheck()\0index\0"
    "easyAddGroups(QModelIndex)\0"
    "changeMembers(QModelIndex)\0setPrimaryGroup()\0"
};

void UserProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserProperties *_t = static_cast<UserProperties *>(_o);
        switch (_id) {
        case 0: _t->fillEasyList(); break;
        case 1: _t->easyCheckboxClicked(); break;
        case 2: _t->addUserBase(); break;
        case 3: _t->setPassword(); break;
        case 4: _t->disCheck(); break;
        case 5: _t->easyAddGroups((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->changeMembers((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->setPrimaryGroup(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UserProperties::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserProperties::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserProperties,
      qt_meta_data_UserProperties, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserProperties::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserProperties))
        return static_cast<void*>(const_cast< UserProperties*>(this));
    if (!strcmp(_clname, "Ui::UserProperties"))
        return static_cast< Ui::UserProperties*>(const_cast< UserProperties*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
