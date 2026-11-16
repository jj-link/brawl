#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

class soAnimCmdEventObserver;
class soLinkEventObserver;
class soKineticEnergy;
template<class T> class soEventObserver { public: static void __vt(int,int); };
template<> class soEventUnitWrapper<soLinkEventObserver> { public: static unsigned char __vt[]; };
template<> class soInstanceUnitFullProperty<soKineticEnergy*> { public: unsigned char pad[0xc]; ~soInstanceUnitFullProperty(); };
template<> class soInstanceUnitFullProperty<soLinkEventObserver*> { public: unsigned char pad[0xc]; ~soInstanceUnitFullProperty(); };
struct DtorHolderKE { char pad[0xC]; soInstanceUnitFullProperty<soKineticEnergy*> arr[2]; ~DtorHolderKE() { } };
struct DtorHolderLE { char pad[0xC]; soInstanceUnitFullProperty<soLinkEventObserver*> arr[1]; ~DtorHolderLE() { } };

extern "C" {
extern char lbl_27_data_1180[];
extern char lbl_27_data_21D78[];
extern char lbl_27_data_25948[];
extern char lbl_27_data_25F88[];
extern char lbl_27_data_25FD8[];
extern char lbl_27_data_26028[];
extern char lbl_27_data_26050[];
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_27_9FA50(void*,int);
void fn_27_50588(void*,int);
void fn_27_2E888(void*,int);
void fn_27_84358(void*,int);
void fn_27_84198(void*,int);
void fn_27_845D8(void*,int);
void fn_27_84258(void*,int);
void fn_27_84458(void*,int);
void fn_27_84398(void*,int);
#define DT(name) void* name(void*,short);
DT(fn_27_5BFA0)
DT(fn_27_97968)
DT(fn_27_A1E80)
DT(fn_27_B5324)
DT(fn_27_3544C)
DT(fn_27_25740)
DT(fn_27_252D0)
DT(__dt__16soHeapModuleImplFv)
DT(__dt__16soModuleAccesserFv)
DT(__dt__23soEventManageModuleImplFv)
#undef DT
}

#define RELEASE(off, table) if (p+off) { if (p+off) { \
 short id=*(short*)(p+off+4); *(void**)(p+off)=table; \
 if (soEventSystem::getInstance()->getInstanceManager().isContain(id)==1) \
 soEventSystem::getInstance()->getManager(*(short*)(p+off+4))->eraseObserver(*(short*)(p+off+6),*(short*)(p+off+8)); \
 *(short*)(p+off+8)=-1; *(short*)(p+off+4)=-1; } }
#define RELEASE_UNIT(off, table) if (p+off) { if (p+off) { \
 short id=*(short*)(p+off+4); *(void**)(p+off)=table; \
 if (id != -1) soEventSystem::getInstance()->getManager(*(short*)(p+off+4))->eraseUnit(*(short*)(p+off+6)); } }

extern "C" void* fn_27_13F86C(char* self, int flag) {
 if (self) {
  char* p=self;
  if (p) {
  if(p+0x818) fn_27_5BFA0(p+0x818,-1);
  if(p+0x688) {
   fn_27_97968(p+0x6D4,-1);
   if(p+0x688) { if(p+0x688) __destroy_arr(p+0x694,fn_27_9FA50,0x2c,1); }
  }
  if(p+0x5bc) {
   if(p+0x5ec) { (*reinterpret_cast<DtorHolderKE*>(p+0x5fc)).~DtorHolderKE(); }
   if(p+0x5bc) { RELEASE(0x5dc,lbl_27_data_1180); if(p+0x5bc) { RELEASE(0x5c4,(void*)soEventObserver<soAnimCmdEventObserver>::__vt); } }
  }
  if(p+0x584) fn_27_A1E80(p+0x584,-1);
  if(p+0x50c) fn_27_B5324(p+0x52c,-1);
  if(p+0x4d0) fn_27_3544C(p+0x4d0,-1);
  if(p+0x428) {
   fn_27_25740(p+0x478,-1);
   if(p+0x428) __destroy_arr(p+0x434,fn_27_2E888,0x44,1);
  }
  if(p+0x3e0) fn_27_252D0(p+0x3e4,-1);
  if(p+0x3b4) __dt__16soHeapModuleImplFv(p+0x3b4,-1);
  __dt__16soModuleAccesserFv(p+0x2d4,-1);
  if(p) {
   if(p+0x294) {
    if(p+0x2a0 && p+0x2b0) __destroy_arr(p+0x2bc,fn_27_84358,0xc,1);
    RELEASE_UNIT(0x294,lbl_27_data_21D78);
   }
   if(p+0x258) {
    if(p+0x264 && p+0x274) __destroy_arr(p+0x280,fn_27_84198,0xc,1);
    RELEASE_UNIT(0x258,lbl_27_data_25948);
   }
   if(p+0x220) {
    if(p+0x22c && p+0x23c) __destroy_arr(p+0x248,fn_27_845D8,0xc,1);
    RELEASE_UNIT(0x220,lbl_27_data_25F88);
   }
   if(p+0x1e4) {
    if(p+0x1f0 && p+0x200) __destroy_arr(p+0x20c,fn_27_84258,0xc,1);
    RELEASE_UNIT(0x1e4,lbl_27_data_25FD8);
   }
   if(p+0x1ac) {
    if(p+0x1b8) (*reinterpret_cast<DtorHolderLE*>(p+0x1c8)).~DtorHolderLE();
    RELEASE_UNIT(0x1ac,soEventUnitWrapper<soLinkEventObserver>::__vt);
   }
   if(p+0x128) {
    if(p+0x134 && p+0x144) __destroy_arr(p+0x150,fn_27_84458,0xc,7);
    RELEASE_UNIT(0x128,lbl_27_data_26028);
   }
   if(p+0xcc) {
    if(p+0xd8 && p+0xe8) __destroy_arr(p+0xf4,fn_27_84398,0xc,4);
    RELEASE_UNIT(0xcc,lbl_27_data_26050);
   }
   __dt__23soEventManageModuleImplFv(p+0xb8,-1);
   if(p) { if(p+0x14) __destroy_arr(p+0x20,fn_27_50588,8,0x13); }
  }
  }
  if(flag>0) __dl__FPv(self);
 }
 return self;
}
