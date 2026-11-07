#include <it/item.h>
#include <so/event/so_event_system.h>
#include <mt/mt_vector.h>
#pragma force_active on

namespace matching {
class soNullable {
public:
 virtual void isNull();
 virtual void fn_27_B81C4();
 virtual void fn_27_B8360();
 virtual void fn_27_B83E4();
 virtual void fn_27_B8674();
 virtual void fn_27_B86B0();
 virtual void fn_27_B87B8();
 virtual void fn_27_B88AC();
 virtual void fn_27_B8A98();
 virtual void fn_27_B8B44();
 virtual int fn_27_BC19C(BaseItem*);
 virtual void fn_27_B91FC();
 virtual void fn_27_B86D4();
 virtual void fn_27_BE4F0();
 virtual int fn_27_B83F4(int);
 virtual void fn_27_B8434();
 virtual void fn_27_B8468();
 virtual void fn_27_B849C();
 virtual void fn_27_B84D0();
 virtual void fn_27_B8548();
 virtual void fn_27_B8594();
 virtual void fn_27_B85E0();
 virtual void fn_27_BE4E8();
 virtual void fn_27_BE4E0();
 virtual void fn_27_BE4D8();
 virtual void fn_27_B8648();
 virtual void fn_27_B8780();
 virtual void fn_27_BC0A4();
 virtual void fn_27_BC0BC();
 virtual void fn_27_B9918();
 virtual void fn_27_B9D20();
 virtual void fn_27_BA1C8();
 virtual void fn_27_BA600();
 virtual void fn_27_BA514();
 virtual void fn_27_BA594();
 virtual void fn_27_BA714();
 virtual void fn_27_BA9B8();
 virtual void fn_27_BAA38();
 virtual void fn_27_BAAAC();
 virtual void fn_27_BAB24();
 virtual void fn_27_BAC38();
 virtual void fn_27_BACD4();
 virtual void fn_27_BB040();
 virtual void fn_27_BB0C0();
 virtual void fn_27_BB14C();
 virtual void fn_27_B9108();
 virtual void fn_27_B9878();
 virtual void fn_27_B97FC();
 virtual void fn_27_B9810();
 virtual void fn_27_BB658();
 virtual void fn_27_BE4D0();
 virtual void fn_27_BB398(int, int, int);
 char pad[0x34];
 soArray<soItemInfo>* items;
 char pad3c[0x2c];
 soModuleAccesser* access;
};
}
extern "C" {
extern const float lbl_27_rodata_E60;
void fn_27_28E48C(BaseItem*, Vec3f*, float);
}
extern "C" void fn_27_BA600(matching::soNullable* self, int index) {
 if (self->fn_27_B83F4(index)) {
  BaseItem* item = self->items->at(index).m_item;
  self->fn_27_BB398(index, 0, 0);
  if (!self->fn_27_BC19C(item) && item->isHaved() == true) {
   item->setVisibilityWhole(1);
   Vec3f velocity;
   velocity.m_x = lbl_27_rodata_E60;
   velocity.m_y = lbl_27_rodata_E60;
   velocity.m_z = lbl_27_rodata_E60;
   fn_27_28E48C(item, &velocity, self->access->m_enumerationStart->m_postureModule->getLr());
  }
 }
}