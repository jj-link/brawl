#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A8B10(void*, short);
extern "C" void* fn_27_D7DBC(void*, short);
extern "C" void* fn_27_D57AC(void*, short);
extern "C" void* fn_27_1A9D88(void*, short);
extern "C" void* fn_27_1A9194(void*, short);
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);
extern "C" void* __dt__98soInstanceManagerSimpleEntityP11soEventUnit50soArrayVector30soInstanceUnitP11soEventUnit19Fv(void*, short);

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

extern "C" void* fn_116_1DAF8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_1A8B10(storage + 0x3B0, destroy);
        fn_27_D7DBC(storage + 0x370, destroy);
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x310)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x2B4)->~soEventUnitWithWorkArea();
        fn_27_D57AC(storage + 0x278, destroy);
        fn_27_1A9D88(storage + 0x170, destroy);
        fn_27_1A9194(storage + 0xCC, destroy);
        __dt__23soEventManageModuleImplFv(storage + 0xB8, destroy);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
