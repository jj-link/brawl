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
void* fn_94_14690(void*, short);
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_4790(void*, short);
void* fn_27_C7770(void*, short);
void* fn_94_146D0(void*, short);
void* fn_94_1475C(void*, short);
void* fn_94_147B8(void*, short);
void* fn_94_14814(void*, short);
void* fn_27_BED74(void*, short);
void* fn_94_2DF4(void*, short);
void* fn_94_14870(void*, short);
void* fn_94_47EC(void*, short);
void* fn_94_4928(void*, short);
void* fn_94_49AC(void*, short);
void* fn_94_148FC(void*, short);
void* fn_94_14984(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_94_149E4(void*, short);
void* fn_94_4B58(void*, short);
void* fn_94_5DCC(void*, short);
void* fn_94_14A6C(void*, short);
void* fn_94_14AD8(void*, short);
void* fn_94_14B38(void*, short);
void* fn_94_14B98(void*, short);
void* fn_94_14BF4(void*, short);
void* fn_94_4BF4(void*, short);
void* fn_94_4C50(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_94_4CC4(void*, short);
void* fn_94_4A0C(void*, short);
void* fn_27_D2AA4(void*, short);
void* fn_27_CD934(void*, short);
void* fn_94_14C80(void*, short);
void* fn_94_14CEC(void*, short);
void* fn_94_14D64(void*, short);
void* fn_94_4D60(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}
extern "C" void* fn_94_14260(void* object, short deleting) {
 if (object) {
  unsigned char* p = static_cast<unsigned char*>(object);
  if (p+0x1b5c) if (p+0x1b5c) fn_94_14690(p+0x1b5c,0);
  if (object) {
   if (p+0xcc) {
    if (p+0x182c) {
     if(p+0x1afc) fn_94_2158(p+0x1afc,-1);
     if(p+0x1a48) { fn_94_2158(p+0x1aac,-1); fn_94_21F4(p+0x1a90,-1); fn_94_4790(p+0x1a5c,-1); if(p+0x1a48) fn_27_C7770(p+0x1a48,-1); }
     if(p+0x1994) { fn_94_2158(p+0x19f8,-1); fn_94_21F4(p+0x19dc,-1); fn_94_4790(p+0x19a8,-1); if(p+0x1994) fn_27_C7770(p+0x1994,-1); }
     if(p+0x18e0) { fn_94_2158(p+0x1944,-1); fn_94_21F4(p+0x1928,-1); fn_94_4790(p+0x18f4,-1); if(p+0x18e0) fn_27_C7770(p+0x18e0,-1); }
     fn_94_146D0(p+0x182c,-1);
    }
    if(p+0xcc) {
     fn_94_1475C(p+0x1810,-1); fn_94_147B8(p+0x17d0,-1); fn_94_14814(p+0x17b8,-1);
     if(p+0x1660) fn_27_BED74(p+0x1660,-1);
     fn_94_2DF4(p+0x1614,-1); fn_94_14870(p+0x147c,-1);
     if(p+0x1414) fn_94_47EC(p+0x1454,-1);
     if(p+0x12a0) { fn_94_4928(p+0x1364,-1); fn_94_49AC(p+0x1350,-1); fn_94_148FC(p+0x12e8,-1); fn_94_14984(p+0x12b0,-1); fn_27_C74E8(p+0x12a0,-1); }
     fn_94_149E4(p+0x11fc,-1); fn_94_4B58(p+0x11c8,-1); fn_94_5DCC(p+0x1194,-1);
     fn_94_14A6C(p+0x1030,-1); fn_94_14AD8(p+0xfc8,-1); fn_94_14B38(p+0xfbc,-1);
     fn_94_14B98(p+0xf94,-1); fn_94_14BF4(p+0xf24,-1); fn_94_4BF4(p+0xee8,-1); fn_94_4C50(p+0xe30,-1);
     if(p+0xbe8) { fn_27_13C90(p+0xcc0,-1); fn_27_21038(p+0xcac,-1); fn_94_4CC4(p+0xc70,-1);
      if(p+0xbe8) { fn_94_4A0C(p+0xc54,-1); if(p+0xc08) if(p+0xc08) if(p+0xc08) fn_27_D2AA4(p+0xc08,-1); fn_27_CD934(p+0xbe8,-1); }
     }
     fn_94_14C80(p+0xa08,-1); fn_94_14CEC(p+0x9d8,-1); fn_94_14D64(p+0x9c8,-1); fn_94_4D60(p+0x9b0,-1);
     __dt__16soModuleAccesserFv(p+0x8d0,-1);
     if(p+0xcc) {
      reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p+0x894)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p+0x85c)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p+0x800)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p+0x7a4)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p+0x748)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p+0x6ec)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p+0x690)->~soEventUnitWithWorkArea();
      fn_27_18D3DC(p+0x64c,-1); fn_27_18D498(p+0x5e4,-1);
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