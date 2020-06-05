/****************************************************************************
** Meta object code from reading C++ file 'editProperties.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editProperties.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editProperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditProperties_t {
    QByteArrayData data[14];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditProperties_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditProperties_t qt_meta_stringdata_EditProperties = {
    {
QT_MOC_LITERAL(0, 0, 14), // "EditProperties"
QT_MOC_LITERAL(1, 15, 13), // "set_Pass_info"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "ok_to_edit_Button"
QT_MOC_LITERAL(4, 48, 13), // "changeMembers"
QT_MOC_LITERAL(5, 62, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 74, 5), // "index"
QT_MOC_LITERAL(7, 80, 12), // "fillEasyList"
QT_MOC_LITERAL(8, 93, 19), // "easyCheckboxClicked"
QT_MOC_LITERAL(9, 113, 13), // "easyAddGroups"
QT_MOC_LITERAL(10, 127, 15), // "setPrimaryGroup"
QT_MOC_LITERAL(11, 143, 10), // "disablechk"
QT_MOC_LITERAL(12, 154, 6), // "browse"
QT_MOC_LITERAL(13, 161, 20) // "openHashingAlgorithm"

    },
    "EditProperties\0set_Pass_info\0\0"
    "ok_to_edit_Button\0changeMembers\0"
    "QModelIndex\0index\0fillEasyList\0"
    "easyCheckboxClicked\0easyAddGroups\0"
    "setPrimaryGroup\0disablechk\0browse\0"
    "openHashingAlgorithm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditProperties[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditProperties *>(_o);
        Q_UNUSED(_t)
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

QT_INIT_METAOBJECT const QMetaObject EditProperties::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_EditProperties.data,
    qt_meta_data_EditProperties,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditProperties.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::EditProperties"))
        return static_cast< Ui::EditProperties*>(this);
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
