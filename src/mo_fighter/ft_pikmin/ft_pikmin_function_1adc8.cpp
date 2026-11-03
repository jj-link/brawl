#pragma force_active on
struct Obj { char pad[0x28]; void* value; };
class Class_7FE8 {
public:
 virtual void fn_113_80F4();
 virtual void fn_113_1552C();
 virtual void fn_113_1C084();
 virtual void fn_113_1C07C();
 virtual void fn_113_1C074();
 virtual void fn_113_1C06C();
 virtual void fn_113_1C064();
 virtual void fn_113_1C05C();
 virtual void fn_113_1C054();
 virtual void fn_113_1C04C();
 virtual void fn_113_1C044();
 virtual void fn_113_1C03C();
 virtual void fn_113_1C034();
 virtual void fn_113_1C02C();
 virtual void fn_113_1BFDC();
 virtual void fn_113_1C024();
 virtual void fn_113_1C014();
 virtual void fn_113_1C004();
 virtual void fn_113_1BFF4();
 virtual void fn_113_1BFE4();
};
class CompB {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual unsigned int f4(int, void*);
 virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(int);
 virtual unsigned int f9(int);
 virtual void f10();
 virtual Obj* f11(int);
};
class CompC {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void* f4(int);
 virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8();
 virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12();
 virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16();
 virtual int f17(int);
 virtual void f18();
 virtual void f19(int);
};
struct Mid;
class CompD {
public:
 virtual void f0(); virtual void f1(); virtual void f2();
 virtual void f3(int, Mid*);
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual int f16();
};
struct Inner {
 char pad0[0x54]; CompB* c54;
 char pad1[0x64-0x58]; CompC* c64;
 char pad2[0x70-0x68]; CompD* c70;
};
struct Mid { char pad[0xd8]; Inner* inner; };
struct Outer { char pad[0x60]; Mid* mid; };
extern "C" void fn_113_19BA8(Outer*, int);
extern "C" void fn_27_1DB7B0(Outer*);
extern "C" void fn_113_1B02C(Outer*);
extern "C" void fn_113_1ADC8(Outer* a, int arg) {
 if (a->mid->inner->c64->f17(0x12000005) &&
     (a->mid->inner->c70->f16() == 0x2e ||
      a->mid->inner->c70->f16() == 0x2f ||
      a->mid->inner->c70->f16() == 0x30)) {
  a->mid->inner->c64->f19(0x12000005);
  fn_113_19BA8(a, 1);
  Mid* mid = a->mid;
  mid->inner->c70->f3(arg, mid);
  if (a->mid->inner->c54->f9(3) == 1U)
   a->mid->inner->c54->f8(3);
  Obj* obj = a->mid->inner->c54->f11(3);
  void* val = a->mid->inner->c64->f4(0x10000000);
  if (obj == 0) {
   a->mid->inner->c54->f4(3, val);
  } else if (val != obj->value) {
   a->mid->inner->c54->f8(3);
   if (a->mid->inner->c54->f9(3) == 0)
    a->mid->inner->c54->f4(3, val);
  }
  fn_27_1DB7B0(a);
  fn_113_1B02C(a);
 }
}
