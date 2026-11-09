#pragma force_active on
extern float lbl_27_rodata_2378;
extern float lbl_27_rodata_237C;
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int, unsigned int, int = 0, int = 0);
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20();
 virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
 virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(int*, float);
 virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36();
 virtual int slot37(int);
 virtual void slot38();
 virtual void slot39(int, int, int, int, int, float, float);
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44();
 virtual int slot45(int);
};
#define V(n) virtual void f##n();
#define V10(n) V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)
struct Base { char pad[0x3c]; };
class Fighter : public Base {
public:
 V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
 V10(10) V10(11) V10(12) V10(13) V10(14) V10(15) V10(16) V10(17)
 V(180) V(181) V(182) V(183) V(184)
 virtual int get();
};
class SubModule {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int, unsigned int);
};
struct Modules {
 char pad0[8]; Object_vptr_0* motion;
 char pad1[0x50-0xc]; Object_vptr_0* sound;
 char pad2[0x64-0x54]; SubModule* sub;
 char pad3[0xa8-0x68]; Object_vptr_0* work;
};
struct Owner { char pad0[8]; void* obj; char pad1[0xd8-0xc]; Modules* modules; };
struct Param { int kind; float a, b; char c0,c1,c2,c3; };
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" const char lbl_27_data_69C0[];
extern "C" const char lbl_27_data_248[];
extern "C" void fn_27_1D6434(int,int,int,int,Owner*);
extern "C" void fn_27_17C174(void*, Owner* owner) {
 int r = owner->modules->work->slot37(0);
 int ret = owner->modules->motion->slot45(1);
 if (ret != -1) {
  int kind = (r == 0) ? 0x16c : 0x164;
  owner->modules->motion->slot39(1, kind, 0x135, 0, 0, lbl_27_rodata_2378, lbl_27_rodata_237C);
 } else {
  Param p;
  int kind = 0x168;
  if (r == 0) kind = 0x170;
  p.kind = kind;
  p.a = lbl_27_rodata_2378;
  p.b = lbl_27_rodata_237C;
  p.c0 = 0; p.c1 = 0; p.c2 = 0; p.c3 = 0;
  owner->modules->motion->slot30((int*)&p, lbl_27_rodata_2378);
 }
 if (r == 0) owner->modules->sound->slot5(0x1f9d, 0, 0, 0);
 owner->modules->sub->slot5(1, 0x2000000c);
 Fighter* f = (Fighter*)__dynamic_cast(owner->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
 fn_27_1D6434(2, 0x65, 1, f->get(), owner);
}