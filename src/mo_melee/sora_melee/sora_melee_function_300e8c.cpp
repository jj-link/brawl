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
DT(fn_27_C31CC)
DT(fn_27_63EBC)
DT(fn_27_5C674)
DT(fn_27_BED74)
DT(fn_27_B64B8)
DT(fn_27_97968)
DT(fn_27_A1E80)
DT(fn_27_5B39C)
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
DT(fn_27_18D498)
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
extern "C" void* fn_27_300E8C(char* self, int flag) {
 if (self) {
  char* p=self;
  if(p+0x1744) fn_27_C31CC(p+0x1744,-1);
  if(p+0x1704) fn_27_63EBC(p+0x1704,-1);
  if(p+0x16ec) fn_27_5C674(p+0x16ec,-1);
  if(p+0x1594) fn_27_BED74(p+0x1594,-1);
  if(p+0x1548) fn_27_B64B8(p+0x1548,-1);
  if(p+0x13b0) {
   fn_27_97968(p+0x1408,-1);
   if(p+0x13b0) { if(p+0x13b0) __destroy_arr(p+0x13bc,fn_27_9FA50,0x2c,1); }
  }
  if(p+0x11d4) {
   if(p+0x1298) {
    if(p+0x12b8) { if(p+0x12b8) {
     short id=*(short*)(p+0x12bc); *(void**)(p+0x12b8)=lbl_27_data_731C;
     if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1)
      soEventSystem::getInstance()->getManager(*(short*)(p+0x12bc))->eraseObserver(*(short*)(p+0x12be),*(short*)(p+0x12c0));
     *(short*)(p+0x12c0)=-1; *(short*)(p+0x12bc)=-1; } }
    RELEASE(0x12ac,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
   }
   if(p+0x121c) {
    if(p+0x123c) { if(p+0x123c) { if(p+0x123c) { if(p+0x123c) __destroy_arr(p+0x1248,fn_27_AB510,0x10,2); } } }
    if(p+0x121c) __destroy_arr(p+0x1228,fn_27_AB18C,0x14,1);
   }
  }
  if(p+0x1130) {
   if(p+0x1154) { if(p+0x1164) __destroy_arr(p+0x1170,fn_27_C940C,0x10,6); }
   if(p+0x1130) {
    RELEASE(0x1144,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
    RELEASE(0x1138,lbl_27_data_1180);
   }
  }
  if(p+0x10fc) fn_27_A1E80(p+0x10fc,-1);
  if(p+0x10c8) fn_27_5B39C(p+0x10c8,-1);
  if(p+0xf64) fn_27_6A3D8(p+0x1074,-1);
  if(p+0xefc) fn_27_565F0(p+0xf08,-1);
  if(p+0xef0) fn_27_6880C(p+0xef4,-1);
  if(p+0xec8) __dt__16soStopModuleImplFv(p+0xec8,-1);
  if(p+0xe58) fn_27_B5324(p+0xe78,-1);
  if(p+0xe1c) fn_27_3544C(p+0xe1c,-1);
  if(p+0xd64) {
   __dt__19soPostureModuleImplFv(p+0xda0,-1);
   if(p+0xd64) { if(p+0xd64) __destroy_arr(p+0xd70,fn_27_25290,0x30,1); }
  }
  if(p+0xb1c) {
   fn_27_13C90(p+0xbf4,-1);
   if(p+0xba4) { if(p+0xba4) __destroy_arr(p+0xbb0,fn_27_137EC,0x2c,1); }
   if(p+0xb1c) {
    if(p+0xb3c) { if(p+0xb3c) { if(p+0xb3c) { if(p+0xb3c) __destroy_arr(p+0xb48,fn_27_AB510,0x10,4); } } }
    if(p+0xb1c) __destroy_arr(p+0xb28,fn_27_AB18C,0x14,1);
   }
  }
  if(p+0x93c) __dt__17soModelModuleImplFv(p+0xa50,-1);
  if(p+0x90c) __dt__20soResourceModuleImplFv(p+0x924,-1);
  if(p+0x8e4) __dt__16soHeapModuleImplFv(p+0x8e4,-1);
  __dt__16soModuleAccesserFv(p+0x804,-1);
  if(p) {
  EVENT(soMotionEventObserver,1,0x7c8);
  EVENT(soItemManageEventObserver,1,0x790);
  EVENT(soCollisionSearchEventObserver,4,0x734);
  EVENT(soCollisionAbsorberEventObserver,4,0x6d8);
  EVENT(soCollisionReflectorEventObserver,4,0x67c);
  EVENT(soCollisionShieldEventObserver,4,0x620);
  EVENT(soCaptureEventObserver,4,0x5c4);
  fn_27_18D3DC(p+0x580,-1);
  fn_27_18D498(p+0x518,-1);
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
