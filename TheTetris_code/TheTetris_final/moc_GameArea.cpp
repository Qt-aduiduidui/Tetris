/****************************************************************************
** Meta object code from reading C++ file 'GameArea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GameArea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameArea_t {
    QByteArrayData data[12];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameArea_t qt_meta_stringdata_GameArea = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameArea"
QT_MOC_LITERAL(1, 9, 18), // "sigUpdateNextBlock"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "Block"
QT_MOC_LITERAL(4, 35, 9), // "NextBlock"
QT_MOC_LITERAL(5, 45, 18), // "sigUpdateHoldBlock"
QT_MOC_LITERAL(6, 64, 6), // "Block*"
QT_MOC_LITERAL(7, 71, 9), // "HoldBlock"
QT_MOC_LITERAL(8, 81, 14), // "sigUpdateScore"
QT_MOC_LITERAL(9, 96, 6), // "nScore"
QT_MOC_LITERAL(10, 103, 14), // "sigUpdateSpeed"
QT_MOC_LITERAL(11, 118, 6) // "nSpeed"

    },
    "GameArea\0sigUpdateNextBlock\0\0Block\0"
    "NextBlock\0sigUpdateHoldBlock\0Block*\0"
    "HoldBlock\0sigUpdateScore\0nScore\0"
    "sigUpdateSpeed\0nSpeed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       8,    1,   40,    2, 0x06 /* Public */,
      10,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void GameArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameArea *_t = static_cast<GameArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateNextBlock((*reinterpret_cast< Block(*)>(_a[1]))); break;
        case 1: _t->sigUpdateHoldBlock((*reinterpret_cast< Block*(*)>(_a[1]))); break;
        case 2: _t->sigUpdateScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigUpdateSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GameArea::*_t)(Block );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigUpdateNextBlock)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GameArea::*_t)(Block * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigUpdateHoldBlock)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GameArea::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigUpdateScore)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GameArea::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigUpdateSpeed)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject GameArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameArea.data,
      qt_meta_data_GameArea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GameArea::sigUpdateNextBlock(Block _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameArea::sigUpdateHoldBlock(Block * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameArea::sigUpdateScore(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameArea::sigUpdateSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
