#include <so/event/so_event_system.h>
#pragma force_active on
class soModelEventObserver;
class soCollisionAttackEventObserver;
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
void operator delete(void*);
extern "C" {
void* fn_94_14690(void*, short);
void* fn_94_15310(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_94_1536C(void*, short);
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_153D8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_94_146D0(void*, short);
void* fn_94_147B8(void*, short);
void* fn_94_14814(void*, short);
void* fn_94_14870(void*, short);
void* fn_94_15434(void*, short);
void* fn_94_15494(void*, short);
void* fn_27_1A220C(void*, short);
void* fn_94_4888(void*, short);
void* fn_94_154D4(void*, short);
void* fn_94_4928(void*, short);
void* fn_94_49AC(void*, short);
void* fn_94_148FC(void*, short);
void* fn_94_47EC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_94_149E4(void*, short);
void* fn_94_4B58(void*, short);
void* fn_94_15540(void*, short);
void* fn_94_14A6C(void*, short);
void* fn_94_14AD8(void*, short);
void* fn_94_14B38(void*, short);
void* fn_94_14BF4(void*, short);
void* fn_94_4BF4(void*, short);
void* fn_94_6560(void*, short);
void* fn_94_4C50(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_94_1559C(void*, short);
void* fn_94_14CEC(void*, short);
void* fn_94_14D64(void*, short);
void* fn_94_4D60(void*, short);
void* fn_27_1A8940(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_D6B9C(void*, short);
void* fn_27_D57AC(void*, short);
void* fn_27_1A9D88(void*, short);
void* fn_27_D645C(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}
extern "C" void* fn_94_15D94(void* object, short deleting) {
 if (object) {
  unsigned char* p = static_cast<unsigned char*>(object);
  if (p+0x15a8) if (p+0x15a8) fn_94_14690(p+0x15a8,0);
  if (object) {
   fn_94_15310(p+0x1560,-1);
   fn_27_1DBB60(p+0x1528,-1);
   if (p+0xcc) {
    if (p+0x120c) {
     fn_94_1536C(p+0x14a0,-1);
     if (p+0x1400) {
      fn_94_2158(p+0x1450,-1); fn_94_21F4(p+0x1434,-1); fn_94_153D8(p+0x1414,-1);
      if (p+0x1400) fn_27_C7770(p+0x1400,-1);
     }
     if (p+0x1360) {
      fn_94_2158(p+0x13b0,-1); fn_94_21F4(p+0x1394,-1); fn_94_153D8(p+0x1374,-1);
      if (p+0x1360) fn_27_C7770(p+0x1360,-1);
     }
     if (p+0x12c0) {
      fn_94_2158(p+0x1310,-1); fn_94_21F4(p+0x12f4,-1); fn_94_153D8(p+0x12d4,-1);
      if (p+0x12c0) fn_27_C7770(p+0x12c0,-1);
     }
     fn_94_146D0(p+0x120c,-1);
    }
    if (p+0xcc) {
     fn_94_147B8(p+0x11c8,-1); fn_94_14814(p+0x11b0,-1);
     fn_94_14870(p+0x1014,-1); fn_94_15434(p+0xfb4,-1);
     if (p+0xf48) {
      fn_94_15494(p+0xfb0,-1);
      if (p+0xf78) { fn_27_1A220C(p+0xf88,-1); fn_94_4888(p+0xf78,0); }
      fn_94_154D4(p+0xf48,-1);
     }
     if (p+0xdd0) {
      fn_94_4928(p+0xe98,-1); fn_94_49AC(p+0xe84,-1); fn_94_148FC(p+0xe1c,-1);
      if (p+0xde0) fn_94_47EC(p+0xdf8,-1);
      fn_27_C74E8(p+0xdd0,-1);
     }
     fn_94_149E4(p+0xd2c,-1); fn_94_4B58(p+0xcf8,-1); fn_94_15540(p+0xce0,-1);
     fn_94_14A6C(p+0xb7c,-1); fn_94_14AD8(p+0xb14,-1); fn_94_14B38(p+0xb08,-1);
     fn_94_14BF4(p+0xa98,-1); fn_94_4BF4(p+0xa5c,-1); fn_94_6560(p+0x9b4,-1); fn_94_4C50(p+0x900,-1);
     if (p+0x774) { fn_27_13C90(p+0x790,-1); fn_27_21038(p+0x77c,-1); }
     fn_94_1559C(p+0x664,-1); fn_94_14CEC(p+0x634,-1); fn_94_14D64(p+0x624,-1); fn_94_4D60(p+0x60c,-1);
     __dt__16soModuleAccesserFv(p+0x52c,-1);
     if (p+0xcc) {
      fn_27_1A8940(p+0x4cc,-1); fn_27_D7DBC(p+0x48c,-1); fn_27_D6B9C(p+0x450,-1);
      reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p+0x3f4)->~soEventUnitWithWorkArea();
      reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p+0x398)->~soEventUnitWithWorkArea();
      fn_27_D57AC(p+0x35c,-1); fn_27_1A9D88(p+0x254,-1); fn_27_D645C(p+0x198,-1);
      __dt__23soEventManageModuleImplFv(p+0x184,-1);
      reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p+0xcc)->~soInstanceManagerSimpleEntity();
     }
    }
   }
   fn_27_1D81C8(object,0);
  }
  if (deleting>0) operator delete(object);
 }
 return object;
}