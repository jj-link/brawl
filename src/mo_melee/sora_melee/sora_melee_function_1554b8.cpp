#include <so/event/so_event_system.h>
#pragma force_active on
class soGimmickEventObserver;
template <> class soEventUnitWrapper<soGimmickEventObserver> {
public:
    static unsigned char __RTTI[];
};
class UnitView {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual int getObserverListSub();
};
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(int,int); virtual int slot6(int);
virtual void slot7(); virtual void* slot8(int);
};
struct OwnerSub { char pad[0x64]; Object_vptr_0* obj; };
struct Owner { char pad[0xd8]; OwnerSub* sub; };
struct Arg { char pad[2]; unsigned short val2; int val4; int val8; };
struct Self { char pad[5]; signed char flag; };
struct Pack { void* vt; short a,b; int c,d; };
struct Params { int id,val; };
extern "C" {
extern char lbl_27_data_2DC60[],lbl_27_data_2DC20[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*,long,const void*,const void*,short);
void fn_27_AA42C(void*,void*,void*,int);
}
inline int getUnit(soEventManager* m, short id) {
UnitView* u=
(UnitView*)__dynamic_cast(m->getEventUnit(id),0,soEventUnitWrapper<soGimmickEventObserver>::__RTTI,__RTTI__11soEventUnit,0);
if(u==0) return 0;
return (int)u->getObserverListSub();
}
extern "C" void fn_27_1554B8(Self* self,Owner* owner,Arg* arg) {
owner->sub->obj->slot5(arg->val4,0x10000015);
owner->sub->obj->slot5(arg->val8,0x10000016);
owner->sub->obj->slot5(arg->val2,0x10000017);
short n=(short)arg->val8;
int res;
Pack pk;
res=0;
pk.vt=lbl_27_data_2DC60; pk.a=n; pk.b=3; pk.c=0;
if(n>0 && n>-1) {
if(soEventSystem::getInstance()->getInstanceManager().isContain(n)) {
if(soEventSystem::getInstance()->getManager(pk.a)->getObserverCapacity(pk.b)==0) pk.c=res;
else { soEventManager* m; short id=pk.b; m=soEventSystem::getInstance()->getManager(pk.a); if(m->getObserverCapacity(id)==0) res=0; else res=getUnit(m,id); pk.c=res; }
}
}
pk.d=-1; pk.vt=lbl_27_data_2DC20;
if(self->flag>0) { Params p; p.id=0x2c;p.val=0;fn_27_AA42C(&pk,&p,owner,-1); }
else { Params p; p.id=0x2d;p.val=0;fn_27_AA42C(&pk,&p,owner,-1); }
}
