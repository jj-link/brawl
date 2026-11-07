#include <gf/gf_model.h>
#pragma force_active on
extern "C" void fn_40_572C(void*);
extern "C" void* lbl_40_bss_15C;
extern "C" const float lbl_40_rodata_280;
struct Entry { unsigned char active; char pad[3]; int id; float value; };
struct Work { char pad0[0x44]; nw4r::g3d::ScnMdl** model; gfModelAnimation** anim; char pad4c[0x121]; unsigned char flag; char pad16e[6]; Entry entries[4]; unsigned char state; char pad1a5[3]; float value; };
extern "C" void fn_40_1B804(Work* self, int id) {
 for (int i = 0; i < 4; ++i) {
  if (id == self->entries[i].id) self->entries[i].active = 0;
 }
 if (self->flag) { fn_40_572C(lbl_40_bss_15C); self->flag = 0; }
 int active = 0;
 for (int i = 0; i < 4; ++i) {
  if (self->entries[i].active == 1) active = 1;
 }
 if (!active) {
  gfModelAnimation** anim = self->anim;
  if ((*anim)->m_anmObjChrRes) {
   self->state = 2;
   self->value = lbl_40_rodata_280;
   (*anim)->unbindNodeAnim(*self->model);
  }
 }
}