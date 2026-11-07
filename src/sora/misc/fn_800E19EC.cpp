#include <mu/mu_object.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8(float);
};
struct State {
 unsigned char flags;
 char pad[11];
 int mode;
 char pad2[0x78];
 MuObject* object;
};
extern float lbl_805A23B0;
extern float lbl_805A23C0;
extern float lbl_805A23F0;
extern "C" void fn_800E22A0(State*, int);
extern "C" void fn_800E1AFC(State*, int, int);
extern "C" void fn_800E19EC(State* self, int value) {
 switch (self->mode) {
 case 2: {
  fn_800E22A0(self, value);
  MuObject* obj = self->object;
  ((Object_vptr_0*)obj->m_modelAnim->m_anmObjVisRes)->slot8(lbl_805A23B0);
  obj->setFrameVisible(lbl_805A23B0);
  break;
 }
 case 1:
  fn_800E1AFC(self, value, 1);
  break;
 case 0:
  if ((self->flags >> 6) & 1) {
   int negative;
   if (value < 0) {
    value = -value;
    negative = 1;
   } else {
    negative = 0;
   }
   fn_800E22A0(self, value);
   float frame;
   if (negative) frame = lbl_805A23F0;
   else frame = lbl_805A23C0;
   MuObject* obj = self->object;
   ((Object_vptr_0*)obj->m_modelAnim->m_anmObjVisRes)->slot8(lbl_805A23B0);
   obj->setFrameVisible(frame);
  }
  break;
 }
}