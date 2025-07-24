/****************************************************************************
** Meta object code from reading C++ file 'Character.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/Items/Characters/Character.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Character.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCharacterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCharacterENDCLASS = QtMocHelpers::stringData(
    "Character",
    "groundTypeChanged",
    "",
    "GroundType",
    "newGround",
    "healthIncreaseRequested",
    "speedIncreaseRequested",
    "handleGroundTypeChanged",
    "increaseHealth",
    "increaseSpeed",
    "resetSpeed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCharacterENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[10];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[10];
    char stringdata5[24];
    char stringdata6[23];
    char stringdata7[24];
    char stringdata8[15];
    char stringdata9[14];
    char stringdata10[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCharacterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCharacterENDCLASS_t qt_meta_stringdata_CLASSCharacterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Character"
        QT_MOC_LITERAL(10, 17),  // "groundTypeChanged"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 10),  // "GroundType"
        QT_MOC_LITERAL(40, 9),  // "newGround"
        QT_MOC_LITERAL(50, 23),  // "healthIncreaseRequested"
        QT_MOC_LITERAL(74, 22),  // "speedIncreaseRequested"
        QT_MOC_LITERAL(97, 23),  // "handleGroundTypeChanged"
        QT_MOC_LITERAL(121, 14),  // "increaseHealth"
        QT_MOC_LITERAL(136, 13),  // "increaseSpeed"
        QT_MOC_LITERAL(150, 10)   // "resetSpeed"
    },
    "Character",
    "groundTypeChanged",
    "",
    "GroundType",
    "newGround",
    "healthIncreaseRequested",
    "speedIncreaseRequested",
    "handleGroundTypeChanged",
    "increaseHealth",
    "increaseSpeed",
    "resetSpeed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCharacterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       5,    0,   59,    2, 0x06,    3 /* Public */,
       6,    0,   60,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   61,    2, 0x08,    5 /* Private */,
       8,    0,   64,    2, 0x08,    7 /* Private */,
       9,    0,   65,    2, 0x08,    8 /* Private */,
      10,    0,   66,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Character::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSCharacterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCharacterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCharacterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Character, std::true_type>,
        // method 'groundTypeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GroundType, std::false_type>,
        // method 'healthIncreaseRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'speedIncreaseRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleGroundTypeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GroundType, std::false_type>,
        // method 'increaseHealth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'increaseSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Character::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Character *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->groundTypeChanged((*reinterpret_cast< std::add_pointer_t<GroundType>>(_a[1]))); break;
        case 1: _t->healthIncreaseRequested(); break;
        case 2: _t->speedIncreaseRequested(); break;
        case 3: _t->handleGroundTypeChanged((*reinterpret_cast< std::add_pointer_t<GroundType>>(_a[1]))); break;
        case 4: _t->increaseHealth(); break;
        case 5: _t->increaseSpeed(); break;
        case 6: _t->resetSpeed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Character::*)(GroundType );
            if (_t _q_method = &Character::groundTypeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Character::*)();
            if (_t _q_method = &Character::healthIncreaseRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Character::*)();
            if (_t _q_method = &Character::speedIncreaseRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Character::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Character::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCharacterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Item"))
        return static_cast< Item*>(this);
    return QObject::qt_metacast(_clname);
}

int Character::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Character::groundTypeChanged(GroundType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Character::healthIncreaseRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Character::speedIncreaseRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
