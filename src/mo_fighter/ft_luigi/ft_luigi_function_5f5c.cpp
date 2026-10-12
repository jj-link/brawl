void operator delete(void*);
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);

// Declaration-only destructor ABI; shared event implementations stay external.
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

template <class Observer, int Capacity>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
template <class Element> class soInstanceUnit;
template <class Element, int Capacity> class soArrayVector;
template <class Element, class Storage>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

// Embedded event units are destroyed in reverse construction order.
extern "C" void* fn_99_5F5C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>*>(storage + 0x998)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soTurnEventObserver, 2>*>(storage + 0x954)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x918)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x8E0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x884)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x828)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x7CC)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x770)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x714)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soArticleEventObserver, 5>*>(storage + 0x6AC)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x650)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x5F4)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x598)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x53C)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soLinkEventObserver, 4>*>(storage + 0x4E0)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x484)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soAnimCmdEventObserver, 40>*>(storage + 0x278)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soStatusEventObserver, 32>*>(storage + 0xCC)->~soEventUnitWithWorkArea();
        __dt__23soEventManageModuleImplFv(storage + 0xB8, -1);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
