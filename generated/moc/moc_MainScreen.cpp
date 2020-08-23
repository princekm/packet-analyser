/****************************************************************************
** Meta object code from reading C++ file 'MainScreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/screens/MainScreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainScreen_t {
    QByteArrayData data[24];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainScreen_t qt_meta_stringdata_MainScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainScreen"
QT_MOC_LITERAL(1, 11, 11), // "sigSnackBar"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "info"
QT_MOC_LITERAL(4, 29, 5), // "color"
QT_MOC_LITERAL(5, 35, 12), // "sigConnected"
QT_MOC_LITERAL(6, 48, 11), // "slotInspect"
QT_MOC_LITERAL(7, 60, 6), // "turnOn"
QT_MOC_LITERAL(8, 67, 14), // "slotRotateDial"
QT_MOC_LITERAL(9, 82, 12), // "slotCloseApp"
QT_MOC_LITERAL(10, 95, 23), // "slotInterfaceNameNotify"
QT_MOC_LITERAL(11, 119, 13), // "interfaceName"
QT_MOC_LITERAL(12, 133, 16), // "slotAddEditorTab"
QT_MOC_LITERAL(13, 150, 19), // "slotRemoveEditorTab"
QT_MOC_LITERAL(14, 170, 18), // "slotAddCapturesTab"
QT_MOC_LITERAL(15, 189, 20), // "slotGotoInspectorTab"
QT_MOC_LITERAL(16, 210, 22), // "slotRemoveInspectorTab"
QT_MOC_LITERAL(17, 233, 10), // "slotEnable"
QT_MOC_LITERAL(18, 244, 6), // "enable"
QT_MOC_LITERAL(19, 251, 21), // "slotRemoveCapturesTab"
QT_MOC_LITERAL(20, 273, 21), // "slotProcessWorkerInfo"
QT_MOC_LITERAL(21, 295, 7), // "message"
QT_MOC_LITERAL(22, 303, 19), // "Worker::MessageType"
QT_MOC_LITERAL(23, 323, 4) // "type"

    },
    "MainScreen\0sigSnackBar\0\0info\0color\0"
    "sigConnected\0slotInspect\0turnOn\0"
    "slotRotateDial\0slotCloseApp\0"
    "slotInterfaceNameNotify\0interfaceName\0"
    "slotAddEditorTab\0slotRemoveEditorTab\0"
    "slotAddCapturesTab\0slotGotoInspectorTab\0"
    "slotRemoveInspectorTab\0slotEnable\0"
    "enable\0slotRemoveCapturesTab\0"
    "slotProcessWorkerInfo\0message\0"
    "Worker::MessageType\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainScreen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   90,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    1,   95,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    1,  103,    2, 0x08 /* Private */,
      19,    0,  106,    2, 0x08 /* Private */,
      20,    2,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 22,   21,   23,

       0        // eod
};

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSnackBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->sigConnected(); break;
        case 2: _t->slotInspect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slotRotateDial(); break;
        case 4: _t->slotCloseApp(); break;
        case 5: _t->slotInterfaceNameNotify((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slotAddEditorTab(); break;
        case 7: _t->slotRemoveEditorTab(); break;
        case 8: _t->slotAddCapturesTab(); break;
        case 9: _t->slotGotoInspectorTab(); break;
        case 10: _t->slotRemoveInspectorTab(); break;
        case 11: _t->slotEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->slotRemoveCapturesTab(); break;
        case 13: _t->slotProcessWorkerInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Worker::MessageType(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainScreen::*)(QString , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainScreen::sigSnackBar)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainScreen::sigConnected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainScreen::staticMetaObject = { {
    &Widget::staticMetaObject,
    qt_meta_stringdata_MainScreen.data,
    qt_meta_data_MainScreen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainScreen::sigSnackBar(QString _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainScreen::sigConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
