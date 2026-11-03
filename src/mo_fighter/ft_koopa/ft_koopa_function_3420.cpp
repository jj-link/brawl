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
void* fn_102_3A4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_102_2208(void*, short);
void* fn_102_212C(void*, short);
void* fn_102_21C8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_102_3080(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_102_3A8C(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_102_3B28(void*, short);
void* fn_102_1EE8(void*, short);
void* fn_102_3B68(void*, short);
void* fn_102_3BC8(void*, short);
void* fn_102_3C4C(void*, short);
void* fn_27_1A2D10(void*, short);
void* fn_102_3CAC(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A262C(void*, short);
void* fn_102_3D4C(void*, short);
void* fn_102_3D8C(void*, short);
void* fn_102_3DF8(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void* fn_27_B5324(void*, short);
void* fn_102_3E54(void*, short);
void* fn_102_3E94(void*, short);
void* fn_102_3EF0(void*, short);
void* fn_102_3F5C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_D2AA4(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);
void* fn_102_3FD0(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}
extern "C" void* fn_102_3420(void* object, short deleting) {
 if (object) {
 unsigned char* p = static_cast<unsigned char*>(object);
 if (object) {
 if (p + 0x1f38) fn_102_3A4C(p + 0x1f38, 0);
 fn_27_1DBB60(p + 0x1f00, -1);
 if (p + 0xcc) {
 if (p + 0x1950) {
 if (p + 0x1e00) { fn_102_2208(p + 0x1e50, -1); fn_102_212C(p + 0x1e00, -1); }
 if (p + 0x1cd4) { fn_102_212C(p + 0x1db0, -1); fn_102_21C8(p + 0x1d94, -1); fn_102_2208(p + 0x1ce8, -1); if (p + 0x1cd4) fn_27_C7770(p + 0x1cd4, -1); }
 if (p + 0x1ba8) { fn_102_212C(p + 0x1c84, -1); fn_102_21C8(p + 0x1c68, -1); fn_102_2208(p + 0x1bbc, -1); if (p + 0x1ba8) fn_27_C7770(p + 0x1ba8, -1); }
 if (p + 0x1a7c) { fn_102_212C(p + 0x1b58, -1); fn_102_21C8(p + 0x1b3c, -1); fn_102_2208(p + 0x1a90, -1); if (p + 0x1a7c) fn_27_C7770(p + 0x1a7c, -1); }
 if (p + 0x1950) { fn_102_212C(p + 0x1a2c, -1); fn_102_21C8(p + 0x1a10, -1); fn_102_2208(p + 0x1964, -1); if (p + 0x1950) fn_27_C7770(p + 0x1950, -1); }
 }
 if (p + 0xcc) {
 if (p + 0x1934) fn_27_C31CC(p + 0x1934, -1);
 if (p + 0x18f4) fn_27_63EBC(p + 0x18f4, -1);
 if (p + 0x18dc) fn_27_5C674(p + 0x18dc, -1);
 if (p + 0x1740) {
 fn_27_97968(p + 0x1798, -1); fn_27_1CCCC(p + 0x1788, -1); fn_102_3080(p + 0x177c, -1);
 if (p + 0x1740) fn_27_CBF58(p + 0x1740, -1);
 }
 if (p + 0x16ec) fn_102_3A8C(p + 0x1718, -1);
 if (p + 0x1638) {
 if (p + 0x1668) { fn_27_1A241C(p + 0x1678, -1); fn_102_3B28(p + 0x1668, 0); }
 if (p + 0x1638) { fn_102_1EE8(p + 0x1658, 0); fn_102_3B68(p + 0x1638, 0); }
 }
 if (p + 0x1478) {
 fn_102_3BC8(p + 0x1588, -1); fn_102_3C4C(p + 0x1574, -1);
 if (p + 0x1564) fn_27_1A2D10(p + 0x1564, -1);
 if (p + 0x14c0) {
 fn_102_3CAC(p + 0x154c, -1);
 if (p + 0x14e0) if (p + 0x14e0) if (p + 0x14e0) fn_27_1A1E70(p + 0x14e0, -1);
 fn_27_CD934(p + 0x14c0, -1);
 }
 if (p + 0x1488) fn_102_3A8C(p + 0x149c, -1);
 fn_27_C74E8(p + 0x1478, -1);
 }
 if (p + 0x13d4) {
 if (p + 0x13f8) { fn_27_1A262C(p + 0x1408, -1); fn_102_3D4C(p + 0x13f8, 0); }
 fn_102_3D8C(p + 0x13d4, -1);
 }
 fn_102_3DF8(p + 0x13a0, -1);
 if (p + 0x1388) fn_27_5AE44(p + 0x1388, -1);
 if (p + 0x1224) { fn_27_6A3D8(p + 0x1334, -1); fn_27_CBB00(p + 0x1224, -1); }
 if (p + 0x11bc) fn_27_565F0(p + 0x11c8, -1);
 if (p + 0x11b0) fn_27_6880C(p + 0x11b4, -1);
 if (p + 0x1188) __dt__16soStopModuleImplFv(p + 0x1188, -1);
 if (p + 0xfb8) { __dt__27soCollisionAttackModuleImplFv(p + 0x10dc, -1); fn_27_82AD4(p + 0x10d8, -1); fn_27_4CAA0(p + 0x1054, -1); fn_27_19CA80(p + 0xfb8, -1); }
 if (p + 0xf54) {
 fn_27_B5324(p + 0xf74, -1);
 if (p + 0xf64) fn_102_3E54(p + 0xf64, 0);
 if (p + 0xf54) fn_102_3E54(p + 0xf54, 0);
 }
 fn_102_3E94(p + 0xf18, -1); fn_102_3EF0(p + 0xe70, -1); fn_102_3F5C(p + 0xdbc, -1);
 if (p + 0xbb0) {
 fn_27_13C90(p + 0xc4c, -1); fn_27_21038(p + 0xc38, -1);
 if (p + 0xbb0) {
 fn_102_3CAC(p + 0xc1c, -1);
 if (p + 0xbd0) if (p + 0xbd0) if (p + 0xbd0) fn_27_D2AA4(p + 0xbd0, -1);
 fn_27_CD934(p + 0xbb0, -1);
 }
 }
 if (p + 0x9d0) { __dt__17soModelModuleImplFv(p + 0xae4, -1); fn_27_CBDE8(p + 0x9d0, -1); }
 fn_102_3FD0(p + 0x9a4, -1); __dt__16soModuleAccesserFv(p + 0x8c4, -1);
 if (p + 0xcc) {
 reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x888)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x850)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x7f4)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x798)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x73c)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x6e0)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x684)->~soEventUnitWithWorkArea();
 fn_27_18D3DC(p + 0x640, -1);
 reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x5e4)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x588)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x52c)->~soEventUnitWithWorkArea();
 reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4d0)->~soEventUnitWithWorkArea();
 fn_27_D597C(p + 0x48c, -1);
 reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x430)->~soEventUnitWithWorkArea();
 fn_27_18D6CC(p + 0x284, -1); fn_27_18D788(p + 0x198, -1);
 __dt__23soEventManageModuleImplFv(p + 0x184, -1);
 reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xcc)->~soInstanceManagerSimpleEntity();
 }
 }
 }
 fn_27_1D81C8(object, 0);
 }
 if (deleting > 0) operator delete(object);
 }
 return object;
}
