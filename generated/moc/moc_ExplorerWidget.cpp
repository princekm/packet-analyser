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
    QByteArrayData data[29];
    char stringdata0[362];
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
QT_MOC_LITERAL(8, 77, 19), // "sigAddCapturePacket"
QT_MOC_LITERAL(9, 97, 8), // "fileName"
QT_MOC_LITERAL(10, 106, 12), // "sigFileAdded"
QT_MOC_LITERAL(11, 119, 4), // "name"
QT_MOC_LITERAL(12, 124, 14), // "sigFileDeleted"
QT_MOC_LITERAL(13, 139, 15), // "sigEmitFileList"
QT_MOC_LITERAL(14, 155, 8), // "fileList"
QT_MOC_LITERAL(15, 164, 10), // "sigCapture"
QT_MOC_LITERAL(16, 175, 19), // "slotShowContextMenu"
QT_MOC_LITERAL(17, 195, 3), // "pos"
QT_MOC_LITERAL(18, 199, 11), // "slotAddFile"
QT_MOC_LITERAL(19, 211, 15), // "slotShowAddMenu"
QT_MOC_LITERAL(20, 227, 13), // "slotAddFolder"
QT_MOC_LITERAL(21, 241, 10), // "slotDelete"
QT_MOC_LITERAL(22, 252, 14), // "slotCreateFile"
QT_MOC_LITERAL(23, 267, 17), // "slotEnableButtons"
QT_MOC_LITERAL(24, 285, 14), // "slotEditPacket"
QT_MOC_LITERAL(25, 300, 11), // "slotCapture"
QT_MOC_LITERAL(26, 312, 18), // "slotUpdateFileSize"
QT_MOC_LITERAL(27, 331, 4), // "size"
QT_MOC_LITERAL(28, 336, 25) // "slotHandleRequestFileList"

    },
    "ExplorerWidget\0sigSnackBar\0\0color\0"
    "sigEditPacket\0QTreeWidgetItem*\0item\0"
    "column\0sigAddCapturePacket\0fileName\0"
    "sigFileAdded\0name\0sigFileDeleted\0"
    "sigEmitFileList\0fileList\0sigCapture\0"
    "slotShowContextMenu\0pos\0slotAddFile\0"
    "slotShowAddMenu\0slotAddFolder\0slotDelete\0"
    "slotCreateFile\0slotEnableButtons\0"
    "slotEditPacket\0slotCapture\0"
    "slotUpdateFileSize\0size\0"
    "slotHandleRequestFileList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExplorerWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  104,    2, 0x06 /* Public */,
       4,    2,  109,    2, 0x06 /* Public */,
       8,    1,  114,    2, 0x06 /* Public */,
      10,    1,  117,    2, 0x06 /* Public */,
      12,    1,  120,    2, 0x06 /* Public */,
      13,    1,  123,    2, 0x06 /* Public */,
      15,    0,  126,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,  127,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    0,  131,    2, 0x08 /* Private */,
      20,    0,  132,    2, 0x08 /* Private */,
      21,    0,  133,    2, 0x08 /* Private */,
      22,    1,  134,    2, 0x08 /* Private */,
      23,    0,  137,    2, 0x08 /* Private */,
      24,    2,  138,    2, 0x08 /* Private */,
      25,    0,  143,    2, 0x08 /* Private */,
      26,    1,  144,    2, 0x08 /* Private */,
      28,    0,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    2,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QStringList,   14,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
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
        case 2: _t->sigAddCapturePacket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigFileAdded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sigFileDeleted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sigEmitFileList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: _t->sigCapture(); break;
        case 7: _t->slotShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->slotAddFile(); break;
        case 9: _t->slotShowAddMenu(); break;
        case 10: _t->slotAddFolder(); break;
        case 11: _t->slotDelete(); break;
        case 12: _t->slotCreateFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slotEnableButtons(); break;
        case 14: _t->slotEditPacket((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->slotCapture(); break;
        case 16: _t->slotUpdateFileSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->slotHandleRequestFileList(); break;
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
            using _t = void (ExplorerWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigAddCapturePacket)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ExplorerWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigFileAdded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ExplorerWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigFileDeleted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ExplorerWidget::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigEmitFileList)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ExplorerWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExplorerWidget::sigCapture)) {
                *result = 6;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
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
void ExplorerWidget::sigAddCapturePacket(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ExplorerWidget::sigFileAdded(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ExplorerWidget::sigFileDeleted(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ExplorerWidget::sigEmitFileList(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ExplorerWidget::sigCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE