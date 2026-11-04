#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
extern char lbl_28_data_FC[];
extern char lbl_28_data_114[];
extern const float lbl_28_rodata_8C;
extern const float lbl_28_rodata_94;
int fn_800B61C0(MuObject*);
}
struct Slot { int state; char pad[0xb4]; };
struct Self {
 char pad0[0x40];
 int result[2];
 char pad48[4];
 int mode;
 int flags[2];
 char pad58[0xf8];
 MuObject* obj;
 char pad154[0x14];
 int result168;
 char pad16c[0xb8];
 Slot slots[2];
};
extern "C" int fn_28_1B80(Self* self) {
 MuObject* obj = self->obj;
 obj->changeClrAnimNIf(lbl_28_data_FC);
 switch (self->mode) {
 case 0: obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_28_rodata_8C); break;
 case 1: obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_28_rodata_94); break;
 }
 Self* p = self;
 Self* q = self;
 for (int i = 0; i < 2; i++) {
  if (p->slots[0].state == 1) {
   p->slots[0].state = 2;
   obj->changeNodeAnimNIf(lbl_28_data_114);
   obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_28_rodata_94);
   obj->setFrameNode(lbl_28_rodata_8C);
  }
  if (p->slots[0].state == 2) {
   if (fn_800B61C0(obj)) p->slots[0].state = 3;
  }
  if (p->slots[0].state == 3) {
   p->slots[0].state = 0;
   if (q->flags[0] == 0) {
    if (self->mode == 0) self->result168 = 2;
    else if (self->mode == 1) q->result[0] = 2;
   } else if (q->flags[0] == 2) q->result[0] = 3;
  }
  p = (Self*)((char*)p + 0xb8);
  q = (Self*)((char*)q + 4);
 }
 return self->result168;
}