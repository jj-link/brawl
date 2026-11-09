#include <types.h>
#include <gf/gf_task.h>
#pragma force_active on
extern "C" {
extern void* lbl_27_bss_F0;
extern const char lbl_27_data_69C0[];
extern const char __RTTI__6gfTask[];
extern float lbl_27_rodata_46C8;
extern float lbl_27_rodata_46DC;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getTask__6gfTaskFi(int);
int getStatusKind__23soExternalValueAccesserFP11StageObject(void*);
void fn_27_28E48C(void*, void*, float);
}
class Class_A { public:
virtual void m0();
virtual void m1();
virtual void m2();
virtual void m3();
virtual void m4();
virtual void m5();
virtual void m6();
virtual void m7();
virtual void m8();
virtual void m9();
virtual void m10();
virtual void m11();
virtual void m12();
virtual void m13();
virtual void m14();
virtual void m15();
virtual int m16(); };
class Class_B { public:
virtual void m0();
virtual void m1();
virtual void m2();
virtual void m3();
virtual void m4();
virtual void m5();
virtual void m6();
virtual void m7();
virtual void m8();
virtual int m9(int);
virtual void m10();
virtual void m11();
virtual void m12();
virtual void m13();
virtual void m14();
virtual void m15();
virtual void m16();
virtual void m17();
virtual void m18();
virtual void m19();
virtual void m20();
virtual void m21();
virtual void m22();
virtual void m23();
virtual void m24();
virtual void m25();
virtual void m26();
virtual void m27();
virtual void m28();
virtual void m29();
virtual void m30();
virtual void m31();
virtual void m32();
virtual void m33();
virtual void m34();
virtual void m35();
virtual void m36();
virtual void m37();
virtual void m38();
virtual void m39();
virtual void m40();
virtual void m41();
virtual int m42(int);
};
extern "C" int fn_27_29BCFC(void* unused, void* self) {
 if (lbl_27_bss_F0 == 0) {
  void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
  if (singleton != 0) singleton = fn_27_5BCD0(singleton);
  lbl_27_bss_F0 = singleton;
 }
 if (fn_27_5BEA8(lbl_27_bss_F0) == 0) return 1;
 void* b = *(void**)((char*)*(void**)((char*)self + 0x1A4) + 0x70);
 if (((Class_A*)b)->m16() != 2) return 1;
 if (((Class_B*)*(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x54))->m9(3) != 0) {
  int id = ((Class_B*)*(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x54))->m42(3);
  void* task = ((unsigned int)id + 0x10000U != 0xFFFFU) ? getTask__6gfTaskFi(id) : 0;
  void* castResult = (task != 0) ? __dynamic_cast(task, 0x3C, lbl_27_data_69C0, __RTTI__6gfTask, 0) : 0;
  if (castResult != 0 && getStatusKind__23soExternalValueAccesserFP11StageObject(castResult) == 0x102) {
   float vec[3];
   vec[0] = lbl_27_rodata_46DC;
   vec[1] = lbl_27_rodata_46DC;
   vec[2] = lbl_27_rodata_46DC;
   fn_27_28E48C(self, vec, lbl_27_rodata_46C8);
  }
 }
 return 1;
}