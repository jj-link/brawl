#include <mu/mu_object.h>
#include <gf/gf_task.h>
#include <snd/snd_system.h>
#include <string.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on
extern "C" {
extern int lbl_33_data_C0[3];
extern char lbl_33_data_3E0[];
extern char lbl_33_data_3E4[];
extern int lbl_33_data_A0[8];
void fn_800B9F90(void*, void*, int);
gfTask* fn_33_2AE0(void*);
}
struct Name { char s[65]; };
struct Values { int v[3]; };
struct Params { int v[8]; };
struct Status { char pad[12]; int buttons; char rest[0x30]; };
struct Node { char pad[0x10]; int value; };
struct Controller {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(int); virtual void f14(); virtual void f15(int);
};
struct Self {
 char pad0[0x48]; int field48;
 char pad4c[0x110-0x4c]; int input;
 char pad114[0x1b0-0x114]; u8 flag; char pad1b1[3]; int field1b4;
 char pad1b8[0x21c-0x1b8]; int count;
 char pad220[0xc]; int selection; int pad230; int options[3]; int numOptions;
 char pad244[8]; int field24c; int field250; char pad254[8]; MuObject* obj;
 char pad260[0x24]; Controller* controller; char pad288[0x34]; gfTask* task;
 char pad2c0[0x9c]; Node* nodes[1];
};
inline int getValue(Self* self) {
 int value = self->options[self->selection];
  if (value == 1) {
   if (!self->flag) value = 5;
   else if (self->task && *(int*)((char*)self->task + 0x1ac) == 1) {
    value = 5;
    if (*(int*)((char*)self->task + 0x1b4) == 0) value = 4;
   }
  }
 return value;
}
extern "C" int fn_33_2100(Self* self) {
 int value;
 MuObject* obj;
 int input = self->input;
 int old = self->selection;
 int selection = old;
 if ((input & 8) && old > 0) selection = old - 1;
 if ((input & 4) && selection < self->numOptions - 1) selection++;
 if (selection != old) {
  g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
  obj = self->obj;
  Values values = *(Values*)lbl_33_data_C0;
  value = values.v[self->options[selection]];
  char* mdl = *(char**)((char*)obj + 8);
  int off = *(int*)(mdl + 0x3c);
  const char* src = off ? mdl + off : 0;
  Name n4; Name n3; Name n2; Name n1;
  n1.s[0] = 0;
  strcat(n1.s, src);
  n2 = n1;
  strcat(n2.s, lbl_33_data_3E4);
  n3 = n2;
  sprintf(n3.s + strlen(n3.s), lbl_33_data_3E0, value);
  n4 = n3;
  obj->changeClrAnimNIf(n4.s);
  self->selection = selection;
 }
 Status status;
 fn_800B9F90(&status, (char*)self + 0x100, 0);
 if (status.buttons & 0x100) {
  int value = getValue(self);
  if (value == 0) g_sndSystem->playSE((SndID)0x13, -1, 0, 0, -1);
  else g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
  if (self->options[self->selection] == 1) {
   Params p = *(Params*)lbl_33_data_A0;
   p.v[0] = self->field1b4;
   p.v[1] = self->field48;
   p.v[2] = self->field24c;
   p.v[3] = self->field250;
   p.v[4] = 4;
   gfTask* task = fn_33_2AE0(&p);
   if (self->task) self->task->exit();
   self->task = task;
  }
  for (selection = 0; selection < self->count; selection++) self->controller->f13((*(Node**)((char*)self + (selection + 1) * 4 + 0x35c))->value);
  return 1;
 }
 return 0;
}