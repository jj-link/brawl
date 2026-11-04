#include <so/so_instance_manager.h>
class soEventUnit;
template <class Observer, int Capacity> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);
#pragma force_active on
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
extern "C" void* fn_97_7EBC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>*>(storage + 0x998)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soTurnEventObserver, 2>*>(storage + 0x954)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x918)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x8e0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x884)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x828)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x7cc)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x770)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x714)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soArticleEventObserver, 5>*>(storage + 0x6ac)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x650)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x5f4)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x598)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x53c)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soLinkEventObserver, 4>*>(storage + 0x4e0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x484)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>*>(storage + 0x278)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soStatusEventObserver, 32>*>(storage + 0xcc)->~soEventUnitWithWorkArea();
        __dt__23soEventManageModuleImplFv(storage + 0xb8, -1);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}