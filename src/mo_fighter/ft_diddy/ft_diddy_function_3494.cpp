#include <so/event/so_event_system.h>
#pragma force_active on
void operator delete(void*);
class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
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
template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
extern "C" {
void* fn_115_226C(void*, short);
void* fn_115_2190(void*, short);
void* fn_115_222C(void*, short);
void* fn_115_30E4(void*, short);
void* fn_115_3A2C(void*, short);
void* fn_115_3AC8(void*, short);
void* fn_115_3B4C(void*, short);
void* fn_115_3BAC(void*, short);
void* fn_115_3C4C(void*, short);
void* fn_115_3C8C(void*, short);
void* fn_115_3CF8(void*, short);
void* fn_115_3D54(void*, short);
void* fn_115_3D94(void*, short);
void* fn_115_3DD4(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A262C(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_D2AA4(void*, short);
void* fn_27_CBDE8(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}
extern "C" void* fn_115_3494(void* object, short deleting) {
 if (object) {
  unsigned char* p = static_cast<unsigned char*>(object);
  if (object) {
   if (p + 0xcc) {
    if (p + 0x1700) {
     if (p + 0x1bb0) { fn_115_226C(p + 0x1c00, -1); fn_115_2190(p + 0x1bb0, -1); }
if(p+0x1a84) { fn_115_2190(p+0x1b60,-1); fn_115_222C(p+0x1b44,-1); fn_115_226C(p+0x1a98,-1); if(p+0x1a84) fn_27_C7770(p+0x1a84,-1); }
if(p+0x1958) { fn_115_2190(p+0x1a34,-1); fn_115_222C(p+0x1a18,-1); fn_115_226C(p+0x196c,-1); if(p+0x1958) fn_27_C7770(p+0x1958,-1); }
if(p+0x182c) { fn_115_2190(p+0x1908,-1); fn_115_222C(p+0x18ec,-1); fn_115_226C(p+0x1840,-1); if(p+0x182c) fn_27_C7770(p+0x182c,-1); }
if(p+0x1700) { fn_115_2190(p+0x17dc,-1); fn_115_222C(p+0x17c0,-1); fn_115_226C(p+0x1714,-1); if(p+0x1700) fn_27_C7770(p+0x1700,-1); }
}
if (p+0xcc) {
if(p+0x16e4) fn_27_C31CC(p+0x16e4,-1);
if(p+0x16a4) fn_27_63EBC(p+0x16a4,-1);
if(p+0x168c) fn_27_5C674(p+0x168c,-1);
if(p+0x1534) fn_27_BED74(p+0x1534,-1);
if(p+0x139c) { fn_27_97968(p+0x13f4,-1); fn_27_1CCCC(p+0x13e4,-1); fn_115_30E4(p+0x13d8,-1); if(p+0x139c) fn_27_CBF58(p+0x139c,-1); }
if(p+0x133c) fn_115_3A2C(p+0x1374,-1);
if(p+0x1174) {
 fn_115_3AC8(p+0x128c,-1); fn_115_3B4C(p+0x1278,-1);
 if(p+0x1260) fn_27_1A405C(p+0x1260,-1);
 if(p+0x11bc) { fn_115_3BAC(p+0x1248,-1); if(p+0x11dc) if(p+0x11dc) if(p+0x11dc) fn_27_1A1E70(p+0x11dc,-1); fn_27_CD934(p+0x11bc,-1); }
 if(p+0x1184) fn_115_3A2C(p+0x1198,-1);
 fn_27_C74E8(p+0x1174,-1);
}
if(p+0x10d0) { if(p+0x10f4) { fn_27_1A262C(p+0x1104,-1); fn_115_3C4C(p+0x10f4,0); } fn_115_3C8C(p+0x10d0,-1); }
fn_115_3CF8(p+0x109c,-1);
if(p+0x1068) fn_27_5B39C(p+0x1068,-1);
if(p+0xf04) { fn_27_6A3D8(p+0x1014,-1); fn_27_CBB00(p+0xf04,-1); }
if(p+0xe9c) fn_27_565F0(p+0xea8,-1);
if(p+0xe90) fn_27_6880C(p+0xe94,-1);
if(p+0xe68) __dt__16soStopModuleImplFv(p+0xe68,-1);
if(p+0xdf8) { fn_27_B5324(p+0xe18,-1); if(p+0xe08) fn_115_3D54(p+0xe08,0); if(p+0xdf8) fn_115_3D54(p+0xdf8,0); }
if(p+0xbe8) { fn_27_13C90(p+0xc84,-1); fn_27_21038(p+0xc70,-1); if(p+0xbe8) { fn_115_3BAC(p+0xc54,-1); if(p+0xc08) if(p+0xc08) if(p+0xc08) fn_27_D2AA4(p+0xc08,-1); fn_27_CD934(p+0xbe8,-1); } }
if(p+0xa08) { __dt__17soModelModuleImplFv(p+0xb1c,-1); fn_27_CBDE8(p+0xa08,-1); }
if(p+0x9d8) { __dt__20soResourceModuleImplFv(p+0x9f0,-1); if(p+0x9d8) fn_115_3D94(p+0x9d8,0); }
fn_115_3DD4(p+0x9b0,-1);
__dt__16soModuleAccesserFv(p+0x8d0,-1);
if(p+0xcc) {
reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p+0x894)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p+0x85c)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p+0x800)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p+0x7a4)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p+0x748)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p+0x6ec)->~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p+0x690)->~soEventUnitWithWorkArea();
fn_27_18D3DC(p+0x64c,-1);
fn_27_18D498(p+0x5e4,-1);
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
fn_27_1D81C8(object,0);
}
if(deleting>0) operator delete(object);
}
return object;
}