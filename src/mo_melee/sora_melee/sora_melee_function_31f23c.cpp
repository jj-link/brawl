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
DT(fn_27_D5B4C)
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
extern "C" void* fn_27_31F23C(char* self, int flag) {
 if (self) {
  char* p=self;
  if(p+0x16b0) fn_27_5C674(p+0x16b0,-1);
  if(p+0x1558) fn_27_BED74(p+0x1558,-1);
  if(p+0x13c0) {
   fn_27_97968(p+0x1418,-1);
   if(p+0x13c0) { if(p+0x13c0) __destroy_arr(p+0x13cc,fn_27_9FA50,0x2c,1); }
  }
  if(p+0x11a0) {
   if(p+0x12b0) {
    RELEASE(0x12d0,lbl_27_data_731C);
    RELEASE(0x12c4,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
   }
   if(p+0x11e8) {
    if(p+0x1208) { if(p+0x1208) { if(p+0x1208) { if(p+0x1208) __destroy_arr(p+0x1214,fn_27_AB510,0x10,6); } } }
    if(p+0x11e8) __destroy_arr(p+0x11f4,fn_27_AB18C,0x14,1);
   }
  }
  if(p+0x10fc) {
   if(p+0x1120) { if(p+0x1130) __destroy_arr(p+0x113c,fn_27_C940C,0x10,6); }
   if(p+0x10fc) {
    RELEASE(0x1110,(void*)soEventObserver<soAnimCmdEventObserver>::__vt);
    RELEASE(0x1104,lbl_27_data_1180);
   }
  }
  if(p+0x10c8) fn_27_A1E80(p+0x10c8,-1);
  if(p+0x10b0) fn_27_5AE44(p+0x10b0,-1);
  if(p+0xf4c) fn_27_6A3D8(p+0x105c,-1);
  if(p+0xee4) fn_27_565F0(p+0xef0,-1);
  if(p+0xed8) fn_27_6880C(p+0xedc,-1);
  if(p+0xeb0) __dt__16soStopModuleImplFv(p+0xeb0,-1);
  if(p+0xe40) fn_27_B5324(p+0xe60,-1);
  if(p+0xe04) fn_27_3544C(p+0xe04,-1);
  if(p+0xd4c) {
   __dt__19soPostureModuleImplFv(p+0xd88,-1);
   if(p+0xd4c) { if(p+0xd4c) __destroy_arr(p+0xd58,fn_27_25290,0x30,1); }
  }
  if(p+0xb04) {
   fn_27_13C90(p+0xbdc,-1);
   if(p+0xb8c) { if(p+0xb8c) __destroy_arr(p+0xb98,fn_27_137EC,0x2c,1); }
   if(p+0xb04) {
    if(p+0xb24) { if(p+0xb24) { if(p+0xb24) { if(p+0xb24) __destroy_arr(p+0xb30,fn_27_AB510,0x10,4); } } }
    if(p+0xb04) __destroy_arr(p+0xb10,fn_27_AB18C,0x14,1);
   }
  }
  if(p+0x924) __dt__17soModelModuleImplFv(p+0xa38,-1);
  if(p+0x8f4) __dt__20soResourceModuleImplFv(p+0x90c,-1);
  if(p+0x8cc) __dt__16soHeapModuleImplFv(p+0x8cc,-1);
  __dt__16soModuleAccesserFv(p+0x7ec,-1);
  if(p) {
   EVENT(soMotionEventObserver,1,0x7b0);
   EVENT(soItemManageEventObserver,1,0x778);
   EVENT(soCollisionSearchEventObserver,4,0x71c);
   EVENT(soCollisionAbsorberEventObserver,4,0x6c0);
   EVENT(soCollisionReflectorEventObserver,4,0x664);
   EVENT(soCollisionShieldEventObserver,4,0x608);
   EVENT(soCaptureEventObserver,4,0x5ac);
   fn_27_18D3DC(p+0x568,-1);
   fn_27_D5B4C(p+0x518,-1);
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
