/****************************************************************************
** Meta object code from reading C++ file 'CaptureWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
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
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CaptureWidget_t {
    QByteArrayData data[31];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CaptureWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CaptureWidget_t qt_meta_stringdata_CaptureWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CaptureWidget"
QT_MOC_LITERAL(1, 14, 9), // "sigEnable"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "enable"
QT_MOC_LITERAL(4, 32, 10), // "sigPayload"
QT_MOC_LITERAL(5, 43, 6), // "uchar*"
QT_MOC_LITERAL(6, 50, 4), // "data"
QT_MOC_LITERAL(7, 55, 3), // "len"
QT_MOC_LITERAL(8, 59, 13), // "sigBusySignal"
QT_MOC_LITERAL(9, 73, 15), // "sigStartCapture"
QT_MOC_LITERAL(10, 89, 14), // "sigStopCapture"
QT_MOC_LITERAL(11, 104, 9), // "sigFilter"
QT_MOC_LITERAL(12, 114, 12), // "filterString"
QT_MOC_LITERAL(13, 127, 16), // "sigInspectPacket"
QT_MOC_LITERAL(14, 144, 10), // "packetName"
QT_MOC_LITERAL(15, 155, 20), // "slotSetInterfaceName"
QT_MOC_LITERAL(16, 176, 4), // "name"
QT_MOC_LITERAL(17, 181, 18), // "slotSetPacketCount"
QT_MOC_LITERAL(18, 200, 19), // "slotDisplayCaptured"
QT_MOC_LITERAL(19, 220, 18), // "const pcap_pkthdr*"
QT_MOC_LITERAL(20, 239, 6), // "pkthdr"
QT_MOC_LITERAL(21, 246, 20), // "const unsigned char*"
QT_MOC_LITERAL(22, 267, 6), // "packet"
QT_MOC_LITERAL(23, 274, 13), // "slotStartStop"
QT_MOC_LITERAL(24, 288, 14), // "slotClearTable"
QT_MOC_LITERAL(25, 303, 13), // "slotClearInfo"
QT_MOC_LITERAL(26, 317, 10), // "slotFilter"
QT_MOC_LITERAL(27, 328, 15), // "slotFilterReady"
QT_MOC_LITERAL(28, 344, 2), // "ok"
QT_MOC_LITERAL(29, 347, 14), // "slotRowClicked"
QT_MOC_LITERAL(30, 362, 19) // "slotResetFilterEdit"

    },
    "CaptureWidget\0sigEnable\0\0enable\0"
    "sigPayload\0uchar*\0data\0len\0sigBusySignal\0"
    "sigStartCapture\0sigStopCapture\0sigFilter\0"
    "filterString\0sigInspectPacket\0packetName\0"
    "slotSetInterfaceName\0name\0slotSetPacketCount\0"
    "slotDisplayCaptured\0const pcap_pkthdr*\0"
    "pkthdr\0const unsigned char*\0packet\0"
    "slotStartStop\0slotClearTable\0slotClearInfo\0"
    "slotFilter\0slotFilterReady\0ok\0"
    "slotRowClicked\0slotResetFilterEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CaptureWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    2,  102,    2, 0x06 /* Public */,
       8,    0,  107,    2, 0x06 /* Public */,
       9,    0,  108,    2, 0x06 /* Public */,
      10,    0,  109,    2, 0x06 /* Public */,
      11,    1,  110,    2, 0x06 /* Public */,
      13,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  116,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    2,  120,    2, 0x08 /* Private */,
      23,    0,  125,    2, 0x08 /* Private */,
      24,    0,  126,    2, 0x08 /* Private */,
      25,    0,  127,    2, 0x08 /* Private */,
      26,    0,  128,    2, 0x08 /* Private */,
      27,    1,  129,    2, 0x08 /* Private */,
      29,    1,  132,    2, 0x08 /* Private */,
      30,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21,   20,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void CaptureWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sigPayload((*reinterpret_cast< uchar*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sigBusySignal(); break;
        case 3: _t->sigStartCapture(); break;
        case 4: _t->sigStopCapture(); break;
        case 5: _t->sigFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sigInspectPacket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slotSetInterfaceName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slotSetPacketCount(); break;
        case 9: _t->slotDisplayCaptured((*reinterpret_cast< const pcap_pkthdr*(*)>(_a[1])),(*reinterpret_cast< const unsigned char*(*)>(_a[2]))); break;
        case 10: _t->slotStartStop(); break;
        case 11: _t->slotClearTable(); break;
        case 12: _t->slotClearInfo(); break;
        case 13: _t->slotFilter(); break;
        case 14: _t->slotFilterReady((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->slotRowClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->slotResetFilterEdit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CaptureWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigEnable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)(uchar * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigPayload)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigBusySignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigStartCapture)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigStopCapture)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigFilter)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CaptureWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CaptureWidget::sigInspectPacket)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CaptureWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<Widget::staticMetaObject>(),
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void CaptureWidget::sigEnable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CaptureWidget::sigPayload(uchar * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CaptureWidget::sigBusySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CaptureWidget::sigStartCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CaptureWidget::sigStopCapture()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CaptureWidget::sigFilter(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CaptureWidget::sigInspectPacket(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
