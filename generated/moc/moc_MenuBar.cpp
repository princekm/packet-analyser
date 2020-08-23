/****************************************************************************
** Meta object code from reading C++ file 'MenuBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/widgets/MenuBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuBar_t {
    QByteArrayData data[11];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuBar_t qt_meta_stringdata_MenuBar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MenuBar"
QT_MOC_LITERAL(1, 8, 18), // "sigShowAboutDialog"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "sigSaveFile"
QT_MOC_LITERAL(4, 40, 8), // "fileName"
QT_MOC_LITERAL(5, 49, 11), // "sigSnackBar"
QT_MOC_LITERAL(6, 61, 7), // "message"
QT_MOC_LITERAL(7, 69, 5), // "color"
QT_MOC_LITERAL(8, 75, 14), // "slotEnableSave"
QT_MOC_LITERAL(9, 90, 6), // "enable"
QT_MOC_LITERAL(10, 97, 12) // "slotSaveFile"

    },
    "MenuBar\0sigShowAboutDialog\0\0sigSaveFile\0"
    "fileName\0sigSnackBar\0message\0color\0"
    "slotEnableSave\0enable\0slotSaveFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,
       5,    2,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   48,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void MenuBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigShowAboutDialog(); break;
        case 1: _t->sigSaveFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigSnackBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 3: _t->slotEnableSave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slotSaveFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MenuBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuBar::sigShowAboutDialog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MenuBar::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuBar::sigSaveFile)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MenuBar::*)(QString , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuBar::sigSnackBar)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MenuBar::staticMetaObject = { {
    &QMenuBar::staticMetaObject,
    qt_meta_stringdata_MenuBar.data,
    qt_meta_data_MenuBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuBar.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int MenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
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
void MenuBar::sigShowAboutDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MenuBar::sigSaveFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MenuBar::sigSnackBar(QString _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
