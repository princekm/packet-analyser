/****************************************************************************
** Meta object code from reading C++ file 'InspectorWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/widgets/InspectorWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InspectorWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InspectorWidget_t {
    QByteArrayData data[25];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InspectorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InspectorWidget_t qt_meta_stringdata_InspectorWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "InspectorWidget"
QT_MOC_LITERAL(1, 16, 10), // "sigInspect"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "turnOn"
QT_MOC_LITERAL(4, 35, 18), // "sigRequestFileList"
QT_MOC_LITERAL(5, 54, 11), // "sigSnackBar"
QT_MOC_LITERAL(6, 66, 18), // "slotAddPacketTypes"
QT_MOC_LITERAL(7, 85, 10), // "packetType"
QT_MOC_LITERAL(8, 96, 21), // "slotDeletePacketTypes"
QT_MOC_LITERAL(9, 118, 16), // "slotPopulateTree"
QT_MOC_LITERAL(10, 135, 8), // "fileName"
QT_MOC_LITERAL(11, 144, 18), // "slotUpdateFileList"
QT_MOC_LITERAL(12, 163, 8), // "fileList"
QT_MOC_LITERAL(13, 172, 11), // "slotPayload"
QT_MOC_LITERAL(14, 184, 6), // "uchar*"
QT_MOC_LITERAL(15, 191, 4), // "data"
QT_MOC_LITERAL(16, 196, 3), // "len"
QT_MOC_LITERAL(17, 200, 13), // "slotStartStop"
QT_MOC_LITERAL(18, 214, 11), // "slotDisable"
QT_MOC_LITERAL(19, 226, 21), // "slotItemDoubleClicked"
QT_MOC_LITERAL(20, 248, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(21, 265, 4), // "item"
QT_MOC_LITERAL(22, 270, 6), // "column"
QT_MOC_LITERAL(23, 277, 16), // "slotChangeFormat"
QT_MOC_LITERAL(24, 294, 6) // "format"

    },
    "InspectorWidget\0sigInspect\0\0turnOn\0"
    "sigRequestFileList\0sigSnackBar\0"
    "slotAddPacketTypes\0packetType\0"
    "slotDeletePacketTypes\0slotPopulateTree\0"
    "fileName\0slotUpdateFileList\0fileList\0"
    "slotPayload\0uchar*\0data\0len\0slotStartStop\0"
    "slotDisable\0slotItemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "slotChangeFormat\0format"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InspectorWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,
       5,    2,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
       9,    1,   89,    2, 0x08 /* Private */,
      11,    1,   92,    2, 0x08 /* Private */,
      13,    2,   95,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    1,  101,    2, 0x08 /* Private */,
      19,    2,  104,    2, 0x08 /* Private */,
      23,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int,   15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Int,   21,   22,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

void InspectorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InspectorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigInspect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sigRequestFileList(); break;
        case 2: _t->sigSnackBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 3: _t->slotAddPacketTypes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotDeletePacketTypes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotPopulateTree((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slotUpdateFileList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 7: _t->slotPayload((*reinterpret_cast< uchar*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->slotStartStop(); break;
        case 9: _t->slotDisable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->slotItemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->slotChangeFormat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InspectorWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InspectorWidget::sigInspect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InspectorWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InspectorWidget::sigRequestFileList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InspectorWidget::*)(QString , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InspectorWidget::sigSnackBar)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InspectorWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<Widget::staticMetaObject>(),
    qt_meta_stringdata_InspectorWidget.data,
    qt_meta_data_InspectorWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InspectorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InspectorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InspectorWidget.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int InspectorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void InspectorWidget::sigInspect(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InspectorWidget::sigRequestFileList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void InspectorWidget::sigSnackBar(QString _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
