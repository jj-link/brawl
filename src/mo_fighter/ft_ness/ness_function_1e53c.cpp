#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A8B10(void*, short);
extern "C" void* fn_27_D7DBC(void*, short);
extern "C" void* fn_27_18D3DC(void*, short);
extern "C" void* fn_27_D597C(void*, short);
extern "C" void* fn_27_1AA128(void*, short);
extern "C" void* fn_27_18D788(void*, short);
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);

// Declaration-only destructor ABI, as in the Ness event storage unit.
// Import the shared implementations without instantiating their vtables.
class soModelEventObserver;
class soCollisionAttackEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;
class soEventUnit;

template <class Observer, int Capacity>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template <class Element> class soInstanceUnit;
template <class Element, int Capacity> class soArrayVector;
template <class Element, class Storage>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" void* fn_101_1E53C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A8B10(storage + 0x544, -1);
        fn_27_D7DBC(storage + 0x504, -1);
        fn_27_18D3DC(storage + 0x4BC, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x460)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x404)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x3A4)->~soEventUnitWithWorkArea();
        fn_27_D597C(storage + 0x360, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x304)->~soEventUnitWithWorkArea();
        fn_27_1AA128(storage + 0x1B8, -1);
        fn_27_18D788(storage + 0xCC, -1);
        __dt__23soEventManageModuleImplFv(storage + 0xB8, -1);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
