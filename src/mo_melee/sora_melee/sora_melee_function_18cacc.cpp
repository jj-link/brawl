#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6();
};
class soAnimCmdEventObserver;
template<class T> class soEventObserver { public: static void __vt(int,int); };
extern "C" {
extern char lbl_27_data_1180[];
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_9FB88(void*,int);
void fn_27_9FA50(void*,int);
void fn_27_C940C(void*,int);
void fn_27_137EC(void*,int);
void fn_27_AB510(void*,int);
void fn_27_AB18C(void*,int);
#define DT(name) void* name(void*,short);
DT(__dt__16acCmdInterpreterFv)
DT(fn_27_5C674)
DT(fn_27_BED74)
DT(fn_27_B64B8)
DT(fn_27_10424)
DT(fn_27_97968)
DT(fn_27_A1E80)
DT(fn_27_5AE44)
DT(fn_27_6A3D8)
DT(fn_27_6880C)
DT(fn_27_B5324)
DT(fn_27_252D0)
DT(fn_27_13C90)
DT(__dt__17soModelModuleImplFv)
DT(__dt__20soResourceModuleImplFv)
DT(__dt__16soHeapModuleImplFv)
DT(__dt__16soModuleAccesserFv)
DT(fn_27_18D3DC)
DT(fn_27_18D498)
DT(fn_27_D597C)
DT(fn_27_18D6CC)
DT(fn_27_18D788)
DT(__dt__23soEventManageModuleImplFv)
DT(fn_27_1D81C8)
#undef DT
}
#define EVENT_TYPE(T,N) class T; template<> class soEventUnitWithWorkArea<T,N> { public: ~soEventUnitWithWorkArea(); };
EVENT_TYPE(soMotionEventObserver,1)
EVENT_TYPE(soItemManageEventObserver,1)
EVENT_TYPE(soCollisionSearchEventObserver,4)
EVENT_TYPE(soCollisionAbsorberEventObserver,4)
EVENT_TYPE(soCollisionReflectorEventObserver,4)
EVENT_TYPE(soCollisionShieldEventObserver,4)
EVENT_TYPE(soCaptureEventObserver,4)
EVENT_TYPE(soCollisionAttackEventObserver,4)
EVENT_TYPE(soCollisionHitEventObserver,4)
EVENT_TYPE(soSituationEventObserver,4)
EVENT_TYPE(soDamageEventObserver,4)
#undef EVENT_TYPE
struct Obs { void* vt; short manager; short event; short send; short pad; };
struct Obj { char pad[0x10b4]; Obs a; Obs b; };
#define RELEASE(ent, table) if (&(ent)) { if (&(ent)) { \
 short id=(ent).manager; (ent).vt=table; \
 if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1) \
 soEventSystem::getInstance()->getManager((ent).manager)->eraseObserver((ent).event,(ent).send); \
 (ent).send=-1; (ent).manager=-1; } }
#define EVENT(T,N,offset) reinterpret_cast<soEventUnitWithWorkArea<T,N>*>(p+offset)->~soEventUnitWithWorkArea()
extern "C" Obj* fn_27_18CACC(Obj* self, int flag) {
 if (self) {
  char* p=(char*)self;
  if (self) {
  if(p+0xcc) {
   if(p+0x1564) { if(p+0x1568) { if(p+0x1644) __dt__16acCmdInterpreterFv(p+0x1644,0); } }
   if(p+0xcc) {
    if(p+0x1548) fn_27_5C674(p+0x1548,-1);
    if(p+0x13f0) fn_27_BED74(p+0x13f0,-1);
    if(p+0x13a4) fn_27_B64B8(p+0x13a4,-1);
    if(p+0x1354) fn_27_10424(p+0x1358,-1);
    if(p+0x11b4) {
     fn_27_97968(p+0x1218,-1);
     if(p+0x11ec) { if(p+0x11ec) __destroy_arr(p+0x11f8,fn_27_9FB88,0xc,1); }
     if(p+0x11b4) { if(p+0x11b4) __destroy_arr(p+0x11c0,fn_27_9FA50,0x2c,1); }
    }
    if(p+0x10ac) {
     if(p+0x10d0) { if(p+0x10e0) __destroy_arr(p+0x10ec,fn_27_C940C,0x10,6); }
     if(p+0x10ac) {
      RELEASE(self->b,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
      RELEASE(self->a,lbl_27_data_1180);
     }
    }
    if(p+0x1078) fn_27_A1E80(p+0x1078,-1);
    if(p+0x1060) fn_27_5AE44(p+0x1060,-1);
    if(p+0xefc) fn_27_6A3D8(p+0x100c,-1);
    if(p+0xeec) fn_27_6880C(p+0xef0,-1);
    if(p+0xe7c) fn_27_B5324(p+0xe9c,-1);
    if(p+0xe30) fn_27_252D0(p+0xe34,-1);
    if(p+0xbe8) {
     fn_27_13C90(p+0xcc0,-1);
     if(p+0xc70) { if(p+0xc70) __destroy_arr(p+0xc7c,fn_27_137EC,0x2c,1); }
     if(p+0xbe8) {
      if(p+0xc08) { if(p+0xc08) { if(p+0xc08) { if(p+0xc08) __destroy_arr(p+0xc14,fn_27_AB510,0x10,4); } } }
      if(p+0xbe8) __destroy_arr(p+0xbf4,fn_27_AB18C,0x14,1);
     }
    }
    if(p+0xa08) __dt__17soModelModuleImplFv(p+0xb1c,-1);
    if(p+0x9d8) __dt__20soResourceModuleImplFv(p+0x9f0,-1);
    if(p+0x9b0) __dt__16soHeapModuleImplFv(p+0x9b0,-1);
    __dt__16soModuleAccesserFv(p+0x8d0,-1);
    if(p+0xcc) {
     EVENT(soMotionEventObserver,1,0x894);
     EVENT(soItemManageEventObserver,1,0x85c);
     EVENT(soCollisionSearchEventObserver,4,0x800);
     EVENT(soCollisionAbsorberEventObserver,4,0x7a4);
     EVENT(soCollisionReflectorEventObserver,4,0x748);
     EVENT(soCollisionShieldEventObserver,4,0x6ec);
     EVENT(soCaptureEventObserver,4,0x690);
     fn_27_18D3DC(p+0x64c,-1);
     fn_27_18D498(p+0x5e4,-1);
     EVENT(soCollisionAttackEventObserver,4,0x588);
     EVENT(soCollisionHitEventObserver,4,0x52c);
     EVENT(soSituationEventObserver,4,0x4d0);
     fn_27_D597C(p+0x48c,-1);
     EVENT(soDamageEventObserver,4,0x430);
     fn_27_18D6CC(p+0x284,-1);
     fn_27_18D788(p+0x198,-1);
     __dt__23soEventManageModuleImplFv(p+0x184,-1);
     reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>,19> >*>(p+0xcc)->~soInstanceManagerSimpleEntity();
    }
   }
  }
  fn_27_1D81C8(self,0);
  }
  if(flag>0) __dl__FPv(self);
 }
 return self;
}
