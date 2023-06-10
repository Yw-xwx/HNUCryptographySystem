/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Second/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10) // "MainWindow"

    },
    "MainWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Widget_base_t {
    QByteArrayData data[4];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_base_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_base_t qt_meta_stringdata_Widget_base = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Widget_base"
QT_MOC_LITERAL(1, 12, 10), // "switchPage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9) // "pageIndex"

    },
    "Widget_base\0switchPage\0\0pageIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_base[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Widget_base::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget_base *_t = static_cast<Widget_base *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Widget_base::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget_base::switchPage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Widget_base::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_base.data,
      qt_meta_data_Widget_base,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget_base::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_base::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_base.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget_base::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Widget_base::switchPage(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Widget_affline_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_affline_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_affline_t qt_meta_stringdata_Widget_affline = {
    {
QT_MOC_LITERAL(0, 0, 14) // "Widget_affline"

    },
    "Widget_affline"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_affline[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Widget_affline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Widget_affline::staticMetaObject = {
    { &Widget_base::staticMetaObject, qt_meta_stringdata_Widget_affline.data,
      qt_meta_data_Widget_affline,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget_affline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_affline::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_affline.stringdata0))
        return static_cast<void*>(this);
    return Widget_base::qt_metacast(_clname);
}

int Widget_affline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget_base::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Widget_stream_rc4_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_stream_rc4_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_stream_rc4_t qt_meta_stringdata_Widget_stream_rc4 = {
    {
QT_MOC_LITERAL(0, 0, 17) // "Widget_stream_rc4"

    },
    "Widget_stream_rc4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_stream_rc4[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Widget_stream_rc4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Widget_stream_rc4::staticMetaObject = {
    { &Widget_base::staticMetaObject, qt_meta_stringdata_Widget_stream_rc4.data,
      qt_meta_data_Widget_stream_rc4,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget_stream_rc4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_stream_rc4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_stream_rc4.stringdata0))
        return static_cast<void*>(this);
    return Widget_base::qt_metacast(_clname);
}

int Widget_stream_rc4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget_base::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Widget_stream_jk_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_stream_jk_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_stream_jk_t qt_meta_stringdata_Widget_stream_jk = {
    {
QT_MOC_LITERAL(0, 0, 16) // "Widget_stream_jk"

    },
    "Widget_stream_jk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_stream_jk[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Widget_stream_jk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Widget_stream_jk::staticMetaObject = {
    { &Widget_base::staticMetaObject, qt_meta_stringdata_Widget_stream_jk.data,
      qt_meta_data_Widget_stream_jk,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget_stream_jk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_stream_jk::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_stream_jk.stringdata0))
        return static_cast<void*>(this);
    return Widget_base::qt_metacast(_clname);
}

int Widget_stream_jk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget_base::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Widget_des_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_des_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_des_t qt_meta_stringdata_Widget_des = {
    {
QT_MOC_LITERAL(0, 0, 10) // "Widget_des"

    },
    "Widget_des"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_des[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Widget_des::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Widget_des::staticMetaObject = {
    { &Widget_base::staticMetaObject, qt_meta_stringdata_Widget_des.data,
      qt_meta_data_Widget_des,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget_des::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_des::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_des.stringdata0))
        return static_cast<void*>(this);
    return Widget_base::qt_metacast(_clname);
}

int Widget_des::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget_base::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Widget_rsa_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_rsa_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_rsa_t qt_meta_stringdata_Widget_rsa = {
    {
QT_MOC_LITERAL(0, 0, 10) // "Widget_rsa"

    },
    "Widget_rsa"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_rsa[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Widget_rsa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Widget_rsa::staticMetaObject = {
    { &Widget_base::staticMetaObject, qt_meta_stringdata_Widget_rsa.data,
      qt_meta_data_Widget_rsa,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget_rsa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_rsa::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_rsa.stringdata0))
        return static_cast<void*>(this);
    return Widget_base::qt_metacast(_clname);
}

int Widget_rsa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget_base::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Widget_dh_t {
    QByteArrayData data[4];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_dh_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_dh_t qt_meta_stringdata_Widget_dh = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Widget_dh"
QT_MOC_LITERAL(1, 10, 9), // "myConnect"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9) // "myReceive"

    },
    "Widget_dh\0myConnect\0\0myReceive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_dh[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget_dh::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget_dh *_t = static_cast<Widget_dh *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->myConnect(); break;
        case 1: _t->myReceive(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Widget_dh::staticMetaObject = {
    { &Widget_base::staticMetaObject, qt_meta_stringdata_Widget_dh.data,
      qt_meta_data_Widget_dh,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget_dh::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_dh::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_dh.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Rsa"))
        return static_cast< Rsa*>(this);
    return Widget_base::qt_metacast(_clname);
}

int Widget_dh::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Widget_base::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
