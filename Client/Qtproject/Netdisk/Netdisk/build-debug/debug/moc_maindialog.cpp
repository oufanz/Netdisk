/****************************************************************************
** Meta object code from reading C++ file 'maindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../maindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainDialog_t {
    QByteArrayData data[23];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainDialog_t qt_meta_stringdata_MainDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainDialog"
QT_MOC_LITERAL(1, 11, 9), // "SIG_close"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "SIG_uploadFile"
QT_MOC_LITERAL(4, 37, 4), // "path"
QT_MOC_LITERAL(5, 42, 3), // "dir"
QT_MOC_LITERAL(6, 46, 19), // "on_pb_share_clicked"
QT_MOC_LITERAL(7, 66, 18), // "on_pb_file_clicked"
QT_MOC_LITERAL(8, 85, 22), // "on_pb_transmit_clicked"
QT_MOC_LITERAL(9, 108, 21), // "on_pb_addfile_clicked"
QT_MOC_LITERAL(10, 130, 14), // "slot_addFolder"
QT_MOC_LITERAL(11, 145, 4), // "flag"
QT_MOC_LITERAL(12, 150, 15), // "slot_uploadFile"
QT_MOC_LITERAL(13, 166, 17), // "slot_uploadFolder"
QT_MOC_LITERAL(14, 184, 21), // "slot_insertUploadFile"
QT_MOC_LITERAL(15, 206, 9), // "FileInfo&"
QT_MOC_LITERAL(16, 216, 4), // "info"
QT_MOC_LITERAL(17, 221, 29), // "slot_insertUploadFileComplete"
QT_MOC_LITERAL(18, 251, 29), // "slot_updateUploadFileProgress"
QT_MOC_LITERAL(19, 281, 9), // "timestamp"
QT_MOC_LITERAL(20, 291, 3), // "pos"
QT_MOC_LITERAL(21, 295, 26), // "slot_deleteUploadFileByRow"
QT_MOC_LITERAL(22, 322, 3) // "row"

    },
    "MainDialog\0SIG_close\0\0SIG_uploadFile\0"
    "path\0dir\0on_pb_share_clicked\0"
    "on_pb_file_clicked\0on_pb_transmit_clicked\0"
    "on_pb_addfile_clicked\0slot_addFolder\0"
    "flag\0slot_uploadFile\0slot_uploadFolder\0"
    "slot_insertUploadFile\0FileInfo&\0info\0"
    "slot_insertUploadFileComplete\0"
    "slot_updateUploadFileProgress\0timestamp\0"
    "pos\0slot_deleteUploadFileByRow\0row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    2,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      17,    1,  101,    2, 0x08 /* Private */,
      18,    2,  104,    2, 0x08 /* Private */,
      21,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void MainDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_close(); break;
        case 1: _t->SIG_uploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_pb_share_clicked(); break;
        case 3: _t->on_pb_file_clicked(); break;
        case 4: _t->on_pb_transmit_clicked(); break;
        case 5: _t->on_pb_addfile_clicked(); break;
        case 6: _t->slot_addFolder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->slot_uploadFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->slot_uploadFolder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slot_insertUploadFile((*reinterpret_cast< FileInfo(*)>(_a[1]))); break;
        case 10: _t->slot_insertUploadFileComplete((*reinterpret_cast< FileInfo(*)>(_a[1]))); break;
        case 11: _t->slot_updateUploadFileProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->slot_deleteUploadFileByRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_close)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDialog::SIG_uploadFile)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_MainDialog.data,
    qt_meta_data_MainDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void MainDialog::SIG_close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainDialog::SIG_uploadFile(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
