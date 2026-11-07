#pragma force_active on
class Class_891F8 {
public:
 virtual void fn_27_3312C0(); virtual void fn_27_2D9350(); virtual void fn_27_2D934C(); virtual void fn_27_33132C(); virtual void fn_27_2D9344(); virtual void fn_27_2D9340(); virtual void fn_27_331300(); virtual void fn_27_2D9338(); virtual void fn_27_3313D8(); virtual void fn_27_331484(); virtual void fn_27_2D9328(); virtual void fn_27_2D9320(); virtual void fn_27_3315D0(); virtual void fn_27_2D9318(); virtual void fn_27_2D9314(); virtual void fn_27_2D9310(); virtual void fn_27_2D9308();
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void slot3(unsigned int, void*);
 virtual unsigned int slot4(unsigned int);
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual int slot16();
};
class FloatModule {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(float, int);
};
struct Modules { char pad[0x44]; FloatModule* floatModule; char pad2[0x1c]; Object_vptr_0* work; char pad3[8]; Object_vptr_0* status; };
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" {
extern unsigned char lbl_27_bss_7B0C[];
int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
unsigned int fn_27_30FA2C(void*, unsigned int, int, void*, unsigned int);
int fn_27_1922CC(Accesser*, unsigned long);
int fn_27_331484(void*, Accesser* a) {
 int status = fn_27_30FACC(lbl_27_bss_7B0C, 0, a->modules->status->slot16(), a, 1);
 unsigned int value = fn_27_30FA2C(lbl_27_bss_7B0C, 2, 1, a, 1);
 if (status == 0x112 && value == a->modules->work->slot4(0x20000002)) {
  a->modules->status->slot3(fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x11d, a, 0), a);
  FloatModule* module = a->modules->floatModule;
  module->slot4((float)fn_27_1922CC(a, 0x5dc0), 0);
  return 1;
 }
 return 0;
}
}