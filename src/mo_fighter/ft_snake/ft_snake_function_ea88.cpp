#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float* fn_122_D580(float*, float, float, float);
void fn_27_28E108(void*, const float*, float, float);
void fn_27_28E48C(void*, const float*);
extern const char lbl_122_data_168[], lbl_122_data_774[], lbl_122_data_8554[], lbl_122_data_8C98[];
extern const float lbl_122_rodata_0[];
}
class Class_DF18 {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual int f16(); virtual void f17();
};
class Class_E104 {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual void f16(); virtual int f17(int);
};
class Object2C {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
 virtual void f8(); virtual float f9();
};
struct Modules {
 char pad[0x0C]; Object2C* object; char pad2[0x54]; Class_E104* mod64;
 char pad3[0x08]; Class_DF18* mod70;
};
struct Fighter { char pad[0x08]; void* unk8; char pad2[0xCC]; Modules* modules; };
extern "C" int fn_122_EA88(Class_DF18* self, void* pad, Fighter* fighter) {
 float* result;
 const float* rodata = lbl_122_rodata_0;
 self = (Class_DF18*)__dynamic_cast(self, 0, lbl_122_data_168, lbl_122_data_8554, 0);
 if (self == 0) return 0;
 if (__dynamic_cast(fighter->unk8, 0x3c, lbl_122_data_774, lbl_122_data_8C98, 0) == 0) return 0;
 if (fighter->modules->mod70->f16() == 0x10F) {
  fighter = (Fighter*)fighter->modules->object;
  float vec[3];
  result = fn_122_D580(vec, rodata[3], rodata[3], rodata[3]);
  float val = ((Object2C*)fighter)->f9();
  fn_27_28E108(self, result, val, rodata[1]);
 } else if (fighter->modules->mod64->f17(0x22000010) != 0) {
  float vec[3];
  vec[0] = rodata[7] * fighter->modules->object->f9();
  vec[1] = rodata[8]; vec[2] = rodata[3];
  fighter->modules->object->f9();
  fn_27_28E48C(self, vec);
 } else {
  float vec[3];
  vec[0] = rodata[7] * fighter->modules->object->f9();
  vec[1] = rodata[9]; vec[2] = rodata[3];
  float val = fighter->modules->object->f9();
  fn_27_28E108(self, vec, val, rodata[1]);
 }
 return 0;
}