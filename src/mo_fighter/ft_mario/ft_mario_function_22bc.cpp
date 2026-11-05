#include <new>
#include <so/event/so_event_manage_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on
#pragma inline_depth(0)
#pragma auto_inline off
class soStatusEventObserver;
class soAnimCmdEventObserver;
class soDamageEventObserver;
class soLinkEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
class soArticleEventObserver;
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;
class soTurnEventObserver;
class soCollisionCatchEventObserver;
template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public:
    soInstanceManagerSimpleEntity();
};
template <> class soEventUnitWithWorkArea<soStatusEventObserver, 32> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soAnimCmdEventObserver, 40> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soLinkEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soArticleEventObserver, 5> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soTurnEventObserver, 2> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
template <> class soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short managerId, short eventId);
};
extern "C" void* fn_91_22BC(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
    new (base + 0xB8) soEventManageModuleImpl(self);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0xcc) soEventUnitWithWorkArea<soStatusEventObserver, 32>(mgr, 4);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x278) soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>(mgr, 5);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x484) soEventUnitWithWorkArea<soDamageEventObserver, 4>(mgr, 6);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x4e0) soEventUnitWithWorkArea<soLinkEventObserver, 4>(mgr, 7);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x53c) soEventUnitWithWorkArea<soSituationEventObserver, 4>(mgr, 8);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x598) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(mgr, 0);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x5f4) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(mgr, 1);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x650) soEventUnitWithWorkArea<soModelEventObserver, 4>(mgr, 9);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x6ac) soEventUnitWithWorkArea<soArticleEventObserver, 5>(mgr, 11);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x714) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(mgr, 13);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x770) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(mgr, 14);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x7cc) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(mgr, 15);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x828) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(mgr, 16);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x884) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(mgr, 17);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x8e0) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(mgr, 12);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x918) soEventUnitWithWorkArea<soMotionEventObserver, 1>(mgr, 10);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x954) soEventUnitWithWorkArea<soTurnEventObserver, 2>(mgr, 18);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x998) soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>(mgr, 2);
    return self;
}
