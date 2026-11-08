#include <new>
#include <so/event/so_event_manage_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

class soCollisionAttackEventObserver;
class soModelEventObserver;

template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public:
    soInstanceManagerSimpleEntity();
};
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};

extern "C" void fn_27_1A9260(void*, short, short);
extern "C" void fn_27_1A9AB4(void*, short, short);
extern "C" void fn_27_2E6790(void*, short, short);
extern "C" void fn_27_D56A8(void*, short, short);
extern "C" void fn_27_2E6794(void*, short, short);
extern "C" void fn_27_2E6798(void*, short, short);
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

extern "C" void* fn_27_36B1C4(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A9260(base + 0xCC, mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A9AB4(base + 0x17C, mgr, 5);
    fn_27_2E6790(base + 0x274, -1, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D56A8(base + 0x278, mgr, 7);
    fn_27_2E6794(base + 0x2B0, -1, 8);
    fn_27_2E6798(base + 0x2B1, -1, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x2B4) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x310) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D6A98(base + 0x36C, mgr, 0xB);
    fn_27_2E679C(base + 0x3A4, -1, 0xD);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D7CB8(base + 0x3A8, mgr, 0xE);
    fn_27_2E67A0(base + 0x3E0, -1, 0xF);
    fn_27_2E67A4(base + 0x3E1, -1, 0x10);
    fn_27_2ECF40(base + 0x3E2, -1, 0x11);
    fn_27_2E67A8(base + 0x3E3, -1, 0xC);
    fn_27_2E67AC(base + 0x3E4, -1, 0xA);
    fn_27_1E1070(base + 0x3E5, -1, 3);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A8BDC(base + 0x3E8, mgr, 0x12);
    fn_27_1E1078(base + 0x468, -1, 2);
    return self;
}