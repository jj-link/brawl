#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#pragma force_active on

class soAnimCmdEventObserver;
template<class T> class soEventObserver { public: static void __vt(int,int); };
extern "C" {
extern char lbl_27_data_731C[];
extern char lbl_27_data_1180[];
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_9FA50(void*,int);
void fn_27_C940C(void*,int);
void fn_27_25290(void*,int);
void fn_27_AB510(void*,int);
void fn_27_AB18C(void*,int);
void fn_27_137EC(void*,int);
#define DT(name) void* name(void*,short);
DT(fn_27_5C674)
DT(fn_27_BED74)
DT(fn_27_97968)
DT(fn_27_A1E80)
DT(fn_27_5AE44)
DT(fn_27_6A3D8)
DT(fn_27_565F0)
DT(fn_27_6880C)
DT(__dt__16soStopModuleImplFv)
DT(fn_27_B5324)
DT(fn_27_3544C)
DT(__dt__19soPostureModuleImplFv)
DT(fn_27_13C90)
DT(__dt__17soModelModuleImplFv)
DT(__dt__20soResourceModuleImplFv)
DT(__dt__16soHeapModuleImplFv)
DT(__dt__16soModuleAccesserFv)
DT(fn_27_18D3DC)
DT(fn_27_D597C)
DT(fn_27_18D6CC)
DT(fn_27_18D788)
DT(__dt__23soEventManageModuleImplFv)
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
EVENT_TYPE(soModelEventObserver,4)
EVENT_TYPE(soCollisionAttackEventObserver,4)
EVENT_TYPE(soCollisionHitEventObserver,4)
EVENT_TYPE(soSituationEventObserver,4)
EVENT_TYPE(soDamageEventObserver,4)
#undef EVENT_TYPE
#define RELEASE(off, table) if (p+off) { if (p+off) { \
 short id=*(short*)(p+off+4); *(void**)(p+off)=table; \
 if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1) \
 soEventSystem::getInstance()->getManager(*(short*)(p+off+4))->eraseObserver(*(short*)(p+off+6),*(short*)(p+off+8)); \
 *(short*)(p+off+8)=-1; *(short*)(p+off+4)=-1; } }
#define EVENT(T,N,offset) reinterpret_cast<soEventUnitWithWorkArea<T,N>*>(p+offset)->~soEventUnitWithWorkArea()
extern "C" void* fn_27_3C86CC(char* self, int flag) {
 if (self) {
  char* p=self;
  if(p+0x16bc) fn_27_5C674(p+0x16bc,-1);
  if(p+0x1564) fn_27_BED74(p+0x1564,-1);
  if(p+0x13cc) {
   fn_27_97968(p+0x1424,-1);
   if(p+0x13cc) { if(p+0x13cc) __destroy_arr(p+0x13d8,fn_27_9FA50,0x2c,1); }
  }
  if(p+0x11ac) {
   if(p+0x12bc) {
    RELEASE(0x12dc,lbl_27_data_731C);
    RELEASE(0x12d0,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
   }
   if(p+0x11f4) {
    if(p+0x1214) { if(p+0x1214) { if(p+0x1214) { if(p+0x1214) __destroy_arr(p+0x1220,fn_27_AB510,0x10,6); } } }
    if(p+0x11f4) __destroy_arr(p+0x1200,fn_27_AB18C,0x14,1);
   }
  }
  if(p+0x1108) {
   if(p+0x112c) { if(p+0x113c) __destroy_arr(p+0x1148,fn_27_C940C,0x10,6); }
   if(p+0x1108) {
    RELEASE(0x111c,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
    RELEASE(0x1110,lbl_27_data_1180);
   }
  }
  if(p+0x10d4) fn_27_A1E80(p+0x10d4,-1);
  if(p+0x10bc) fn_27_5AE44(p+0x10bc,-1);
  if(p+0xf58) fn_27_6A3D8(p+0x1068,-1);
  if(p+0xef0) fn_27_565F0(p+0xefc,-1);
  if(p+0xee4) fn_27_6880C(p+0xee8,-1);
  if(p+0xebc) __dt__16soStopModuleImplFv(p+0xebc,-1);
  if(p+0xe4c) fn_27_B5324(p+0xe6c,-1);
  if(p+0xe10) fn_27_3544C(p+0xe10,-1);
  if(p+0xd58) {
   __dt__19soPostureModuleImplFv(p+0xd94,-1);
   if(p+0xd58) { if(p+0xd58) __destroy_arr(p+0xd64,fn_27_25290,0x30,1); }
  }
  if(p+0xb10) {
   fn_27_13C90(p+0xbe8,-1);
   if(p+0xb98) { if(p+0xb98) __destroy_arr(p+0xba4,fn_27_137EC,0x2c,1); }
   if(p+0xb10) {
    if(p+0xb30) { if(p+0xb30) { if(p+0xb30) { if(p+0xb30) __destroy_arr(p+0xb3c,fn_27_AB510,0x10,4); } } }
    if(p+0xb10) __destroy_arr(p+0xb1c,fn_27_AB18C,0x14,1);
   }
  }
  if(p+0x930) __dt__17soModelModuleImplFv(p+0xa44,-1);
  if(p+0x900) __dt__20soResourceModuleImplFv(p+0x918,-1);
  if(p+0x8d8) __dt__16soHeapModuleImplFv(p+0x8d8,-1);
  __dt__16soModuleAccesserFv(p+0x7f8,-1);
  if(p) {
   EVENT(soMotionEventObserver,1,0x7bc);
   EVENT(soItemManageEventObserver,1,0x784);
   EVENT(soCollisionSearchEventObserver,4,0x728);
   EVENT(soCollisionAbsorberEventObserver,4,0x6cc);
   EVENT(soCollisionReflectorEventObserver,4,0x670);
   EVENT(soCollisionShieldEventObserver,4,0x614);
   EVENT(soCaptureEventObserver,4,0x5b8);
   fn_27_18D3DC(p+0x574,-1);
   EVENT(soModelEventObserver,4,0x518);
   EVENT(soCollisionAttackEventObserver,4,0x4bc);
   EVENT(soCollisionHitEventObserver,4,0x460);
   EVENT(soSituationEventObserver,4,0x404);
   fn_27_D597C(p+0x3c0,-1);
   EVENT(soDamageEventObserver,4,0x364);
   fn_27_18D6CC(p+0x1b8,-1);
   fn_27_18D788(p+0xcc,-1);
   __dt__23soEventManageModuleImplFv(p+0xb8,-1);
   reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>,19> >*>(p)->~soInstanceManagerSimpleEntity();
  }
  if(flag>0) __dl__FPv(self);
 }
 return self;
}