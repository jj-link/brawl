void operator delete(void*);

// Destructor-only ABI declarations: layouts and inline destructor definitions
// are intentionally not imported. All members below call existing out-of-line
// destructors; no objects of these declaration-only types are constructed here.
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
class soEventUnit;

template <class Observer, int Count>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

class soEventManageModuleImpl {
public:
    ~soEventManageModuleImpl();
};

template <class T> class soInstanceUnit;
template <class T, int Count> class soArrayVector;
template <class T, class Storage>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" void* fn_98_7230(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        // Event work areas are embedded and destroyed in reverse order.
        // The aggregate alone owns the allocation.
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>*>(members + 0x998)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soTurnEventObserver, 2>*>(members + 0x954)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(members + 0x918)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(members + 0x8E0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(members + 0x884)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(members + 0x828)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(members + 0x7CC)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(members + 0x770)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(members + 0x714)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soArticleEventObserver, 5>*>(members + 0x6AC)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(members + 0x650)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(members + 0x5F4)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(members + 0x598)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(members + 0x53C)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soLinkEventObserver, 4>*>(members + 0x4E0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(members + 0x484)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>*>(members + 0x278)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soStatusEventObserver, 32>*>(members + 0xCC)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventManageModuleImpl*>(members + 0xB8)->~soEventManageModuleImpl();
        typedef soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > EventInstances;
        reinterpret_cast<EventInstances*>(object)->~EventInstances();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
