/****************************************************************************
** Meta object code from reading C++ file 'editProperties.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editProperties.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editProperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditProperties[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      58,   52,   15,   15, 0x08,
      85,   15,   15,   15, 0x08,
     100,   15,   15,   15, 0x08,
     122,   52,   15,   15, 0x08,
     149,   15,   15,   15, 0x08,
     167,   15,   15,   15, 0x08,
     180,   15,   15,   15, 0x08,
     189,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditProperties[] = {
    "EditProperties\0\0set_Pass_info()\0"
    "ok_to_edit_Button()\0index\0"
    "changeMembers(QModelIndex)\0fillEasyList()\0"
    "easyCheckboxClicked()\0easyAddGroups(QModelIndex)\0"
    "setPrimaryGroup()\0disablechk()\0browse()\0"
    "openHashingAlgorithm()\0"
};

void EditProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditProperties *_t = static_cast<EditProperties *>(_o);
        switch (_id) {
        case 0: _t->set_Pass_info(); break;
        case 1: _t->ok_to_edit_Button(); break;
        case 2: _t->changeMembers((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->fillEasyList(); break;
        case 4: _t->easyCheckboxClicked(); break;
        case 5: _t->easyAddGroups((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->setPrimaryGroup(); break;
        case 7: _t->disablechk(); break;
        case 8: _t->browse(); break;
        case 9: _t->openHashingAlgorithm(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditProperties::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditProperties::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditProperties,
      qt_meta_data_EditProperties, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditProperties::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditProperties))
        return static_cast<void*>(const_cast< EditProperties*>(this));
    if (!strcmp(_clname, "Ui::EditProperties"))
        return static_cast< Ui::EditProperties*>(const_cast< EditProperties*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
