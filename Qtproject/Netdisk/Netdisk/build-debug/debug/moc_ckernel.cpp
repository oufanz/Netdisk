/****************************************************************************
** Meta object code from reading C++ file 'ckernel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ckernel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ckernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CKernel_t {
    QByteArrayData data[20];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CKernel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CKernel_t qt_meta_stringdata_CKernel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CKernel"
QT_MOC_LITERAL(1, 8, 19), // "slot_registerCommit"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "tel"
QT_MOC_LITERAL(4, 33, 8), // "password"
QT_MOC_LITERAL(5, 42, 4), // "name"
QT_MOC_LITERAL(6, 47, 16), // "slot_LoginCommit"
QT_MOC_LITERAL(7, 64, 12), // "slot_destroy"
QT_MOC_LITERAL(8, 77, 15), // "slot_uploadFile"
QT_MOC_LITERAL(9, 93, 4), // "path"
QT_MOC_LITERAL(10, 98, 3), // "dir"
QT_MOC_LITERAL(11, 102, 19), // "slot_dealClientData"
QT_MOC_LITERAL(12, 122, 7), // "lSendIP"
QT_MOC_LITERAL(13, 130, 5), // "char*"
QT_MOC_LITERAL(14, 136, 3), // "buf"
QT_MOC_LITERAL(15, 140, 4), // "nlen"
QT_MOC_LITERAL(16, 145, 16), // "slot_dealLoginRs"
QT_MOC_LITERAL(17, 162, 19), // "slot_dealRegisterRs"
QT_MOC_LITERAL(18, 182, 21), // "slot_dealUploaFiledRs"
QT_MOC_LITERAL(19, 204, 22) // "slot_dealFileContentRs"

    },
    "CKernel\0slot_registerCommit\0\0tel\0"
    "password\0name\0slot_LoginCommit\0"
    "slot_destroy\0slot_uploadFile\0path\0dir\0"
    "slot_dealClientData\0lSendIP\0char*\0buf\0"
    "nlen\0slot_dealLoginRs\0slot_dealRegisterRs\0"
    "slot_dealUploaFiledRs\0slot_dealFileContentRs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CKernel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x08 /* Private */,
       6,    2,   66,    2, 0x08 /* Private */,
       7,    0,   71,    2, 0x08 /* Private */,
       8,    2,   72,    2, 0x08 /* Private */,
      11,    3,   77,    2, 0x08 /* Private */,
      16,    3,   84,    2, 0x08 /* Private */,
      17,    3,   91,    2, 0x08 /* Private */,
      18,    3,   98,    2, 0x08 /* Private */,
      19,    3,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 13, QMetaType::Int,   12,   14,   15,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 13, QMetaType::Int,   12,   14,   15,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 13, QMetaType::Int,   12,   14,   15,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 13, QMetaType::Int,   12,   14,   15,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 13, QMetaType::Int,   12,   14,   15,

       0        // eod
};

void CKernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CKernel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_registerCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->slot_LoginCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->slot_destroy(); break;
        case 3: _t->slot_uploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->slot_dealClientData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->slot_dealLoginRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->slot_dealRegisterRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->slot_dealUploaFiledRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->slot_dealFileContentRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CKernel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CKernel.data,
    qt_meta_data_CKernel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CKernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CKernel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CKernel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CKernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
