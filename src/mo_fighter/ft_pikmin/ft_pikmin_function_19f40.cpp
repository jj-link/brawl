#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" {
int fn_113_19E30(void*);
int fn_113_18FB4(void*);
int fn_113_1AA38(void*, float*, float*);
void fn_27_1DB174(void*, int, float, float);
extern const float lbl_113_rodata_5C;
extern const float lbl_113_rodata_64;
}
class Object_vptr_0 {
public:
 virtual void fn_113_80F4(); virtual void slot1(); virtual int slot2();
 virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 virtual void slot7(); virtual void slot8(); virtual int slot9(); virtual void slot10();
 virtual void slot11(); virtual float slot12(int); virtual int slot13(); virtual float slot14();
 virtual void slot15(); virtual int slot16();
};
struct BC {
 char pad[8];
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual int getValue(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual int getState(); virtual float getFacing();
};
struct Inner {
 char pad0[0x18]; Object_vptr_0* u18;
 char pad1[0x64-0x1c]; Object_vptr_0* u64;
 char pad2[0x70-0x68]; Object_vptr_0* u70;
 char pad3[0xbc-0x74]; BC* uBc;
};
struct Mid { char pad[0xd8]; Inner* inner; };
struct Fighter { char pad[0x60]; Mid* acc; };
struct Flags { unsigned int a:28; unsigned int bit:1; unsigned int b:3; };
extern "C" int fn_113_19F40(Fighter* self, unsigned int flags) {
 float b[2]; float a[2]; int ok;
 if (fn_113_19E30(self)) {
  if (self->acc->inner->u64->slot12(0x11000001) > lbl_113_rodata_64) {
   float r = self->acc->inner->u64->slot12(0x11000001);
   fn_27_1DB174(self, 0, r, lbl_113_rodata_5C);
  }
 }
 Flags f; *(unsigned int*)&f = flags;
 ok = f.bit;
 if (ok) { BC* p = self->acc->inner->uBc; ok = p->getState() == 1; }
 if (ok) {
  Inner* in = self->acc->inner;
  BC* p = in->uBc;
  int v = ((Object_vptr_0*)in->u18->slot2())->slot2();
  ok = (v - p->getValue()) != 0;
 }
 if (ok) ok = fn_113_18FB4(self) == 1;
 if (ok) {
  BC* p = self->acc->inner->uBc;
  b[0] = -p->getFacing();
  b[1] = lbl_113_rodata_5C;
  p = self->acc->inner->uBc;
  a[0] = -p->getFacing();
  a[1] = lbl_113_rodata_5C;
  if (self->acc->inner->u70->slot16() == 0x15) {
   b[0] = lbl_113_rodata_5C;
   a[1] = soValueAccesser::getConstantFloat((soModuleAccesser*)self->acc, 0xfbb, 0);
  }
  return fn_113_1AA38(self, a, b);
 }
 return 0;
}