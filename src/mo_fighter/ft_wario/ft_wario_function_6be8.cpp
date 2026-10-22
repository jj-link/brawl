#pragma force_active on
void operator delete(void*);
struct soEventUnit;
template<class T> struct soInstanceUnit {};
template<class T, int N> struct soArrayVector {};
template<class T, class V> struct soInstanceManagerSimpleEntity { ~soInstanceManagerSimpleEntity(); };
struct soEventManageModuleImpl { ~soEventManageModuleImpl(); };
template<class T, int N> struct soEventUnitWithWorkArea { ~soEventUnitWithWorkArea(); };
struct soCollisionCatchEventObserver; struct soTurnEventObserver; struct soMotionEventObserver; struct soItemManageEventObserver;
struct soCollisionSearchEventObserver; struct soCollisionAbsorberEventObserver; struct soCollisionReflectorEventObserver;
struct soCollisionShieldEventObserver; struct soCaptureEventObserver; struct soArticleEventObserver; struct soModelEventObserver;
struct soCollisionAttackEventObserver; struct soCollisionHitEventObserver; struct soSituationEventObserver; struct soLinkEventObserver;
struct soDamageEventObserver; struct soAnimCmdEventObserver; struct soStatusEventObserver;
typedef soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > Base;
#define D(T,N,off) ((soEventUnitWithWorkArea<T,N>*)(s + off))->~soEventUnitWithWorkArea<T,N>()
extern "C" Base* fn_110_6BE8(Base* p, short del) {
    if (p) {
        char* s = (char*)p;
        D(soCollisionCatchEventObserver,1,0x998);
        D(soTurnEventObserver,2,0x954);
        D(soMotionEventObserver,1,0x918);
        D(soItemManageEventObserver,1,0x8E0);
        D(soCollisionSearchEventObserver,4,0x884);
        D(soCollisionAbsorberEventObserver,4,0x828);
        D(soCollisionReflectorEventObserver,4,0x7CC);
        D(soCollisionShieldEventObserver,4,0x770);
        D(soCaptureEventObserver,4,0x714);
        D(soArticleEventObserver,5,0x6AC);
        D(soModelEventObserver,4,0x650);
        D(soCollisionAttackEventObserver,4,0x5F4);
        D(soCollisionHitEventObserver,4,0x598);
        D(soSituationEventObserver,4,0x53C);
        D(soLinkEventObserver,4,0x4E0);
        D(soDamageEventObserver,4,0x484);
        D(soAnimCmdEventObserver,40,0x278);
        D(soStatusEventObserver,32,0xCC);
        ((soEventManageModuleImpl*)(s + 0xB8))->~soEventManageModuleImpl();
        p->~Base();
        if (del > 0) operator delete(p);
    }
    return p;
}
