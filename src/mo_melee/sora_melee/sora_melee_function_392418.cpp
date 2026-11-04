#include <new>
#include <so/event/so_event_manage_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

class soModelEventObserver;

template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public:
    soInstanceManagerSimpleEntity();
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};

extern "C" void fn_27_D6358(void*, short, short);
extern "C" void fn_27_1A9E54(void*, short, short);
extern "C" void fn_27_2E6790(void*, short, short);
extern "C" void fn_27_D56A8(void*, short, short);
extern "C" void fn_27_2E6794(void*, short, short);
extern "C" void fn_27_2E6798(void*, short, short);
extern "C" void fn_27_D7578(void*, short, short);
extern "C" void fn_27_D6A98(void*, short, short);
extern "C" void fn_27_2E679C(void*, short, short);
extern "C" void fn_27_D7CB8(void*, short, short);
extern "C" void fn_27_2E67A0(void*, short, short);
extern "C" void fn_27_2E67A4(void*, short, short);
extern "C" void fn_27_2ECF40(void*, short, short);
extern "C" void fn_27_2E67A8(void*, short, short);
extern "C" void fn_27_2E67AC(void*, short, short);
extern "C" void fn_27_1E1070(void*, short, short);
extern "C" void fn_27_1A8BDC(void*, short, short);
extern "C" void fn_27_1E1078(void*, short, short);

extern "C" void* fn_27_392418(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D6358(base + 0xCC, mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A9E54(base + 0x188, mgr, 5);
    fn_27_2E6790(base + 0x2A4, -1, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D56A8(base + 0x2A8, mgr, 7);
    fn_27_2E6794(base + 0x2E0, -1, 8);
    fn_27_2E6798(base + 0x2E1, -1, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D7578(base + 0x2E4, mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x334) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D6A98(base + 0x390, mgr, 11);
    fn_27_2E679C(base + 0x3C8, -1, 13);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D7CB8(base + 0x3CC, mgr, 14);
    fn_27_2E67A0(base + 0x404, -1, 15);
    fn_27_2E67A4(base + 0x405, -1, 16);
    fn_27_2ECF40(base + 0x406, -1, 17);
    fn_27_2E67A8(base + 0x407, -1, 12);
    fn_27_2E67AC(base + 0x408, -1, 10);
    fn_27_1E1070(base + 0x409, -1, 3);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A8BDC(base + 0x40C, mgr, 18);
    fn_27_1E1078(base + 0x48C, -1, 2);
    return self;
}