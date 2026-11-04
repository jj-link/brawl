#pragma force_active on
struct Data { int value; unsigned char flag; };
class Class_CD28 {
public:
 virtual void fn_96_28D0();
 virtual void fn_96_2331C();
 virtual void fn_96_23D84();
 virtual void fn_96_23D7C();
 virtual void fn_96_23D74();
 virtual void fn_96_23D6C();
 virtual void fn_96_23D64();
 virtual void fn_96_23D5C();
 virtual void fn_96_23D54();
 virtual void fn_96_23D4C();
 virtual void fn_96_23D44(int, int, int);
 virtual void fn_96_23D3C();
 virtual void fn_96_23D34();
 virtual void fn_96_23D2C();
 virtual void fn_96_23CDC();
 virtual void fn_96_23D24();
 virtual void fn_96_23D14(int, int);
 virtual void fn_96_23D04();
 virtual int fn_96_23CF4(int);
 virtual void fn_96_23CE4();
};
struct Module {
 virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
 virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
 virtual void p8(int); virtual int p9(int); virtual int p10(int);
 virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
 virtual void p16(int, Data*, int);
};
struct Work {
 virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
 virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
 virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11();
 virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
 virtual void p16(); virtual int isFlag(int); virtual void p18(); virtual void offFlag(int);
};
struct Modules {
 char pad[0x54]; Module* module;
 char pad58[0xc]; Work* work;
 char pad68[0x1c]; Class_CD28* other;
};
struct Fighter { char pad[0xd8]; Modules* modules; };
extern "C" void fn_96_1BEC8(void*, Fighter*);
extern "C" void fn_96_1BFA4(void*);
extern "C" void fn_96_1C034(void*);
extern "C" void fn_96_1B5A0(void* self, Fighter* fighter, int kind) {
 switch (kind) {
 case 0x116: case 0x12e: case 0x12f: case 0x130: case 0x131: case 0x132:
  break;
 default:
  if (fighter->modules->module->p10(4)) {
   Data data; data.value = 0x32; data.flag = 0;
   fighter->modules->module->p16(4, &data, 0);
  }
  if (fighter->modules->module->p9(6))
   fighter->modules->module->p8(6);
  fn_96_1BEC8(self, fighter);
  fn_96_1BFA4(self);
  fn_96_1C034(self);
  fighter->modules->work->offFlag(0x12000001);
  fighter->modules->other->fn_96_23D14(4, 0);
  fighter->modules->other->fn_96_23D14(5, 0);
  fighter->modules->other->fn_96_23D14(6, 0);
  fighter->modules->other->fn_96_23D14(7, 0);
  fighter->modules->other->fn_96_23D14(8, 0);
  fighter->modules->other->fn_96_23D14(9, 0);
  if (fighter->modules->work->isFlag(0x12000042)) {
   if (fighter->modules->other->fn_96_23CF4(10))
    fighter->modules->other->fn_96_23D44(10, 1, 0);
  }
 }
}