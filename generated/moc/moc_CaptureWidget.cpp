/****************************************************************************
** Meta object code from reading C++ file 'CaptureWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ui/widgets/CaptureWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CaptureWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureWidget_t {
    QByteArrayData data[18];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CaptureWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CaptureWidget_t qt_meta_stringdata_CaptureWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CaptureWidget"
QT_MOC_LITERAL(1, 14, 15), // "sigStartCapture"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "sigStopCapture"
QT_MOC_LITERAL(4, 46, 16), // "sigInspectPacket"
QT_MOC_LITERAL(5, 63, 10), // "packetName"
QT_MOC_LITERAL(6, 74, 20), // "slotSetInterfaceName"
QT_MOC_LITERAL(7, 95, 4), // "name"
QT_MOC_LITERAL(8, 100, 18), // "slotSetPacketCount"
QT_MOC_LITERAL(9, 119, 19), // "slotDisplayCaptured"
QT_MOC_LITERAL(10, 139, 18), // "const pcap_pkthdr*"
QT_MOC_LITERAL(11, 158, 6), // "pkthdr"
QT_MOC_LITERAL(12, 165, 20), // "const unsigned char*"
QT_MOC_LITERAL(13, 186, 6), // "packet"
QT_MOC_LITERAL(14, 193, 13), // "slotStartStop"
QT_MOC_LITERAL(15, 207, 14), // "slotClearTable"
QT_MOC_LITERAL(16, 222, 13), // "slotClearInfo"
QT_MOC_LITERAL(17, 236, 14) // "slotRowClicked"

    },
    "CaptureWidget\0sigStartCapture\0\0"
    "sigStopCapture\0sigInspectPacket\0"
    "packetName\0slotSetInterfaceName\0name\0"
    "slotSetPacketCount\0slotDisplayCaptured\0"
    "const pcap_pkthdr*\0pkthdr\0"
    "const unsigned char*\0packet\0slotStartStop\0"
    "slotClearTable\0slotClearInfo\0"
    "slotRowClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   69,    2, 0x08 /* Private */,
       8,    0,   72,    2, 0x08 /* Private */,
       9,    2,   73,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    0,   79,    2, 0x08 /* Private */,
      16,    0,   80,    2, 0x08 /* Private */,
      17,    1,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void CaptureWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigStartCapture(); break;
        case 1: _t->sigStopCapture(); break;
        case 2: _t->sigInspectPacket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotSetInterfaceName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotSetPacketCount(); break;
        case 5: _t->slotDisplayCaptured((*reinterpret_cast< const pcap_pkthdr*(*)>(_a[1])),(*reinterpret_cast< const unsigned char*(*)>(_a[2]))); break;
        case 6: _t->slotStartStop(); break;
        case 7: _t->slotClearTable(); break;
        case 8: _t->slotClearInfo(); break;
        case 9: _t->slotRowClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaptureWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigStartCapture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigStopCapture)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigInspectPacket)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CaptureWidget::staticMetaObject = { {
    &Widget::staticMetaObject,
    qt_meta_stringdata_CaptureWidget.data,
    qt_meta_data_CaptureWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CaptureWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureWidget.stringdata0))
        return static_cast<void*>(this);
    return Widget::qt_metacast(_clname);
}

int CaptureWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CaptureWidget::sigStartCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CaptureWidget::sigStopCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CaptureWidget::sigInspectPacket(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
