#include <so/event/so_event_system.h>
#pragma force_active on
class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soModelEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;
template<> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soModelEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void fn_27_9FA50(void*, int);
void fn_27_25290(void*, int);
void fn_27_AB510(void*, int);
void fn_27_AB18C(void*, int);
}
extern "C" void* fn_27_3A7AEC(char* p, int flags) {
 if (p) {
  if (p) {
   if (p + 0xCC) {
    if (p + 0xCC) {
     if(p+0x1498) fn_27_63EBC(p+0x1498,-1);
     if(p+0x1480) fn_27_5C674(p+0x1480,-1);
     if(p+0x1328) fn_27_BED74(p+0x1328,-1);
     if(p+0x1190) {
      fn_27_97968(p+0x11E8,-1);
      if(p+0x1190 && p+0x1190) __destroy_arr(p+0x119C,fn_27_9FA50,0x2C,1);
     }
     if(p+0x10F4) fn_27_A1E80(p+0x10F4,-1);
     if(p+0x10DC) fn_27_5AE44(p+0x10DC,-1);
     if(p+0xF78) fn_27_6A3D8(p+0x1088,-1);
     if(p+0xF10) fn_27_565F0(p+0xF1C,-1);
     if(p+0xF04) fn_27_6880C(p+0xF08,-1);
     if(p+0xEDC) __dt__16soStopModuleImplFv(p+0xEDC,-1);
     if(p+0xE6C) fn_27_B5324(p+0xE8C,-1);
     if(p+0xDE8) {
      fn_27_252D0(p+0xE24,-1);
      if(p+0xDE8 && p+0xDE8) __destroy_arr(p+0xDF4,fn_27_25290,0x30,1);
     }
     if(p+0xBDC) {
      fn_27_13C90(p+0xC78,-1);
      if(p+0xBDC) {
       if(p+0xBFC && p+0xBFC && p+0xBFC && p+0xBFC) __destroy_arr(p+0xC08,fn_27_AB510,0x10,4);
       if(p+0xBDC) __destroy_arr(p+0xBE8,fn_27_AB18C,0x14,1);
      }
     }
     if(p+0x9FC) __dt__17soModelModuleImplFv(p+0xB10,-1);
     if(p+0x9CC) __dt__20soResourceModuleImplFv(p+0x9E4,-1);
     if(p+0x9A4) __dt__16soHeapModuleImplFv(p+0x9A4,-1);
     __dt__16soModuleAccesserFv(p+0x8C4,-1);
     if(p+0xCC) {
      reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p+0x888)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p+0x850)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p+0x7F4)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p+0x798)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p+0x73C)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p+0x6E0)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p+0x684)->~soEventUnitWithWorkArea();
      fn_27_18D3DC(p+0x640,-1);
      reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p+0x5E4)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p+0x588)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p+0x52C)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p+0x4D0)->~soEventUnitWithWorkArea();
      fn_27_D597C(p+0x48C,-1);
      reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p+0x430)->~soEventUnitWithWorkArea();
      fn_27_18D6CC(p+0x284,-1);
      fn_27_18D788(p+0x198,-1);
      __dt__23soEventManageModuleImplFv(p+0x184,-1);
      reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p+0xCC)->~soInstanceManagerSimpleEntity();
     }
    }
   }
   fn_27_1D81C8(p,0);
  }
  if(flags>0) __dl__FPv(p);
 }
 return p;
}
