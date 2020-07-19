/****************************************************************************
** Meta object code from reading C++ file 'PacketEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/widgets/PacketEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PacketEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketEditor_t {
    QByteArrayData data[25];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PacketEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PacketEditor_t qt_meta_stringdata_PacketEditor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PacketEditor"
QT_MOC_LITERAL(1, 13, 11), // "sigSnackBar"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "string"
QT_MOC_LITERAL(4, 33, 5), // "color"
QT_MOC_LITERAL(5, 39, 8), // "slotSave"
QT_MOC_LITERAL(6, 48, 10), // "slotDelete"
QT_MOC_LITERAL(7, 59, 18), // "slotHandleDataType"
QT_MOC_LITERAL(8, 78, 10), // "TypeObject"
QT_MOC_LITERAL(9, 89, 10), // "typeObject"
QT_MOC_LITERAL(10, 100, 20), // "slotHandleObjectType"
QT_MOC_LITERAL(11, 121, 6), // "Object"
QT_MOC_LITERAL(12, 128, 19), // "slotHandleArrayType"
QT_MOC_LITERAL(13, 148, 15), // "ArrayTypeObject"
QT_MOC_LITERAL(14, 164, 14), // "slotEditPacket"
QT_MOC_LITERAL(15, 179, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(16, 196, 4), // "item"
QT_MOC_LITERAL(17, 201, 6), // "column"
QT_MOC_LITERAL(18, 208, 17), // "slotEnableButtons"
QT_MOC_LITERAL(19, 226, 16), // "slotShowAddMenus"
QT_MOC_LITERAL(20, 243, 19), // "slotShowContextMenu"
QT_MOC_LITERAL(21, 263, 3), // "pos"
QT_MOC_LITERAL(22, 267, 15), // "slotCreateArray"
QT_MOC_LITERAL(23, 283, 16), // "slotCreateObject"
QT_MOC_LITERAL(24, 300, 14) // "slotCreateType"

    },
    "PacketEditor\0sigSnackBar\0\0string\0color\0"
    "slotSave\0slotDelete\0slotHandleDataType\0"
    "TypeObject\0typeObject\0slotHandleObjectType\0"
    "Object\0slotHandleArrayType\0ArrayTypeObject\0"
    "slotEditPacket\0QTreeWidgetItem*\0item\0"
    "column\0slotEnableButtons\0slotShowAddMenus\0"
    "slotShowContextMenu\0pos\0slotCreateArray\0"
    "slotCreateObject\0slotCreateType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   84,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    1,   86,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      14,    2,   95,    2, 0x08 /* Private */,
      18,    0,  100,    2, 0x08 /* Private */,
      19,    0,  101,    2, 0x08 /* Private */,
      20,    1,  102,    2, 0x08 /* Private */,
      22,    0,  105,    2, 0x08 /* Private */,
      23,    0,  106,    2, 0x08 /* Private */,
      24,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 13,    9,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PacketEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PacketEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSnackBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->slotSave(); break;
        case 2: _t->slotDelete(); break;
        case 3: _t->slotHandleDataType((*reinterpret_cast< TypeObject(*)>(_a[1]))); break;
        case 4: _t->slotHandleObjectType((*reinterpret_cast< Object(*)>(_a[1]))); break;
        case 5: _t->slotHandleArrayType((*reinterpret_cast< ArrayTypeObject(*)>(_a[1]))); break;
        case 6: _t->slotEditPacket((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slotEnableButtons(); break;
        case 8: _t->slotShowAddMenus(); break;
        case 9: _t->slotShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->slotCreateArray(); break;
        case 11: _t->slotCreateObject(); break;
        case 12: _t->slotCreateType(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PacketEditor::*)(QString , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketEditor::sigSnackBar)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PacketEditor::staticMetaObject = { {
    &Widget::staticMetaObject,
    qt_meta_stringdata_PacketEditor.data,
    qt_meta_data_PacketEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PacketEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketEditor.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int PacketEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void PacketEditor::sigSnackBar(QString _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
