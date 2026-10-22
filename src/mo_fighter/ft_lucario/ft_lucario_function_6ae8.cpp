#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);
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

#define D(T,N,O) reinterpret_cast<soEventUnitWithWorkArea<T, N>*>(s + O)->~soEventUnitWithWorkArea();

extern "C" void* fn_118_6AE8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* s = static_cast<unsigned char*>(object);
        D(soCollisionCatchEventObserver,1,0x998)
        D(soTurnEventObserver,2,0x954)
        D(soMotionEventObserver,1,0x918)
        D(soItemManageEventObserver,1,0x8E0)
        D(soCollisionSearchEventObserver,4,0x884)
        D(soCollisionAbsorberEventObserver,4,0x828)
        D(soCollisionReflectorEventObserver,4,0x7CC)
        D(soCollisionShieldEventObserver,4,0x770)
        D(soCaptureEventObserver,4,0x714)
        D(soArticleEventObserver,5,0x6AC)
        D(soModelEventObserver,4,0x650)
        D(soCollisionAttackEventObserver,4,0x5F4)
        D(soCollisionHitEventObserver,4,0x598)
        D(soSituationEventObserver,4,0x53C)
        D(soLinkEventObserver,4,0x4E0)
        D(soDamageEventObserver,4,0x484)
        D(soAnimCmdEventObserver,40,0x278)
        D(soStatusEventObserver,32,0xCC)
        __dt__23soEventManageModuleImplFv(s + 0xB8, -1);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
