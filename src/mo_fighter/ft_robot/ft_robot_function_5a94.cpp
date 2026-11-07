#pragma force_active on
extern "C" {
void* __dt__23soEventManageModuleImplFv(void*, short);
}

void operator delete(void*);

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

#define DT(T, N, OFF) reinterpret_cast<soEventUnitWithWorkArea<T, N>*>(storage + OFF)->~soEventUnitWithWorkArea()

extern "C" void* fn_120_5A94(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        DT(soCollisionCatchEventObserver, 1, 0x998);
        DT(soTurnEventObserver, 2, 0x954);
        DT(soMotionEventObserver, 1, 0x918);
        DT(soItemManageEventObserver, 1, 0x8E0);
        DT(soCollisionSearchEventObserver, 4, 0x884);
        DT(soCollisionAbsorberEventObserver, 4, 0x828);
        DT(soCollisionReflectorEventObserver, 4, 0x7CC);
        DT(soCollisionShieldEventObserver, 4, 0x770);
        DT(soCaptureEventObserver, 4, 0x714);
        DT(soArticleEventObserver, 5, 0x6AC);
        DT(soModelEventObserver, 4, 0x650);
        DT(soCollisionAttackEventObserver, 4, 0x5F4);
        DT(soCollisionHitEventObserver, 4, 0x598);
        DT(soSituationEventObserver, 4, 0x53C);
        DT(soLinkEventObserver, 4, 0x4E0);
        DT(soDamageEventObserver, 4, 0x484);
        DT(soAnimCmdEventObserver, 40, 0x278);
        DT(soStatusEventObserver, 32, 0xCC);
        __dt__23soEventManageModuleImplFv(storage + 0xB8, destroy);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
