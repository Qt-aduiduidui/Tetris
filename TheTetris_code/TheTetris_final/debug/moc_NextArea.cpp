/****************************************************************************
** Meta object code from reading C++ file 'NextArea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NextArea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NextArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NextArea_t {
    QByteArrayData data[5];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NextArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NextArea_t qt_meta_stringdata_NextArea = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NextArea"
QT_MOC_LITERAL(1, 9, 19), // "slotUpdateNextBlock"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "Block"
QT_MOC_LITERAL(4, 36, 9) // "NextBlock"

    },
    "NextArea\0slotUpdateNextBlock\0\0Block\0"
    "NextBlock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NextArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void NextArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NextArea *_t = static_cast<NextArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotUpdateNextBlock((*reinterpret_cast< Block(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NextArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NextArea.data,
      qt_meta_data_NextArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NextArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NextArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NextArea.stringdata0))
        return static_cast<void*>(const_cast< NextArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int NextArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
