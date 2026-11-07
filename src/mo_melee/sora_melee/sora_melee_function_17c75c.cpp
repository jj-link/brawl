#pragma force_active on
#include <so/controller/so_controller_impl.h>
#include <so/so_value_accesser.h>

#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)

class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(int); virtual void slot5(int,int); virtual void slot6(); virtual void slot7(float);
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual int slot17(int); virtual void slot18(int); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual int slot37(int); virtual void slot38(); virtual unsigned char slot39(int);
 virtual void slot40(); virtual unsigned slot41(); virtual void slot42(); virtual void slot43();
 virtual void slot44(); virtual int slot45(int); virtual void slot46(int,float);
};
struct Object_vptr_c_base { char pad[0xc]; };
class Object_vptr_c : public Object_vptr_c_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(int,int,int);
};
struct ObjectBase { char pad[0x3c]; };
struct Obj : ObjectBase {
 V32(a) V32(b) V32(c) V32(d) V32(e)
 V8(f0) V8(f1) V8(f2)
 virtual void h184();
 virtual Object_vptr_c* get();
};
struct Modules {
 char pad0[8]; Object_vptr_0* m8;
 char padC[0x50]; Object_vptr_0* m5c;
 char pad60[4]; Object_vptr_0* work;
 char pad68[0x40]; Object_vptr_0* ma8;
};
struct Access {
 char pad[8]; void* obj; char padC[0xcc]; Modules* modules;
};
extern "C" {
 void fn_27_17E908(Access*);
 void* __dynamic_cast(void*, long, const void*, const void*, short);
 extern const char lbl_27_data_69C0[];
 extern const char lbl_27_data_248[];
 extern float lbl_27_rodata_2380;
}
extern "C" void fn_27_17C75C(void* self, Access* acc) {
 switch (acc->modules->work->slot4(0x2000000c)) {
 case 0:
  if (acc->modules->work->slot17(0x22000013)) {
   if (acc->modules->m8->slot45(1) != -1)
    acc->modules->m8->slot46(1, lbl_27_rodata_2380);
   else
    acc->modules->m8->slot7(lbl_27_rodata_2380);
   acc->modules->work->slot5(1, 0x2000000c);
   if (acc->modules->ma8->slot37(0) > 0) {
    Obj* o = (Obj*)__dynamic_cast(acc->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    o->get()->slot13(1, 0x1d, 0);
   }
  }
  break;
 case 1: {
  Object_vptr_0* c = acc->modules->m5c;
  unsigned mask = soController::getButtonMask(soController::Pad_Button_Attack);
  unsigned k = c->slot41();
  if (!(k & mask)) {
   int n = soValueAccesser::getConstantInt((soModuleAccesser*)acc, 0x5a63, 0);
   if (acc->modules->m5c->slot39(0) >= n) {
    acc->modules->work->slot18(0x22000014);
    acc->modules->work->slot18(0x22000012);
   }
  }
  break;
 }
 }
 fn_27_17E908(acc);
}