#include <so/so_value_accesser.h>
#pragma force_active on
struct Self {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
 virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
 virtual void d12(); virtual void d13(); virtual void f16(void*);
};
struct ObjD {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
 virtual void d8(); virtual float f11();
};
struct ObjE {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual int f5();
};
struct ObjB {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual void d4(); virtual int f7();
};
struct ObjC {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
 virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
 virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
 virtual float f18();
};
struct ObjF {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual int f6(unsigned int); virtual void f7(int, unsigned int);
};
struct ObjT {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
 virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
 virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
 virtual int f18(void*);
};
struct ObjG {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual void d4(); virtual void d5(); virtual void* f8(int);
};
struct Modules {
 char p0[0x0c]; ObjD* pc; char p10[0x04]; ObjE* p14; char p18[0x30];
 ObjB* p48; char p4c[0x10]; ObjC* p5c; char p60[0x04]; ObjF* p64;
 char p68[0x08]; ObjT* p70; char p74[0x08]; ObjG* p7c;
};
struct Owner { char pad[0xd8]; Modules* mod; };
struct Eff { char p0[5]; unsigned char flag : 1; unsigned char rest : 7; char p6[6]; float f0c; float f10; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern float lbl_27_rodata_7488;
void fn_27_3114F4(Self* self, Owner* a) {
 float f30; float f31; int r30;
 switch (a->mod->p70->f18(a)) {
 case 0x11a:
  if (a->mod->p48->f7() == 0) {
   f30 = soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xc31, 0);
   f31 = a->mod->p5c->f18();
   if (f31 * a->mod->pc->f11() <= f30) self->f16(a);
  }
  break;
 }
 if (a->mod->p14->f5() == 2) {
  float c; unsigned char fl;
  r30 = a->mod->p64->f6(0x20000002);
  Eff* e = (Eff*)__dynamic_cast(a->mod->p7c->f8(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
  e->flag = 1;
  if (r30 - 1 > 0) {
   c = lbl_27_rodata_7488; e->f0c = c; e->f10 = c;
  } else {
   e->f10 = -soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xfbb, 0);
  }
  a->mod->p64->f7(r30 - 1, 0x20000002);
 }
}
}