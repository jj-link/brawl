#include <ft/ft_common_data_accesser.h>
#pragma force_active on
struct LocalVec { float x, y, z; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual int slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual int slot21(int);
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
 virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28();
 virtual void fn_27_7AB50(); virtual void* fn_27_7B2EC();
};
struct Owner { char pad[0x28]; void* value; };
struct Context { char pad[8]; Owner* owner; char pad2[0xcc]; Class_90D8** module; };
extern "C" {
extern char lbl_27_data_31AD8[], lbl_27_data_C938[], lbl_27_data_2C0C0[], lbl_27_data_CBA0[];
extern float lbl_27_rodata_8030;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1E1B14(void*, void*, int, void*, int, int, LocalVec*, unsigned int,
 unsigned int, int, int, int, int, int, int, int, int, int);
int fn_27_3BAF40(void*, Object_vptr_0* obj, Context* ctx) {
 char* params;
 if (obj->slot6() == 13) {
  Object_vptr_0* castObj = (Object_vptr_0*)__dynamic_cast(obj, 0, lbl_27_data_31AD8, lbl_27_data_C938, 0);
  if (!castObj) return 0;
  void* data = g_ftCommonDataAccesser.getData((ftKind)5);
  params = **(char***)((char*)data + 0x64) + 0x1f8;
  Object_vptr_0* target = (Object_vptr_0*)__dynamic_cast((*ctx->module)->fn_27_7B2EC(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
  int id = target->slot21(0x2e);
  LocalVec v;
  v.x = lbl_27_rodata_8030;
  v.y = lbl_27_rodata_8030;
  v.z = lbl_27_rodata_8030;
  fn_27_1E1B14(castObj, ctx->owner->value, id, params, 1, 0, &v, 65535, 65535, 0, 1, 0, -1, 0, 0, 2, 0, 0);
  return 1;
 }
 return 0;
}
}