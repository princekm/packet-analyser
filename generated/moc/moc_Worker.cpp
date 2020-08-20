/****************************************************************************
** Meta object code from reading C++ file 'Worker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../engine/Worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Worker_t {
    QByteArrayData data[32];
    char stringdata0[415];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Worker_t qt_meta_stringdata_Worker = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Worker"
QT_MOC_LITERAL(1, 7, 8), // "sigReady"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 11), // "sigFiltered"
QT_MOC_LITERAL(4, 29, 5), // "error"
QT_MOC_LITERAL(5, 35, 15), // "sigCaptureReady"
QT_MOC_LITERAL(6, 51, 10), // "deviceName"
QT_MOC_LITERAL(7, 62, 11), // "sigProgress"
QT_MOC_LITERAL(8, 74, 10), // "percentage"
QT_MOC_LITERAL(9, 85, 16), // "sigInterfaceList"
QT_MOC_LITERAL(10, 102, 17), // "interfaceNameList"
QT_MOC_LITERAL(11, 120, 11), // "sigFinished"
QT_MOC_LITERAL(12, 132, 7), // "sigInfo"
QT_MOC_LITERAL(13, 140, 19), // "Worker::MessageType"
QT_MOC_LITERAL(14, 160, 11), // "sigCaptured"
QT_MOC_LITERAL(15, 172, 18), // "const pcap_pkthdr*"
QT_MOC_LITERAL(16, 191, 6), // "pkthdr"
QT_MOC_LITERAL(17, 198, 20), // "const unsigned char*"
QT_MOC_LITERAL(18, 219, 6), // "packet"
QT_MOC_LITERAL(19, 226, 20), // "sigEmitDeviceDetails"
QT_MOC_LITERAL(20, 247, 4), // "list"
QT_MOC_LITERAL(21, 252, 9), // "slotParse"
QT_MOC_LITERAL(22, 262, 8), // "slotLoad"
QT_MOC_LITERAL(23, 271, 15), // "slotSetFilePath"
QT_MOC_LITERAL(24, 287, 4), // "path"
QT_MOC_LITERAL(25, 292, 27), // "slotFetchEthernetInterfaces"
QT_MOC_LITERAL(26, 320, 16), // "slotStartCapture"
QT_MOC_LITERAL(27, 337, 13), // "slotSetFilter"
QT_MOC_LITERAL(28, 351, 12), // "filterString"
QT_MOC_LITERAL(29, 364, 15), // "slotStopCapture"
QT_MOC_LITERAL(30, 380, 11), // "slotCapture"
QT_MOC_LITERAL(31, 392, 22) // "slotFetchDeviceDetails"

    },
    "Worker\0sigReady\0\0sigFiltered\0error\0"
    "sigCaptureReady\0deviceName\0sigProgress\0"
    "percentage\0sigInterfaceList\0"
    "interfaceNameList\0sigFinished\0sigInfo\0"
    "Worker::MessageType\0sigCaptured\0"
    "const pcap_pkthdr*\0pkthdr\0"
    "const unsigned char*\0packet\0"
    "sigEmitDeviceDetails\0list\0slotParse\0"
    "slotLoad\0slotSetFilePath\0path\0"
    "slotFetchEthernetInterfaces\0"
    "slotStartCapture\0slotSetFilter\0"
    "filterString\0slotStopCapture\0slotCapture\0"
    "slotFetchDeviceDetails"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Worker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    1,  105,    2, 0x06 /* Public */,
       5,    1,  108,    2, 0x06 /* Public */,
       7,    1,  111,    2, 0x06 /* Public */,
       9,    1,  114,    2, 0x06 /* Public */,
      11,    0,  117,    2, 0x06 /* Public */,
      12,    2,  118,    2, 0x06 /* Public */,
      14,    2,  123,    2, 0x06 /* Public */,
      19,    1,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    0,  131,    2, 0x08 /* Private */,
      22,    0,  132,    2, 0x08 /* Private */,
      23,    1,  133,    2, 0x08 /* Private */,
      25,    0,  136,    2, 0x08 /* Private */,
      26,    0,  137,    2, 0x08 /* Private */,
      27,    1,  138,    2, 0x08 /* Private */,
      29,    0,  141,    2, 0x08 /* Private */,
      30,    0,  142,    2, 0x08 /* Private */,
      31,    0,  143,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QStringList,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    2,    2,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void, QMetaType::QStringList,   20,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReady(); break;
        case 1: _t->sigFiltered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sigCaptureReady((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sigInterfaceList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->sigFinished(); break;
        case 6: _t->sigInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Worker::MessageType(*)>(_a[2]))); break;
        case 7: _t->sigCaptured((*reinterpret_cast< const pcap_pkthdr*(*)>(_a[1])),(*reinterpret_cast< const unsigned char*(*)>(_a[2]))); break;
        case 8: _t->sigEmitDeviceDetails((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 9: _t->slotParse(); break;
        case 10: _t->slotLoad(); break;
        case 11: _t->slotSetFilePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slotFetchEthernetInterfaces(); break;
        case 13: _t->slotStartCapture(); break;
        case 14: _t->slotSetFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->slotStopCapture(); break;
        case 16: _t->slotCapture(); break;
        case 17: _t->slotFetchDeviceDetails(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Worker::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigFiltered)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigCaptureReady)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Worker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigProgress)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigInterfaceList)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigFinished)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QString , Worker::MessageType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigInfo)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Worker::*)(const pcap_pkthdr * , const unsigned char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigCaptured)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::sigEmitDeviceDetails)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Worker.data,
    qt_meta_data_Worker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Worker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Worker::sigReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Worker::sigFiltered(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Worker::sigCaptureReady(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Worker::sigProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Worker::sigInterfaceList(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Worker::sigFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Worker::sigInfo(QString _t1, Worker::MessageType _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Worker::sigCaptured(const pcap_pkthdr * _t1, const unsigned char * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Worker::sigEmitDeviceDetails(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
