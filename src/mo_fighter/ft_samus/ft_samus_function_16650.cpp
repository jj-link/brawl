#include <so/event/so_event_system.h>
#include <so/event/so_event_manage_module_impl.h>
#pragma force_active on
class soCollisionCatchEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
class soTurnEventObserver;
template <> class soEventUnitWithWorkArea<soTurnEventObserver, 2> { public: ~soEventUnitWithWorkArea(); };
class soMotionEventObserver;
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
class soItemManageEventObserver;
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
class soCollisionSearchEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionAbsorberEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionReflectorEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionShieldEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCaptureEventObserver;
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soArticleEventObserver;
template <> class soEventUnitWithWorkArea<soArticleEventObserver, 5> { public: ~soEventUnitWithWorkArea(); };
class soModelEventObserver;
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionAttackEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionHitEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soSituationEventObserver;
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soLinkEventObserver;
template <> class soEventUnitWithWorkArea<soLinkEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soDamageEventObserver;
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soAnimCmdEventObserver;
template <> class soEventUnitWithWorkArea<soAnimCmdEventObserver, 40> { public: ~soEventUnitWithWorkArea(); };
class soStatusEventObserver;
template <> class soEventUnitWithWorkArea<soStatusEventObserver, 32> { public: ~soEventUnitWithWorkArea(); };
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_16650(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>*>(storage + 0x998)->soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soTurnEventObserver, 2>*>(storage + 0x954)->soEventUnitWithWorkArea<soTurnEventObserver, 2>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x918)->soEventUnitWithWorkArea<soMotionEventObserver, 1>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x8E0)->soEventUnitWithWorkArea<soItemManageEventObserver, 1>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x884)->soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x828)->soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x7CC)->soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x770)->soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x714)->soEventUnitWithWorkArea<soCaptureEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soArticleEventObserver, 5>*>(storage + 0x6AC)->soEventUnitWithWorkArea<soArticleEventObserver, 5>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x650)->soEventUnitWithWorkArea<soModelEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x5F4)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x598)->soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x53C)->soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soLinkEventObserver, 4>*>(storage + 0x4E0)->soEventUnitWithWorkArea<soLinkEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x484)->soEventUnitWithWorkArea<soDamageEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>*>(storage + 0x278)->soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soStatusEventObserver, 32>*>(storage + 0xCC)->soEventUnitWithWorkArea<soStatusEventObserver, 32>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventManageModuleImpl*>(storage + 0xB8)->~soEventManageModuleImpl();
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
