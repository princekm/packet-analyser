/****************************************************************************
** Meta object code from reading C++ file 'ExplorerWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/widgets/ExplorerWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExplorerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExplorerWidget_t {
    QByteArrayData data[20];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExplorerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExplorerWidget_t qt_meta_stringdata_ExplorerWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ExplorerWidget"
QT_MOC_LITERAL(1, 15, 11), // "sigSnackBar"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "color"
QT_MOC_LITERAL(4, 34, 13), // "sigEditPacket"
QT_MOC_LITERAL(5, 48, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 65, 4), // "item"
QT_MOC_LITERAL(7, 70, 6), // "column"
QT_MOC_LITERAL(8, 77, 10), // "sigCapture"
QT_MOC_LITERAL(9, 88, 19), // "slotShowContextMenu"
QT_MOC_LITERAL(10, 108, 3), // "pos"
QT_MOC_LITERAL(11, 112, 11), // "slotAddFile"
QT_MOC_LITERAL(12, 124, 15), // "slotShowAddMenu"
QT_MOC_LITERAL(13, 140, 13), // "slotAddFolder"
QT_MOC_LITERAL(14, 154, 10), // "slotDelete"
QT_MOC_LITERAL(15, 165, 14), // "slotCreateFile"
QT_MOC_LITERAL(16, 180, 4), // "name"
QT_MOC_LITERAL(17, 185, 17), // "slotEnableButtons"
QT_MOC_LITERAL(18, 203, 14), // "slotEditPacket"
QT_MOC_LITERAL(19, 218, 11) // "slotCapture"

    },
    "ExplorerWidget\0sigSnackBar\0\0color\0"
    "sigEditPacket\0QTreeWidgetItem*\0item\0"
    "column\0sigCapture\0slotShowContextMenu\0"
    "pos\0slotAddFile\0slotShowAddMenu\0"
    "slotAddFolder\0slotDelete\0slotCreateFile\0"
    "name\0slotEnableButtons\0slotEditPacket\0"
    "slotCapture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExplorerWidget[] = {

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
       1,    2,   74,    2, 0x06 /* Public */,
       4,    2,   79,    2, 0x06 /* Public */,
       8,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   85,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    1,   92,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,
      18,    2,   96,    2, 0x08 /* Private */,
      19,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    2,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,

       0        // eod
};

void ExplorerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExplorerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSnackBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->sigEditPacket((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sigCapture(); break;
        case 3: _t->slotShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->slotAddFile(); break;
        case 5: _t->slotShowAddMenu(); break;
        case 6: _t->slotAddFolder(); break;
        case 7: _t->slotDelete(); break;
        case 8: _t->slotCreateFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slotEnableButtons(); break;
        case 10: _t->slotEditPacket((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->slotCapture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExplorerWidget::*)(QString , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigSnackBar)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ExplorerWidget::*)(QTreeWidgetItem * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigEditPacket)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ExplorerWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigCapture)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ExplorerWidget::staticMetaObject = { {
    &Widget::staticMetaObject,
    qt_meta_stringdata_ExplorerWidget.data,
    qt_meta_data_ExplorerWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ExplorerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExplorerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExplorerWidget.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int ExplorerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ExplorerWidget::sigSnackBar(QString _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExplorerWidget::sigEditPacket(QTreeWidgetItem * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ExplorerWidget::sigCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
