/****************************************************************************
** Meta object code from reading C++ file 'SettingsWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/widgets/SettingsWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsWidget_t {
    QByteArrayData data[11];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsWidget_t qt_meta_stringdata_SettingsWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingsWidget"
QT_MOC_LITERAL(1, 15, 22), // "sigFetchInterfaceNames"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 20), // "sigInterfaceSelected"
QT_MOC_LITERAL(4, 60, 4), // "name"
QT_MOC_LITERAL(5, 65, 10), // "slotEnable"
QT_MOC_LITERAL(6, 76, 6), // "enable"
QT_MOC_LITERAL(7, 83, 21), // "slotAddInterfaceNames"
QT_MOC_LITERAL(8, 105, 17), // "interfaceNameList"
QT_MOC_LITERAL(9, 123, 27), // "slotDisplayInterfaceDetails"
QT_MOC_LITERAL(10, 151, 4) // "list"

    },
    "SettingsWidget\0sigFetchInterfaceNames\0"
    "\0sigInterfaceSelected\0name\0slotEnable\0"
    "enable\0slotAddInterfaceNames\0"
    "interfaceNameList\0slotDisplayInterfaceDetails\0"
    "list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x08 /* Private */,
       7,    1,   46,    2, 0x08 /* Private */,
       9,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QStringList,    8,
    QMetaType::Void, QMetaType::QStringList,   10,

       0        // eod
};

void SettingsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigFetchInterfaceNames(); break;
        case 1: _t->sigInterfaceSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slotAddInterfaceNames((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->slotDisplayInterfaceDetails((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingsWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWidget::sigFetchInterfaceNames)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SettingsWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWidget::sigInterfaceSelected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SettingsWidget::staticMetaObject = { {
    &Widget::staticMetaObject,
    qt_meta_stringdata_SettingsWidget.data,
    qt_meta_data_SettingsWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWidget.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int SettingsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SettingsWidget::sigFetchInterfaceNames()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SettingsWidget::sigInterfaceSelected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
