class soCollisionAttackModule;

#include <so/event/so_event_system.h>

class soCollisionCatchEventObserver;
class soTurnEventObserver;
class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soArticleEventObserver;
class soModelEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soLinkEventObserver;
class soDamageEventObserver;
class soAnimCmdEventObserver;
class soStatusEventObserver;

// Preserve the normal template layout, but import its methods from sora_melee.
// Defining the inline template methods here would also take ownership of their vtables.
#define DECLARE_ORIGINAL_EVENT_UNIT(Observer, Capacity) \
    template <> \
    class soEventUnitWithWorkArea<Observer, Capacity> : public soEventUnitImpl<Observer> { \
        soInstanceManagerFullPropertyVector<Observer*, Capacity> m_observerList; \
    public: \
        soEventUnitWithWorkArea(s16 managerId, s16 eventId); \
        virtual ~soEventUnitWithWorkArea(); \
        virtual u32 getObserverNum() const; \
    };

DECLARE_ORIGINAL_EVENT_UNIT(soCollisionCatchEventObserver, 1)
DECLARE_ORIGINAL_EVENT_UNIT(soTurnEventObserver, 2)
DECLARE_ORIGINAL_EVENT_UNIT(soMotionEventObserver, 1)
DECLARE_ORIGINAL_EVENT_UNIT(soItemManageEventObserver, 1)
DECLARE_ORIGINAL_EVENT_UNIT(soCollisionSearchEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soCollisionAbsorberEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soCollisionReflectorEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soCollisionShieldEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soCaptureEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soArticleEventObserver, 5)
DECLARE_ORIGINAL_EVENT_UNIT(soModelEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soCollisionAttackEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soCollisionHitEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soSituationEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soLinkEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soDamageEventObserver, 4)
DECLARE_ORIGINAL_EVENT_UNIT(soAnimCmdEventObserver, 40)
DECLARE_ORIGINAL_EVENT_UNIT(soStatusEventObserver, 32)

#undef DECLARE_ORIGINAL_EVENT_UNIT

#include <so/so_inside_event_manage_module_builder.h>

typedef soInsideEventManageModuleBuildConfig<
    32, 40, 4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 1, 1, 0, 2, 1,
    ftInsideEventManageModuleTypes> PeachEventBuildConfig;

struct PeachEventStorage {
    typedef PeachEventBuildConfig B;
    typedef ftInsideEventManageModuleTypes T;
    soInsideEventManageModuleBuilder_MEMBER_LIST

    ~PeachEventStorage();
};

PeachEventStorage::~PeachEventStorage() {
}
