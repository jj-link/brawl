#pragma force_active on
typedef unsigned long u32;
class soNullable {
public:
 virtual void isNull();
 virtual void* slot1(void*, void*);
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual u32 slot5();
 virtual u32 slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual int slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual u32 slot17(u32);
 virtual void slot18();
 virtual void slot19(u32);
};
class Class_6E20 {
public:
 virtual void fn_41_3516C();
 virtual void fn_41_34F30();
 virtual void fn_41_350A4();
 virtual void fn_41_350AC();
 virtual void fn_41_350B4();
 virtual void fn_41_350BC();
 virtual void fn_41_350DC();
 virtual void fn_41_350C4();
 virtual void fn_41_35120();
 virtual void fn_41_350CC();
 virtual void fn_41_350D4();
 virtual void fn_41_350E4();
 virtual void fn_41_350EC();
 virtual void fn_41_350F0();
 virtual void fn_41_350F4();
 virtual void fn_41_350F8();
 virtual void fn_41_350FC();
 virtual void fn_41_35108();
 virtual void fn_41_3510C();
 virtual void fn_41_13638();
};
struct Arg {
 char pad0[8]; float x; float y;
 char pad10[0x5c]; u32 flags;
};
class Self {
public:
 int pad[2];
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
 virtual void s20(); virtual u32 s21(Arg*);
};
extern "C" {
 void* __dynamic_cast(void*, long, const void*, const void*, short);
 void fn_27_2330C4(void*, int);
 void fn_41_4D5C(void*);
 void fn_41_108F8(void*, Arg*, u32);
 int fn_41_12014(void*);
 void fn_41_118D0(void*, Arg*);
 void fn_41_11830(void*, Arg*);
 void fn_41_119D4(void*, void*);
 int fn_41_11CBC(void*, void*, u32);
 float fn_41_11B48(void*);
 void fn_41_11454(void*, Arg*);
 extern char __RTTI__5Enemy[];
 extern char __RTTI__11StageObject[];
 extern void* g_stTriggerMng;
 extern float lbl_41_rodata_BE0;
}
#define PTR(p, offset) (*(char**)((char*)(p) + (offset)))
#define MOD(self, off) ((soNullable*)PTR(PTR(PTR(self, 0x3c), 0xd8), off))
#define CAST(self) __dynamic_cast(PTR(PTR(self, 0x3c), 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1)
extern "C" int fn_41_12100(char* self, void* unused) {
 char* modules = PTR(PTR(self, 0x3c), 0xd8);
 soNullable* work = (soNullable*)PTR(modules, 0x64);
 Arg* arg = (Arg*)((soNullable*)PTR(self, 0x40))->slot1(unused, modules);
 u32 state = MOD(self, 0x40)->slot5();
 void* obj = CAST(self);
 u32 special = 0;
 if (work->slot17(0x12000010) == 1 && work->slot17(0x12000013) == 1) {
  work->slot19(0x12000010);
  special = 1;
 }
 if (work->slot17(0x12000000) == 1) {
  if (state == 1 || special == 1) {
   if (special == 1 || MOD(self, 0x40)->slot12() == 0) {
    if (g_stTriggerMng) {
     void* cast = CAST(self);
     fn_27_2330C4(PTR(cast, 0xb0), 1);
    }
    fn_41_4D5C(obj);
    fn_41_108F8(self, arg, state);
    return fn_41_12014(self);
   }
   fn_41_118D0(self, arg);
   return fn_41_12014(self);
  }
  return 0;
 }
 if (*(int*)(self + 0xdc) == 1) {
  *(int*)(self + 0xdc) = -1;
  fn_41_119D4(self, (char*)arg + 0x10);
  fn_41_11830(self, arg);
  return fn_41_12014(self);
 }
 *(int*)(self + 0xdc) = -1;
 if (lbl_41_rodata_BE0 == arg->y && arg->x <= lbl_41_rodata_BE0)
  return 0;
 fn_41_119D4(self, (char*)arg + 0x10);
 int result = fn_41_11CBC(self, (char*)arg + 4, state);
 u32 low = 0;
 if (arg->y <= fn_41_11B48(self))
  low = 1;
 int blocked = 0;
 if (MOD(self, 0x3c)->slot6() == 1 || state == 1) {
  blocked = 1;
  if (state == 1) {
   if (MOD(self, 0x40)->slot12() == 0) {
    if (work->slot17(0x12000000) == 1 && g_stTriggerMng) {
     void* cast = CAST(self);
     fn_27_2330C4(PTR(cast, 0xb0), 1);
    }
    fn_41_4D5C(obj);
   } else {
    fn_41_118D0(self, arg);
    return fn_41_12014(self);
   }
  }
 }
 if (work->slot17(0x12000013) == 1)
  blocked = 1;
 if ((arg->flags & 31) == 7 && result == 0 && blocked == 0) {
  fn_41_11454(self, arg);
 } else if (low == 1 && result == 0 && blocked == 0) {
  fn_41_118D0(self, arg);
  return fn_41_12014(self);
 } else if (((Self*)self)->s21(arg) == 1 && result == 0 && blocked == 0) {
  fn_41_118D0(self, arg);
  return fn_41_12014(self);
 } else {
  fn_41_108F8(self, arg, state);
 }
 return fn_41_12014(self);
}