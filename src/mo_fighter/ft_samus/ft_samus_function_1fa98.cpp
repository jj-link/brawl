#pragma force_active on
extern "C" void* fn_27_1A8940(void*, short);
extern "C" void* fn_27_D7DBC(void*, short);
extern "C" void* fn_27_D6B9C(void*, short);
extern "C" void* fn_27_D57AC(void*, short);
extern "C" void* fn_27_1A9D88(void*, short);
extern "C" void* fn_27_D645C(void*, short);
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

class soEventUnit;
class soModelEventObserver;
class soCollisionAttackEventObserver;
template <class T> class soInstanceUnit { };
template <class T, int N> class soArrayVector { };
template <class T, class U> class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};
template <class Obsvr, int N> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

extern "C" void* fn_94_1FA98(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A8940(storage + 0x400, -1);
        fn_27_D7DBC(storage + 0x3C0, -1);
        fn_27_D6B9C(storage + 0x384, -1);
        static_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(reinterpret_cast<void*>(storage + 0x328))->~soEventUnitWithWorkArea();
        static_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(reinterpret_cast<void*>(storage + 0x2CC))->~soEventUnitWithWorkArea();
        fn_27_D57AC(storage + 0x290, -1);
        fn_27_1A9D88(storage + 0x188, -1);
        fn_27_D645C(storage + 0xCC, -1);
        __dt__23soEventManageModuleImplFv(storage + 0xB8, -1);
        static_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(reinterpret_cast<void*>(object))->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
