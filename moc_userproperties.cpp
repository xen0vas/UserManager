/****************************************************************************
** Meta object code from reading C++ file 'userproperties.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userproperties.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userproperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserProperties_t {
    QByteArrayData data[11];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserProperties_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserProperties_t qt_meta_stringdata_UserProperties = {
    {
QT_MOC_LITERAL(0, 0, 14), // "UserProperties"
QT_MOC_LITERAL(1, 15, 20), // "openHashingAlgorithm"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "fillEasyList"
QT_MOC_LITERAL(4, 50, 19), // "easyCheckboxClicked"
QT_MOC_LITERAL(5, 70, 11), // "addUserBase"
QT_MOC_LITERAL(6, 82, 15), // "setFormContents"
QT_MOC_LITERAL(7, 98, 13), // "easyAddGroups"
QT_MOC_LITERAL(8, 112, 5), // "index"
QT_MOC_LITERAL(9, 118, 13), // "changeMembers"
QT_MOC_LITERAL(10, 132, 15) // "setPrimaryGroup"

    },
    "UserProperties\0openHashingAlgorithm\0"
    "\0fillEasyList\0easyCheckboxClicked\0"
    "addUserBase\0setFormContents\0easyAddGroups\0"
    "index\0changeMembers\0setPrimaryGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserProperties[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,

       0        // eod
};

void UserProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserProperties *_t = static_cast<UserProperties *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openHashingAlgorithm(); break;
        case 1: _t->fillEasyList(); break;
        case 2: _t->easyCheckboxClicked(); break;
        case 3: _t->addUserBase(); break;
        case 4: _t->setFormContents(); break;
        case 5: _t->easyAddGroups((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->changeMembers((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->setPrimaryGroup(); break;
        default: ;
        }
    }
}

const QMetaObject UserProperties::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserProperties.data,
      qt_meta_data_UserProperties,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserProperties.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::UserProperties"))
        return static_cast< Ui::UserProperties*>(this);
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
