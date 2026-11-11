#include <gf/gf_task.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int fn_27_28CCF0(void*, int);
extern "C" int fn_27_14D6F4(void*, int);
extern "C" int fn_27_8BC8C(void*, void*, int);
extern "C" const char __RTTI__6gfTask[];
extern "C" const char lbl_27_data_4A000[];
extern "C" const char lbl_27_data_248[];
extern "C" const char lbl_27_data_69C0[];
struct SoValue {
 int pad0, v4, v8, padC[5], v20, v24, v28, v2c, pad30[3], v3c, v40;
 unsigned char v44, v45;
};
struct Obj38Base { char pad[8]; };
class Obj38V : public Obj38Base {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
 virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
 virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
 virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
 virtual SoValue* f34();
};
class Obj38 : public Obj38V {};
class M54 {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void* f9(int); virtual void f9a(); virtual void* f10(int);
};
class VClass2 {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual int f4(int, void*);
};
struct So {
 char pad38[0x38]; Obj38* m38; char pad54[0x54-0x3c]; M54* m54;
 char pad64[0x64-0x58]; VClass2* m64;
};
struct Src {
 char pad3c[0x3c]; void* v2; char pad40[0x8c0-0x40]; int m8C0, m8C4, m8C8;
};
struct Acc { char pad8[8]; Src* src; char padC[0xd8-0xc]; So* so; };
extern "C" int fn_27_2BFDD0(void* arg1, Acc* acc, int code) {
 if (code <= 0x5207) return fn_27_8BC8C(arg1, acc, code);
 Src* src = (Src*)__dynamic_cast(acc->src, 0x3c, lbl_27_data_4A000, lbl_27_data_248, 1);
 switch (code - 0x5208) {
 case 0x07: {
  int id=src->m8C8;
  if ((unsigned)id + 0x10000U != 0xFFFFU) {
   gfTask* task=gfTask::getTask(id);
   void* cast=task ? __dynamic_cast(task,0x3c,lbl_27_data_4A000,__RTTI__6gfTask,0) : 0;
   if (cast) return ((Src*)cast)->m8C0;
   return -1;
  }
  return -1;
 }
 case 0x08: {
  int id=src->m8C8;
  if ((unsigned)id + 0x10000U != 0xFFFFU) {
   gfTask* task=gfTask::getTask(id);
   void* cast=task ? __dynamic_cast(task,0x3c,lbl_27_data_4A000,__RTTI__6gfTask,0) : 0;
   if (cast) return fn_27_28CCF0(cast,0x1000000D);
   return 0;
  }
  return 0;
 }
 case 0x09: {
  int id=acc->so->m64->f4(0x10000014,acc->so);
  if (id != -1) {
   gfTask* task=gfTask::getTask(id);
   void* cast=task ? __dynamic_cast(task,0x3c,lbl_27_data_4A000,__RTTI__6gfTask,0) : 0;
   if (cast) return fn_27_28CCF0(cast,0x1000000D);
   return 0;
  }
  return 0;
 }
 case 0x0A: {
  int id=acc->so->m64->f4(0x10000013,acc->so);
  if ((unsigned)id + 0x10000U != 0xFFFFU) {
   gfTask* task=gfTask::getTask(id);
   void* cast=task ? __dynamic_cast(task,0x3c,lbl_27_data_248,__RTTI__6gfTask,0) : 0;
   if (!cast) return 2;
   return soExternalValueAccesser::getSituationKind((StageObject*)cast);
  }
  return 2;
 }
 case 0x0B: return src->m8C4;
 case 0x0D: return src->m8C0;
 case 0x00: return acc->so->m38->f34()->v4;
 case 0x01: return acc->so->m38->f34()->v8;
 case 0x02: return 0;
 case 0x03: return acc->so->m38->f34()->v20;
 case 0x04: return acc->so->m38->f34()->v24;
 case 0x05: return acc->so->m38->f34()->v3c;
 case 0x14: return acc->so->m38->f34()->v40;
 case 0x0E: return acc->so->m38->f34()->v44;
 case 0x06: return acc->so->m38->f34()->v2c;
 case 0x0F: return (acc->so->m38->f34()->v45 >> 2) & 1;
 case 0x0C: {
  if (acc->so->m54->f9(3)) {
   void* value=acc->so->m54->f10(3);
   if (value) return ((SoValue*)value)->v28;
   return -1;
  }
  return -1;
 }
 case 0x10: return src->m8C8;
 case 0x11: case 0x12: case 0x13: {
  if (acc->so->m54->f9(3)) {
  void* value=acc->so->m54->f10(3);
  if (!value) return 0;
  void* cast=__dynamic_cast(value,0x3c,lbl_27_data_69C0,lbl_27_data_248,0);
  if (!cast) return 0;
  if (code==0x5219) return fn_27_14D6F4(cast,0);
  if (code==0x521A) return fn_27_14D6F4(cast,1);
  if (code==0x521B) return fn_27_14D6F4(cast,2);
  }
  return 0;
 }
 }
 return 0;
}