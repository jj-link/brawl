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

template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > : public soInstanceManagerSimple<soEventUnit*> {
public:
    soInstanceManagerFixedSimple<soEventUnit*, soInstanceUnit<soEventUnit*>, soArray<soInstanceUnit<soEventUnit*> > > m_fixedSimple;
    soArrayVector<soInstanceUnit<soEventUnit*>, 19> m_arrayVector;
    soInstanceManagerSimpleEntity();
    ~soInstanceManagerSimpleEntity();
};
#define DECLARE_UNIT(Observer, Capacity) \
template <> class soEventUnitWithWorkArea<Observer, Capacity> : public soEventUnitImpl<Observer> { \
    soInstanceManagerFullPropertyVector<Observer*, Capacity> m_observerList; \
public: \
    soEventUnitWithWorkArea(short mgrId, short p2); \
    virtual ~soEventUnitWithWorkArea(); \
    virtual u32 getObserverNum() const; \
};
DECLARE_UNIT(soStatusEventObserver, 32)
DECLARE_UNIT(soAnimCmdEventObserver, 40)
DECLARE_UNIT(soDamageEventObserver, 4)
DECLARE_UNIT(soLinkEventObserver, 4)
DECLARE_UNIT(soSituationEventObserver, 4)
DECLARE_UNIT(soCollisionHitEventObserver, 4)
DECLARE_UNIT(soCollisionAttackEventObserver, 4)
DECLARE_UNIT(soModelEventObserver, 4)
DECLARE_UNIT(soArticleEventObserver, 5)
DECLARE_UNIT(soCaptureEventObserver, 4)
DECLARE_UNIT(soCollisionShieldEventObserver, 4)
DECLARE_UNIT(soCollisionReflectorEventObserver, 4)
DECLARE_UNIT(soCollisionAbsorberEventObserver, 4)
DECLARE_UNIT(soCollisionSearchEventObserver, 4)
DECLARE_UNIT(soItemManageEventObserver, 1)
DECLARE_UNIT(soMotionEventObserver, 1)
DECLARE_UNIT(soTurnEventObserver, 2)
DECLARE_UNIT(soCollisionCatchEventObserver, 1)
#undef DECLARE_UNIT

extern "C" void* fn_103_72AC(void* self) {
    char* base = static_cast<char*>(self);
    short mgr;
    new (base) soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >();
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
    new (base + 0x6AC) soEventUnitWithWorkArea<soArticleEventObserver, 5>(mgr, 11);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x714) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(mgr, 13);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x770) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(mgr, 14);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x7CC) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(mgr, 15);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x828) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(mgr, 16);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x884) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(mgr, 17);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x8E0) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(mgr, 12);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x918) soEventUnitWithWorkArea<soMotionEventObserver, 1>(mgr, 10);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x954) soEventUnitWithWorkArea<soTurnEventObserver, 2>(mgr, 18);
    mgr = reinterpret_cast<soEventManageModuleImpl*>(base + 0xB8)->getManageId();
    new (base + 0x998) soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>(mgr, 2);
    return self;
}
