#pragma force_active on
extern "C" {
extern char lbl_27_data_29510[];
extern char lbl_27_data_CDF8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual int slot3();
 virtual int slot4(int);
 virtual void slot5(int,int);
 virtual void* slot6(int);
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual float slot12(int);
};
struct Modules {
 char pad[0x14];
 Object_vptr_0* m14;
 char pad2[0x4c];
 Object_vptr_0* m64;
 char pad3[0x14];
 Object_vptr_0* m7c;
};
struct Obj { char pad[0xd8]; Modules* modules; };
struct Target { char pad[0x38]; float x; char pad2[8]; float y; };
extern "C" void fn_27_32907C(Obj*);
extern "C" void fn_27_328F64(void*, Obj* obj) {
 Modules* modules = obj->modules;
 Object_vptr_0* work = modules->m64;
 int value = modules->m14->slot3();
 int old = work->slot4(0x20000002);
 work->slot5(value, 0x20000002);
 if (value != old) {
  Target* target = (Target*)__dynamic_cast(obj->modules->m7c->slot6(0), 0, lbl_27_data_29510, lbl_27_data_CDF8, 1);
  float f = work->slot12(0x21000004);
  if (f != target->x) {
   target->y = -target->y;
   target->x = f;
  }
 }
 if (value == 2) fn_27_32907C(obj);
}