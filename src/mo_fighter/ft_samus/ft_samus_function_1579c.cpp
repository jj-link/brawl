#include <so/event/so_event_system.h>
#pragma force_active on
class soModelEventObserver;
class soDamageEventObserver;
class soMotionEventObserver;
class soCaptureEventObserver;
class soSituationEventObserver;
class soItemManageEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soCollisionSearchEventObserver;
class soCollisionShieldEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
void operator delete(void*);
extern "C" {
void* fn_94_14690(void*, short);
void* fn_94_1536C(void*, short);
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_4790(void*, short);
void* fn_27_C7770(void*, short);
void* fn_94_1475C(void*, short);
void* fn_94_147B8(void*, short);
void* fn_94_14814(void*, short);
void* fn_27_10424(void*, short);
void* fn_94_14870(void*, short);
void* fn_94_47EC(void*, short);
void* fn_94_4928(void*, short);
void* fn_94_49AC(void*, short);
void* fn_27_1A4D90(void*, short);
void* fn_94_148FC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_94_149E4(void*, short);
void* fn_94_4B58(void*, short);
void* fn_94_15540(void*, short);
void* fn_94_14A6C(void*, short);
void* fn_94_14AD8(void*, short);
void* fn_94_14B38(void*, short);
void* fn_94_14B98(void*, short);
void __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CF10(void*, short);
void* fn_94_14BF4(void*, short);
void* fn_94_4BF4(void*, short);
void* fn_94_4C50(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_94_14C80(void*, short);
void* fn_94_14CEC(void*, short);
void* fn_94_14D64(void*, short);
void* fn_94_4D60(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}
extern "C" void* fn_94_1579C(void* object, short deleting) {
 if (object) {
  unsigned char* p = static_cast<unsigned char*>(object);
  if (p+0x1d1c) { if (p+0x1d1c) fn_94_14690(p+0x1d1c,0); }
  if (object) {
   if (p+0xCC) {
    if (p+0x19BC) {
     fn_94_1536C(p+0x1C8C,-1);
     if (p+0x1BD8) {
      fn_94_2158(p+0x1C3C,-1); fn_94_21F4(p+0x1C20,-1); fn_94_4790(p+0x1BEC,-1);
      if (p+0x1BD8) fn_27_C7770(p+0x1BD8,-1);
     }
     if (p+0x1B24) {
      fn_94_2158(p+0x1B88,-1); fn_94_21F4(p+0x1B6C,-1); fn_94_4790(p+0x1B38,-1);
      if (p+0x1B24) fn_27_C7770(p+0x1B24,-1);
     }
     if (p+0x1A70) {
      fn_94_2158(p+0x1AD4,-1); fn_94_21F4(p+0x1AB8,-1); fn_94_4790(p+0x1A84,-1);
      if (p+0x1A70) fn_27_C7770(p+0x1A70,-1);
     }
     if (p+0x19BC) {
      fn_94_2158(p+0x1A20,-1); fn_94_21F4(p+0x1A04,-1); fn_94_4790(p+0x19D0,-1);
      if (p+0x19BC) fn_27_C7770(p+0x19BC,-1);
     }
    }
    if (p+0xCC) {
     fn_94_1475C(p+0x19A0,-1); fn_94_147B8(p+0x1960,-1); fn_94_14814(p+0x1948,-1);
     if (p+0x18F4) fn_27_10424(p+0x18F8,-1);
     fn_94_14870(p+0x1760,-1);
     if (p+0x16D8) fn_94_47EC(p+0x1738,-1);
     if (p+0x1530) {
      fn_94_4928(p+0x1628,-1); fn_94_49AC(p+0x1614,-1);
      if (p+0x15E4) fn_27_1A4D90(p+0x15E4,-1);
      fn_94_148FC(p+0x1580,-1);
      if (p+0x1540) fn_94_47EC(p+0x155C,-1);
      fn_27_C74E8(p+0x1530,-1);
     }
     fn_94_149E4(p+0x148C,-1); fn_94_4B58(p+0x1458,-1); fn_94_15540(p+0x1440,-1);
     fn_94_14A6C(p+0x12DC,-1); fn_94_14AD8(p+0x1274,-1); fn_94_14B38(p+0x1268,-1); fn_94_14B98(p+0x1240,-1);
     if (p+0xEC0) {
      __dt__27soCollisionAttackModuleImplFv(p+0x1194,-1);
      fn_27_82AD4(p+0x1190,-1); fn_27_4CAA0(p+0x110C,-1); fn_27_19CF10(p+0xEC0,-1);
     }
     fn_94_14BF4(p+0xE5C,-1); fn_94_4BF4(p+0xE20,-1); fn_94_4C50(p+0xD68,-1);
     if (p+0xBDC) { fn_27_13C90(p+0xBF8,-1); fn_27_21038(p+0xBE4,-1); }
     fn_94_14C80(p+0x9FC,-1); fn_94_14CEC(p+0x9CC,-1); fn_94_14D64(p+0x9BC,-1); fn_94_4D60(p+0x9A4,-1);
     __dt__16soModuleAccesserFv(p+0x8C4,-1);
     if (p+0xCC) {
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
      fn_27_18D6CC(p+0x284,-1); fn_27_18D788(p+0x198,-1);
      __dt__23soEventManageModuleImplFv(p+0x184,-1);
      reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p+0xCC)->~soInstanceManagerSimpleEntity();
     }
    }
   }
   fn_27_1D81C8(object,0);
  }
  if (deleting>0) operator delete(object);
 }
 return object;
}
