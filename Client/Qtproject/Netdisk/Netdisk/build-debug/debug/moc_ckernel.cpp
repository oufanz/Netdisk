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
    QByteArrayData data[23];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CKernel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CKernel_t qt_meta_stringdata_CKernel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CKernel"
QT_MOC_LITERAL(1, 8, 28), // "SIG_updateUploadFileProgress"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "timestamp"
QT_MOC_LITERAL(4, 48, 3), // "pos"
QT_MOC_LITERAL(5, 52, 19), // "slot_registerCommit"
QT_MOC_LITERAL(6, 72, 3), // "tel"
QT_MOC_LITERAL(7, 76, 8), // "password"
QT_MOC_LITERAL(8, 85, 4), // "name"
QT_MOC_LITERAL(9, 90, 16), // "slot_LoginCommit"
QT_MOC_LITERAL(10, 107, 12), // "slot_destroy"
QT_MOC_LITERAL(11, 120, 15), // "slot_uploadFile"
QT_MOC_LITERAL(12, 136, 4), // "path"
QT_MOC_LITERAL(13, 141, 3), // "dir"
QT_MOC_LITERAL(14, 145, 19), // "slot_dealClientData"
QT_MOC_LITERAL(15, 165, 7), // "lSendIP"
QT_MOC_LITERAL(16, 173, 5), // "char*"
QT_MOC_LITERAL(17, 179, 3), // "buf"
QT_MOC_LITERAL(18, 183, 4), // "nlen"
QT_MOC_LITERAL(19, 188, 16), // "slot_dealLoginRs"
QT_MOC_LITERAL(20, 205, 19), // "slot_dealRegisterRs"
QT_MOC_LITERAL(21, 225, 21), // "slot_dealUploaFiledRs"
QT_MOC_LITERAL(22, 247, 22) // "slot_dealFileContentRs"

    },
    "CKernel\0SIG_updateUploadFileProgress\0"
    "\0timestamp\0pos\0slot_registerCommit\0"
    "tel\0password\0name\0slot_LoginCommit\0"
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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   69,    2, 0x08 /* Private */,
       9,    2,   76,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    2,   82,    2, 0x08 /* Private */,
      14,    3,   87,    2, 0x08 /* Private */,
      19,    3,   94,    2, 0x08 /* Private */,
      20,    3,  101,    2, 0x08 /* Private */,
      21,    3,  108,    2, 0x08 /* Private */,
      22,    3,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 16, QMetaType::Int,   15,   17,   18,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 16, QMetaType::Int,   15,   17,   18,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 16, QMetaType::Int,   15,   17,   18,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 16, QMetaType::Int,   15,   17,   18,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 16, QMetaType::Int,   15,   17,   18,

       0        // eod
};

void CKernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CKernel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_updateUploadFileProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slot_registerCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->slot_LoginCommit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slot_destroy(); break;
        case 4: _t->slot_uploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->slot_dealClientData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->slot_dealLoginRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->slot_dealRegisterRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->slot_dealUploaFiledRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->slot_dealFileContentRs((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CKernel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CKernel::SIG_updateUploadFileProgress)) {
                *result = 0;
                return;
            }
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
void CKernel::SIG_updateUploadFileProgress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
