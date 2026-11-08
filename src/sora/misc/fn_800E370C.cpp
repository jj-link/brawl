#include <mu/mu_object.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(float);
};
struct State {
 char pad[0x18];
 unsigned int field18;
 unsigned int field1C;
 char pad2[8];
 MuObject* objects[6];
};
extern float lbl_805A23B0;
extern float lbl_805A23C0;
extern float lbl_805A23E4;
extern "C" void fn_800E1588(State*, unsigned int, int, int);
extern "C" void fn_800E370C(State* self) {
 MuObject** p;
 int i;
 i = 2;
 p = self->objects - 8;
 do {
  ((Object_vptr_0*)p[10]->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A23B0);
  i++; p++;
 } while (i < 6);
 i = 2;
 p = self->objects - 8;
 do {
  p[10]->setFrameNode(lbl_805A23B0);
  i++; p++;
 } while (i < 6);
 if (self->field1C != self->field18) {
  i = 2;
  p = self->objects - 8;
  do {
   p[10]->setFrameNode(lbl_805A23E4);
   i++; p++;
  } while (i < 6);
  i = 2;
  p = self->objects - 8;
  do {
   ((Object_vptr_0*)p[10]->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A23C0);
   i++; p++;
  } while (i < 6);
 } else {
  fn_800E1588(self, self->field18, 1, 0);
 }
}