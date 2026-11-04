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

extern "C" void fn_27_D6358(void*, short, short);
extern "C" void fn_27_1A9E54(void*, short, short);
extern "C" void fn_27_2E6790(void*, short, short);
extern "C" void fn_27_D56A8(void*, short, short);
extern "C" void fn_27_2E6794(void*, short, short);
extern "C" void fn_27_2E6798(void*, short, short);
extern "C" void fn_27_D6A98(void*, short, short);
extern "C" void fn_27_2E679C(void*, short, short);
extern "C" void fn_27_D7CB8(void*, short, short);
extern "C" void fn_27_2E67A0(void*, short, short);
extern "C" void fn_27_2E67A4(void*, short, short);
extern "C" void fn_27_2EA26C(void*, short, short);
extern "C" void fn_27_2E67A8(void*, short, short);
extern "C" void fn_27_2E67AC(void*, short, short);
extern "C" void fn_27_1E1070(void*, short, short);
extern "C" void fn_27_1A8A0C(void*, short, short);
extern "C" void fn_27_1E1078(void*, short, short);

extern "C" void* fn_27_2E654C(void* self) {
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
    new (base + 0x2E4) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x340) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D6A98(base + 0x39C, mgr, 11);
    fn_27_2E679C(base + 0x3D4, -1, 13);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D7CB8(base + 0x3D8, mgr, 14);
    fn_27_2E67A0(base + 0x410, -1, 15);
    fn_27_2E67A4(base + 0x411, -1, 16);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_2EA26C(base + 0x414, mgr, 17);
    fn_27_2E67A8(base + 0x464, -1, 12);
    fn_27_2E67AC(base + 0x465, -1, 10);
    fn_27_1E1070(base + 0x466, -1, 3);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A8A0C(base + 0x468, mgr, 18);
    fn_27_1E1078(base + 0x4DC, -1, 2);
    return self;
}
