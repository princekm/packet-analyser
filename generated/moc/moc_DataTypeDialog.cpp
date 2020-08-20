/****************************************************************************
** Meta object code from reading C++ file 'DataTypeDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/dialogs/DataTypeDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataTypeDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataTypeDialog_t {
    QByteArrayData data[9];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataTypeDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataTypeDialog_t qt_meta_stringdata_DataTypeDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataTypeDialog"
QT_MOC_LITERAL(1, 15, 12), // "sigLoadTypes"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 7), // "sigData"
QT_MOC_LITERAL(4, 37, 10), // "TypeObject"
QT_MOC_LITERAL(5, 48, 6), // "object"
QT_MOC_LITERAL(6, 55, 17), // "slotSetSizeOfType"
QT_MOC_LITERAL(7, 73, 4), // "text"
QT_MOC_LITERAL(8, 78, 13) // "slotProcessOk"

    },
    "DataTypeDialog\0sigLoadTypes\0\0sigData\0"
    "TypeObject\0object\0slotSetSizeOfType\0"
    "text\0slotProcessOk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataTypeDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   38,    2, 0x08 /* Private */,
       8,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void DataTypeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataTypeDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLoadTypes(); break;
        case 1: _t->sigData((*reinterpret_cast< TypeObject(*)>(_a[1]))); break;
        case 2: _t->slotSetSizeOfType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotProcessOk(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataTypeDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataTypeDialog::sigLoadTypes)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataTypeDialog::*)(TypeObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataTypeDialog::sigData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataTypeDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<ObjectTypeDialog::staticMetaObject>(),
    qt_meta_stringdata_DataTypeDialog.data,
    qt_meta_data_DataTypeDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataTypeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataTypeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataTypeDialog.stringdata0))
        return static_cast<void*>(this);
    return ObjectTypeDialog::qt_metacast(_clname);
}

int DataTypeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ObjectTypeDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DataTypeDialog::sigLoadTypes()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataTypeDialog::sigData(TypeObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
