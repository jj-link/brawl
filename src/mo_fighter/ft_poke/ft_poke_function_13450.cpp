#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A8CE0(void*, short);
extern "C" void* fn_27_D7DBC(void*, short);
extern "C" void* fn_27_D6B9C(void*, short);
extern "C" void* fn_27_D57AC(void*, short);
extern "C" void* fn_27_1A9D88(void*, short);
extern "C" void* fn_27_1A9364(void*, short);
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);

class soModelEventObserver;
class soCollisionAttackEventObserver;
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

extern "C" void* fn_116_13450(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_1A8CE0(storage + 0x3F4, destroy);
        fn_27_D7DBC(storage + 0x3B4, destroy);
        fn_27_D6B9C(storage + 0x378, destroy);
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x31C)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x2C0)->~soEventUnitWithWorkArea();
        fn_27_D57AC(storage + 0x284, destroy);
        fn_27_1A9D88(storage + 0x17C, destroy);
        fn_27_1A9364(storage + 0xCC, destroy);
        __dt__23soEventManageModuleImplFv(storage + 0xB8, destroy);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
