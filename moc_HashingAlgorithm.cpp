/****************************************************************************
** Meta object code from reading C++ file 'HashingAlgorithm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "HashingAlgorithm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HashingAlgorithm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HashingAlgorithm_t {
    QByteArrayData data[7];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HashingAlgorithm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HashingAlgorithm_t qt_meta_stringdata_HashingAlgorithm = {
    {
QT_MOC_LITERAL(0, 0, 16), // "HashingAlgorithm"
QT_MOC_LITERAL(1, 17, 19), // "setHashingAlgorithm"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 18), // "getSha256IsChecked"
QT_MOC_LITERAL(4, 57, 18), // "getSha512IsChecked"
QT_MOC_LITERAL(5, 76, 15), // "getMd5IsChecked"
QT_MOC_LITERAL(6, 92, 16) // "getBlowIsChecked"

    },
    "HashingAlgorithm\0setHashingAlgorithm\0"
    "\0getSha256IsChecked\0getSha512IsChecked\0"
    "getMd5IsChecked\0getBlowIsChecked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HashingAlgorithm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void HashingAlgorithm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HashingAlgorithm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHashingAlgorithm(); break;
        case 1: { bool _r = _t->getSha256IsChecked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->getSha512IsChecked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->getMd5IsChecked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->getBlowIsChecked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HashingAlgorithm::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_HashingAlgorithm.data,
    qt_meta_data_HashingAlgorithm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HashingAlgorithm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HashingAlgorithm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HashingAlgorithm.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::HashingAlgorithm"))
        return static_cast< Ui::HashingAlgorithm*>(this);
    return QDialog::qt_metacast(_clname);
}

int HashingAlgorithm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
