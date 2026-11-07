#include <mu/mu_msg.h>
#pragma force_active on
extern float lbl_6_rodata_6E8;
extern float lbl_6_rodata_758;
extern char lbl_6_data_8DC[];
extern "C" void fn_16_44C(void*, int, int, MuObject*, void*, MuObject*, int, int, MuMsg*, int, int);
struct Viewer {
 char pad[0x4c];
 MuObject* obj1;
 char field50[0x14];
 MuObject* obj2;
 int field68;
 char pad6c[4];
 int field70;
 int field74;
 MuMsg* msg;
 char pad7c[0x128];
};
extern "C" void fn_6_AECC(Viewer* self, int flag) {
 float frame;
 int a, b;
 MuMsg* c;
 int d;
 if (flag) {
  frame = lbl_6_rodata_6E8;
  a = 0;
  b = 1;
  c = 0;
  d = 1;
  self->msg->printf(4, lbl_6_data_8DC);
 } else {
  a = self->field68;
  c = self->msg;
  b = 4;
  frame = lbl_6_rodata_758;
  d = 0;
 }
 self->obj1->setFrameVisible(frame);
 self->obj2->setFrameVisible(frame);
 fn_16_44C((char*)self + 0x1a4, self->field74, self->field70, self->obj1, self->field50, self->obj2, a, b, c, 0, d);
}