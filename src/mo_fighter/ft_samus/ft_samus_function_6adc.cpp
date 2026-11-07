#include <so/so_instance_manager.h>
class soEventUnit;
template <class Observer, int Capacity> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);
extern "C" void* fn_27_1AA7AC(void*, short);
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
class soModelEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soLinkEventObserver;
class soDamageEventObserver;
class soAnimCmdEventObserver;
class soStatusEventObserver;

extern "C" soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >* fn_94_6ADC(soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >* object, short deleting) {
    if (object != 0) {
        char* storage = reinterpret_cast<char*>(object);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>*>(storage + 0x9D4)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soTurnEventObserver, 2>*>(storage + 0x990)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x954)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x91C)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x8C0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x864)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x808)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x7AC)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x750)->~soEventUnitWithWorkArea();
        fn_27_1AA7AC(storage + 0x6AC, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x650)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x5F4)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x598)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x53C)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soLinkEventObserver, 4>*>(storage + 0x4E0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x484)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>*>(storage + 0x278)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soStatusEventObserver, 32>*>(storage + 0xCC)->~soEventUnitWithWorkArea();
        __dt__23soEventManageModuleImplFv(storage + 0xB8, -1);
        object->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
