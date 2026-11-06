#include <new>
#include <so/event/so_event_manage_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

class soSituationEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;

template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public:
    soInstanceManagerSimpleEntity();
};
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
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
extern "C" void fn_27_2E6798(void*, short, short);
extern "C" void fn_27_33EC7C(void*, short, short);
extern "C" void fn_27_2E679C(void*, short, short);
extern "C" void fn_27_D7CB8(void*, short, short);
extern "C" void fn_27_2E67A0(void*, short, short);
extern "C" void fn_27_2E67A4(void*, short, short);
extern "C" void fn_27_2ECF40(void*, short, short);
extern "C" void fn_27_2E67A8(void*, short, short);
extern "C" void fn_27_2E67AC(void*, short, short);
extern "C" void fn_27_1E1070(void*, short, short);
extern "C" void fn_27_1A8A0C(void*, short, short);
extern "C" void fn_27_1E1078(void*, short, short);

extern "C" void* fn_27_33EA50(void* self) {
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
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x2E0) soEventUnitWithWorkArea<soSituationEventObserver, 4>(mgr, 8);
    fn_27_2E6798(base + 0x33C, -1, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x340) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x39C) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    fn_27_33EC7C(base + 0x3F8, -1, 0xB);
    fn_27_2E679C(base + 0x3F9, -1, 0xD);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D7CB8(base + 0x3FC, mgr, 0xE);
    fn_27_2E67A0(base + 0x434, -1, 0xF);
    fn_27_2E67A4(base + 0x435, -1, 0x10);
    fn_27_2ECF40(base + 0x436, -1, 0x11);
    fn_27_2E67A8(base + 0x437, -1, 0xC);
    fn_27_2E67AC(base + 0x438, -1, 0xA);
    fn_27_1E1070(base + 0x439, -1, 3);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A8A0C(base + 0x43C, mgr, 0x12);
    fn_27_1E1078(base + 0x4B0, -1, 2);
    return self;
}
