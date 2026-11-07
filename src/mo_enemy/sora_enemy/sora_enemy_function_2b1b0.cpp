#pragma force_active on
typedef unsigned int u32;
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual int slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual u32 slot17(u32);
};
struct Modules { char pad[0x44]; Object_vptr_0* field44; char pad2[0x1c]; Object_vptr_0* field64; };
struct Access { char pad[8]; void* object; char pad2[0xcc]; Modules* modules; };
struct Self { char pad[0xac]; int a; int b; };
extern "C" {
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
u32 fn_41_29008(void*, int, int);
u32 fn_27_746B0(Self*, Access*);
u32 fn_41_2B1B0(Self* self, Access* access) {
 char* obj = (char*)__dynamic_cast(access->object, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
 u32 result = 0;
 if (self->a == -50 && self->b == 250) {
  fn_41_29008(obj + 0x1108, -100, -100);
  if (fn_27_746B0(self, access) == 1) return 1;
  if (access->modules->field64->slot17(0x12000004) == 1 || access->modules->field64->slot17(0x22000000) == 1)
   result = fn_41_29008(obj + 0x1108, -250, -150);
  else if (access->modules->field44->slot9() == 0)
   result = fn_41_29008(obj + 0x1108, self->a, self->b);
 } else {
  result = fn_41_29008(obj + 0x1108, self->a, self->b);
 }
 if (result == 1) return 1;
 return fn_27_746B0(self, access);
}
}