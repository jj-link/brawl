#pragma force_active on

template <class Observer, int Capacity> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
class soMotionEventObserver;
class soEventUnit;
template <class T, int N> class soArrayVector;
template <class T> class soInstanceUnit;
template <class T, class Storage> class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" {
void fn_27_D7BEC(void*, short);
void fn_27_D7DBC(void*, short);
void fn_27_D6B9C(void*, short);
void fn_27_D5B4C(void*, short);
void fn_27_D767C(void*, short);
void fn_27_D710C(void*, short);
void fn_27_D57AC(void*, short);
void fn_27_D5EEC(void*, short);
void fn_27_D67FC(void*, short);
void fn_27_D645C(void*, short);
void __dt__23soEventManageModuleImplFv(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_2ECE4(void* self, short del) {
    if (self != 0) {
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>((char*)self + 0x4E0)->~soEventUnitWithWorkArea();
        fn_27_D7BEC((char*)self + 0x498, -1);
        fn_27_D7DBC((char*)self + 0x45C, -1);
        fn_27_D6B9C((char*)self + 0x420, -1);
        fn_27_D5B4C((char*)self + 0x3D0, -1);
        fn_27_D767C((char*)self + 0x380, -1);
        fn_27_D710C((char*)self + 0x330, -1);
        fn_27_D57AC((char*)self + 0x2F4, -1);
        fn_27_D5EEC((char*)self + 0x2BC, -1);
        fn_27_D67FC((char*)self + 0x188, -1);
        fn_27_D645C((char*)self + 0xCC, -1);
        __dt__23soEventManageModuleImplFv((char*)self + 0xB8, -1);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(self)->~soInstanceManagerSimpleEntity();
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
