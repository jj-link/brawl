#include <new>
#include <so/event/so_event_manage_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

class soStatusEventObserver;
class soAnimCmdEventObserver;
class soDamageEventObserver;
class soLinkEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;
class soTurnEventObserver;
class soCollisionCatchEventObserver;

typedef soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > EventInstances;
template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public:
    soInstanceManagerSimpleEntity();
};
template <> class soEventUnitWithWorkArea<soStatusEventObserver, 32> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soAnimCmdEventObserver, 40> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soLinkEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soTurnEventObserver, 2> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};
template <> class soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short mgrId, short p2);
};

extern "C" void fn_27_1AA878(void*, short, short);
extern "C" void fn_27_1E1070(void*, int, int);

extern "C" void* fn_27_37B680(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) EventInstances();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0xCC) soEventUnitWithWorkArea<soStatusEventObserver, 32>(mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x278) soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>(mgr, 5);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x484) soEventUnitWithWorkArea<soDamageEventObserver, 4>(mgr, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x4E0) soEventUnitWithWorkArea<soLinkEventObserver, 4>(mgr, 7);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x53C) soEventUnitWithWorkArea<soSituationEventObserver, 4>(mgr, 8);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x598) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(mgr, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x5F4) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x650) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    fn_27_1AA878(base + 0x6AC, mgr, 11);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x6F0) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(mgr, 13);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x74C) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(mgr, 14);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x7A8) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(mgr, 15);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x804) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(mgr, 16);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x860) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(mgr, 17);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x8BC) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(mgr, 12);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x8F4) soEventUnitWithWorkArea<soMotionEventObserver, 1>(mgr, 10);
    fn_27_1E1070(base + 0x92C, -1, 3);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x930) soEventUnitWithWorkArea<soTurnEventObserver, 2>(mgr, 18);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x974) soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>(mgr, 2);
    return self;
}
