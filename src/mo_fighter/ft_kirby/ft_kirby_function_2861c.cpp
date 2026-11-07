#include <so/so_module_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void fn_96_28D0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16();
};
struct Energy { char pad[5]; unsigned char enable:1; unsigned char rest:7; char pad2[2]; float speed; };
struct Params { char pad[0x2c]; float speed; char pad2[0x18]; int value; };
struct Holder { char pad[0x34]; Params* params; };
extern "C" {
extern const char lbl_96_data_D9A4[], lbl_96_data_5E00[], lbl_96_data_AAD8[], lbl_96_data_68D8[];
extern const float lbl_96_rodata_570;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Holder* fn_96_28234(void*);
}
extern "C" void fn_96_2861C(void*, soModuleAccesser* accesser) {
 Energy* energy = static_cast<Energy*>(__dynamic_cast(accesser->getKineticModule().getEnergy(2), 0, lbl_96_data_D9A4, lbl_96_data_5E00, 1));
 void* self = __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_96_data_AAD8, lbl_96_data_68D8, 1);
 switch (accesser->getStatusModule().getStatusKind()) {
 case 0:
  energy->speed = lbl_96_rodata_570;
  energy->enable = 0;
  break;
 case 1:
  accesser->getWorkManageModule().setInt(fn_96_28234(self)->params->value, 0x20000002);
  energy->speed = fn_96_28234(self)->params->speed;
  energy->enable = 1;
  break;
 }
}