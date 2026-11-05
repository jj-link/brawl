#include <new>
#include <so/event/so_event_manage_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public:
    soInstanceManagerSimpleEntity();
};
class soDamageEventObserver;
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soSituationEventObserver;
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soCollisionHitEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soCollisionAttackEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soCaptureEventObserver;
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soCollisionShieldEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soCollisionReflectorEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soCollisionAbsorberEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soCollisionSearchEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soItemManageEventObserver;
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short, short);
};
class soMotionEventObserver;
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short, short);
};
extern "C" void fn_27_1A9430(void*, short, short);
extern "C" void fn_27_1AA1F4(void*, short, short);
extern "C" void fn_27_D5878(void*, short, short);
extern "C" void fn_27_1A8F7C(void*, short, short);
extern "C" void fn_27_1AA878(void*, short, short);
extern "C" void fn_27_1E1070(void*, short, short);
extern "C" void fn_27_1E1074(void*, short, short);
extern "C" void fn_27_1E1078(void*, short, short);

extern "C" void* fn_27_1E0D84(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A9430(base + 0xCC, mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1AA1F4(base + 0x1B8, mgr, 5);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x364) soEventUnitWithWorkArea<soDamageEventObserver, 4>(mgr, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_D5878(base + 0x3C0, mgr, 7);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x404) soEventUnitWithWorkArea<soSituationEventObserver, 4>(mgr, 8);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x460) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(mgr, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x4BC) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1A8F7C(base + 0x518, mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1AA878(base + 0x580, mgr, 11);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x5C4) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(mgr, 13);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x620) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(mgr, 14);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x67C) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(mgr, 15);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x6D8) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(mgr, 16);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x734) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(mgr, 17);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x790) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(mgr, 12);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x7C8) soEventUnitWithWorkArea<soMotionEventObserver, 1>(mgr, 10);
    fn_27_1E1070(base + 0x800, -1, 3);
    fn_27_1E1074(base + 0x801, -1, 18);
    fn_27_1E1078(base + 0x802, -1, 2);
    return self;
}
