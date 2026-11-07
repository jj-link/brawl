#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void* slot1(int);
 virtual void slot2();
 virtual int slot3();
};
class Self {
public:
 char pad[8];
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void s16(); virtual void s17(); virtual void s18();
 virtual void s19(int,int); virtual void s20(); virtual void s21(); virtual void s22();
 virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
 virtual void s27(); virtual void s28(); virtual void s29(int,int);
 virtual void s30(int,int); virtual void s31(); virtual void s32(int,int);
 char pad2[0x1c];
 Object_vptr_0* inner;
 char pad3[0x24];
 u8 flags;
};
struct Args { char pad[12]; u32 value; };
extern "C" void fn_27_2ED10(void*);
extern "C" void fn_27_30130(void*);
extern "C" void fn_27_2EFF0(void*);
extern "C" void fn_27_2ACF0(Self* self, int a, int b, Args* args) {
 for (int i = 0; i < self->inner->slot3(); i++) {
  fn_27_2ED10(self->inner->slot1(i));
  if ((self->flags >> 4) & 1) fn_27_30130(self->inner->slot1(i));
  if (i) fn_27_2EFF0(self->inner->slot1(i));
  else {
   self->s19((args->value >> 24) & 15, i);
   self->s30((args->value >> 21) & 7, i);
   self->s32(0, i);
   self->s29(0, i);
  }
 }
}