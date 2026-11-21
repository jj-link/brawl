#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(void*);
};
struct String { char data[33]; };
struct Self { unsigned char reverse; char pad[3]; int value; int count; MuObject* objects[6]; Object_vptr_0* parent; };
extern "C" {
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_8059E564[5];
extern char lbl_8059E5B0[3];
}
extern "C" void fn_80101948(Self* self, int value) {
 String name;
 name.data[0] = 0;
 strcat(name.data, lbl_8059E564);
 self->value = value;
 int power;
 unsigned int exp;
 int base = 10;
 exp = self->count;
 power = 1;
 while (exp) {
  if (exp & 1) power *= base;
  base *= base;
  exp >>= 1;
 }
 int max = power - 1;
 int v = value > 0 ? value : 0;
 if (v < max) max = v;
 value = max;
 String copy;
 String tmp;
 unsigned int index;
 char* p;
 MuObject** ptr = self->objects;
 p = tmp.data;
 int i = 0;
 for (; i < self->count; i++) {
  if (*(int*)((char*)(*ptr)->m_sceneModel + 4) == 0) {
   index = self->reverse;
   index = index ? i : self->count - 1 - i;
   tmp = name;
   sprintf(p + strlen(tmp.data), lbl_8059E5B0, index);
   copy = tmp;
   Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->parent, (*ptr)->m_sceneModel, copy.data);
  }
  (*ptr)->setFrameTex((float)(value % 10));
  value /= 10;
  if (value <= 0) { i++; break; }
  ptr++;
 }
 for (; i < self->count; i++) {
  self->parent->slot13(self->objects[i]->m_sceneModel);
 }
}
