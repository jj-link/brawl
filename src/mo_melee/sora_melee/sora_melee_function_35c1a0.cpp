#include <so/event/so_event_system.h>
#pragma force_active on
void operator delete(void*);
class soMotionEventObserver;
template<> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
class soItemManageEventObserver;
template<> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
class soCollisionSearchEventObserver;
template<> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionAbsorberEventObserver;
template<> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionReflectorEventObserver;
template<> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionShieldEventObserver;
template<> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCaptureEventObserver;
template<> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soModelEventObserver;
template<> class soEventUnitWithWorkArea<soModelEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionAttackEventObserver;
template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionHitEventObserver;
template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soSituationEventObserver;
template<> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soDamageEventObserver;
template<> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
extern "C" {
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_B64B8(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_27_A0C34(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_C96C0(void*, short);
void* fn_27_D2AA4(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_CBDE8(void*, short);
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
}
extern "C" void* fn_27_35C1A0(char* p, int flag) {
if (p) {
 if (p) {
  if (p+0xcc) {
   if (p+0xcc) {
if (p+0x14e8) fn_27_63EBC(p+0x14e8,-1);
if (p+0x14d0) fn_27_5C674(p+0x14d0,-1);
if (p+0x1378) fn_27_BED74(p+0x1378,-1);
if (p+0x132c) fn_27_B64B8(p+0x132c,-1);
if(p+0x1194) { fn_27_97968(p+0x11ec,-1); fn_27_1CCCC(p+0x11dc,-1); if(p+0x11d0) fn_27_A0C34(p+0x11d0,-1); if(p+0x1194) fn_27_CBF58(p+0x1194,-1); }
if(p+0x10f8) fn_27_A1E80(p+0x10f8,-1);
if(p+0x10e0) fn_27_5AE44(p+0x10e0,-1);
if(p+0xf7c) { fn_27_6A3D8(p+0x108c,-1); fn_27_CBB00(p+0xf7c,-1); }
if(p+0xf14) fn_27_565F0(p+0xf20,-1);
if(p+0xf08) fn_27_6880C(p+0xf0c,-1);
if(p+0xee0) __dt__16soStopModuleImplFv(p+0xee0,-1);
if(p+0xe70) fn_27_B5324(p+0xe90,-1);
if(p+0xe24) fn_27_252D0(p+0xe28,-1);
if(p+0xbdc) { fn_27_13C90(p+0xcb4,-1); fn_27_21038(p+0xca0,-1); if(p+0xc64) fn_27_C96C0(p+0xc64,-1); if(p+0xbdc) { if(p+0xbfc) if(p+0xbfc) if(p+0xbfc) fn_27_D2AA4(p+0xbfc,-1); fn_27_CD934(p+0xbdc,-1); } }
if(p+0x9fc) { __dt__17soModelModuleImplFv(p+0xb10,-1); fn_27_CBDE8(p+0x9fc,-1); }
if(p+0x9cc) __dt__20soResourceModuleImplFv(p+0x9e4,-1);
if(p+0x9a4) __dt__16soHeapModuleImplFv(p+0x9a4,-1);
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
fn_27_18D6CC(p+0x284,-1);
fn_27_18D788(p+0x198,-1);
__dt__23soEventManageModuleImplFv(p+0x184,-1);
reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p+0xcc)->~soInstanceManagerSimpleEntity();
}
}
}
fn_27_1D81C8(p,0);
}
if(flag>0) operator delete(p);
}
return p;
}