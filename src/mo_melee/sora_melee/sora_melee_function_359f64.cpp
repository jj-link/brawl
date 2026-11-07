#pragma force_active on
struct Object;
struct Pair { unsigned int a; float b; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1(Object*);
 virtual unsigned long long slot2();
 virtual int slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6(int,int);
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual bool slot17(unsigned int);
};
struct Pad8 { char pad[8]; };
struct Status : Pad8 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18();
 virtual void change(int, int);
};
struct Modules {
 char pad[0x10];
 Status* status;
 Object_vptr_0* state;
 char pad2[0x4c];
 Object_vptr_0* work;
};
struct Object { char pad[0xd8]; Modules* modules; };
struct Self : Object_vptr_0 { unsigned char field4; unsigned char flags : 1; unsigned char rest : 7; unsigned char field6; };
extern float lbl_27_rodata_79E8;
extern "C" void fn_27_359F64(Self* self, int unused, Object* object) {
 if ((unsigned int)(self->flags != 0) == 1 && self->field6 == 0)
  self->slot1(object);
 if (object->modules->state->slot3() == 0) {
  int flag = 0;
  union { unsigned long long value; Pair pair; } result;
  result.value = self->slot2();
  if (result.pair.b > lbl_27_rodata_79E8 && !object->modules->work->slot17(0x22000011))
   flag = 1;
  if (flag) {
   object->modules->state->slot6(2, 0);
   object->modules->status->change(5, 0);
  }
 }
}