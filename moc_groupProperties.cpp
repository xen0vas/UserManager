/****************************************************************************
** Meta object code from reading C++ file 'groupProperties.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "groupProperties.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupProperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GroupProperties_t {
    QByteArrayData data[9];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupProperties_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupProperties_t qt_meta_stringdata_GroupProperties = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GroupProperties"
QT_MOC_LITERAL(1, 16, 10), // "addMembers"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "removeMembers"
QT_MOC_LITERAL(4, 42, 14), // "checkGroupname"
QT_MOC_LITERAL(5, 57, 4), // "text"
QT_MOC_LITERAL(6, 62, 8), // "checkGID"
QT_MOC_LITERAL(7, 71, 11), // "renameGroup"
QT_MOC_LITERAL(8, 83, 11) // "addNewGroup"

    },
    "GroupProperties\0addMembers\0\0removeMembers\0"
    "checkGroupname\0text\0checkGID\0renameGroup\0"
    "addNewGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupProperties[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Bool,
    QMetaType::Int,

       0        // eod
};

void GroupProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupProperties *_t = static_cast<GroupProperties *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addMembers(); break;
        case 1: _t->removeMembers(); break;
        case 2: _t->checkGroupname((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->checkGID((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->renameGroup();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->addNewGroup();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject GroupProperties::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GroupProperties.data,
      qt_meta_data_GroupProperties,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GroupProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GroupProperties.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::GroupProperties"))
        return static_cast< Ui::GroupProperties*>(this);
    return QDialog::qt_metacast(_clname);
}

int GroupProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
