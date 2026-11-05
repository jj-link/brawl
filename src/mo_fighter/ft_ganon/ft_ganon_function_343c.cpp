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
void operator delete(void*);
extern "C" {
void* fn_27_D3B50(void*, short);
void* fn_109_39C8(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_109_2230(void*, short);
void* fn_109_2154(void*, short);
void* fn_109_21F0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_109_3A08(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_109_3A94(void*, short);
void* fn_27_BED74(void*, short);
void* fn_109_2DF0(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_109_30A8(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_109_3AF0(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_109_3BEC(void*, short);
void* fn_109_1F10(void*, short);
void* fn_109_3C2C(void*, short);
void* fn_109_3C8C(void*, short);
void* fn_109_3D10(void*, short);
void* fn_27_1A301C(void*, short);
void* fn_109_3D70(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_109_3B50(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_109_3E10(void*, short);
void* fn_109_3F44(void*, short);
void* fn_109_3FA0(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_109_4014(void*, short);
void* fn_27_565F0(void*, short);
void* fn_109_4080(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_5CC1C(void*, short);
void* fn_27_D3080(void*, short);
void* fn_109_40E0(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_CB800(void*, short);
void* fn_27_19CF10(void*, short);
void* fn_109_4164(void*, short);
void* fn_109_4230(void*, short);
void* fn_109_428C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_109_4300(void*, short);
void* fn_109_435C(void*, short);
void* fn_109_43E4(void*, short);
void* fn_109_4450(void*, short);
void* fn_109_4508(void*, short);
void* fn_109_4548(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}
extern "C" void* fn_109_343C(void* object, short deleting) {
 if (object) {
 unsigned char* p = static_cast<unsigned char*>(object);
 if (p+0x2e44) fn_27_D3B50(p+0x2e44,0);
 if (object) {
 if (p+0x2e00) fn_109_39C8(p+0x2e00,0);
 fn_27_1DBB60(p+0x2dc8,-1);
 if (p+0xcc) {
 if (p+0x2818) {
 if (p+0x2cc8) { fn_109_2230(p+0x2d18,-1); fn_109_2154(p+0x2cc8,-1); }
if (p+0x2b9c) { fn_109_2154(p+0x2c78,-1); fn_109_21F0(p+0x2c5c,-1); fn_109_2230(p+0x2bb0,-1); if (p+0x2b9c) fn_27_C7770(p+0x2b9c,-1); }
fn_109_3A08(p+0x2a70,-1);
if (p+0x2944) { fn_109_2154(p+0x2a20,-1); fn_109_21F0(p+0x2a04,-1); fn_109_2230(p+0x2958,-1); if (p+0x2944) fn_27_C7770(p+0x2944,-1); }
if (p+0x2818) { fn_109_2154(p+0x28f4,-1); fn_109_21F0(p+0x28d8,-1); fn_109_2230(p+0x282c,-1); if (p+0x2818) fn_27_C7770(p+0x2818,-1); }
}
if(p+0xcc) {
if(p+0x27d4) fn_27_63EBC(p+0x27d4,-1);
fn_109_3A94(p+0x27bc,-1);
if(p+0x2664) fn_27_BED74(p+0x2664,-1);
fn_109_2DF0(p+0x2618,-1);
if(p+0x2480) {
 fn_27_97968(p+0x24d8,-1); fn_27_1CCCC(p+0x24c8,-1); fn_109_30A8(p+0x24bc,-1);
 if(p+0x2480) fn_27_CBF58(p+0x2480,-1);
}
fn_109_3AF0(p+0x2420,-1);
if(p+0x236c) {
 if(p+0x239c) { fn_27_1A241C(p+0x23ac,-1); fn_109_3BEC(p+0x239c,0); }
 if(p+0x236c) { fn_109_1F10(p+0x238c,0); fn_109_3C2C(p+0x236c,0); }
}
if(p+0x21a8) {
 fn_109_3C8C(p+0x22bc,-1); fn_109_3D10(p+0x22a8,-1);
 if(p+0x2294) fn_27_1A301C(p+0x2294,-1);
 if(p+0x21f0) {
  fn_109_3D70(p+0x227c,-1);
  if(p+0x2210) if(p+0x2210) if(p+0x2210) fn_27_1A1E70(p+0x2210,-1);
  fn_27_CD934(p+0x21f0,-1);
 }
 if(p+0x21b8) fn_109_3B50(p+0x21cc,-1);
 fn_27_C74E8(p+0x21a8,-1);
}
fn_109_3E10(p+0x2104,-1); fn_109_3F44(p+0x20d0,-1); fn_109_3FA0(p+0x205c,-1);
if(p+0x2028) fn_27_5B39C(p+0x2028,-1);
fn_109_4014(p+0x1ec4,-1);
if(p+0x1e5c) fn_27_565F0(p+0x1e68,-1);
fn_109_4080(p+0x1e50,-1);
if(p+0x1e28) __dt__16soStopModuleImplFv(p+0x1e28,-1);
if(p+0x1ccc) { fn_27_5CC1C(p+0x1d78,-1); if(p+0x1ccc) fn_27_D3080(p+0x1ccc,-1); }
fn_109_40E0(p+0x1368,-1);
if(p+0xf7c) { __dt__27soCollisionAttackModuleImplFv(p+0x12c8,-1); fn_27_82AD4(p+0x12c4,-1); fn_27_CB800(p+0x11c8,-1); fn_27_19CF10(p+0xf7c,-1); }
fn_109_4164(p+0xf18,-1); fn_109_4230(p+0xedc,-1); fn_109_428C(p+0xe24,-1);
if(p+0xbdc) { fn_27_13C90(p+0xcb4,-1); fn_27_21038(p+0xca0,-1); fn_109_4300(p+0xc64,-1); fn_109_435C(p+0xbdc,-1); }
fn_109_43E4(p+0x9fc,-1); fn_109_4450(p+0x9cc,-1); fn_109_4508(p+0x9bc,-1); fn_109_4548(p+0x9a4,-1);
__dt__16soModuleAccesserFv(p+0x8c4,-1);
if(p+0xcc) {
reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p+0x888)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p+0x850)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p+0x7f4)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p+0x798)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p+0x73c)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p+0x6e0)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p+0x684)->~soEventUnitWithWorkArea();
fn_27_18D3DC(p+0x640,-1);
reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p+0x5e4)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p+0x588)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p+0x52c)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p+0x4d0)->~soEventUnitWithWorkArea();
fn_27_D597C(p+0x48c,-1);
reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p+0x430)->~soEventUnitWithWorkArea();
fn_27_18D6CC(p+0x284,-1); fn_27_18D788(p+0x198,-1);
__dt__23soEventManageModuleImplFv(p+0x184,-1);
reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p+0xcc)->~soInstanceManagerSimpleEntity();
}
}
}
fn_27_1D81C8(object,0);
}
if(deleting>0) operator delete(object);
}
return object;
}