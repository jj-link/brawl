#pragma force_active on
struct Vec2 { float x,y; Vec2() {} Vec2(float a,float b):x(a),y(b) {} };
struct Vec3 { float x,y,z; };
struct Energy { char pad[5]; unsigned char flags : 1; int enable() { flags = 1; return 1; } };
class Class_6414 { public: virtual void fn_110_CFE8(); virtual void fn_110_CCA8(); virtual void fn_110_CFE4(); virtual void fn_110_CFE0(); virtual void fn_110_CFDC(); virtual void fn_110_CFD8(); virtual Energy* fn_110_CFD4(int); };
struct Modules { char pad[0x7c]; Class_6414* kinetic; };
struct Accesser { char pad[8]; void* owner; char pad2[0xcc]; Modules* modules; };
struct Params { char pad[4]; float* values; };
extern "C" {
extern const float lbl_110_rodata_1D8;
extern const char lbl_110_data_62B8[], lbl_110_data_212C[], lbl_110_data_617C[], lbl_110_data_168C[];
void* __memcpy(void*, const void*, unsigned long);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Params* fn_110_1EF78(void*);
Vec3* fn_110_CC98(Vec3*, float, float, float);
void fn_27_89D08(int, Accesser*, int, Vec2*, Vec3*);
void fn_110_210D8(void*, int, const Vec2* input, Accesser* a) {
 Vec2 speed; __memcpy(&speed, input, sizeof(speed));
 Vec2 gravity(lbl_110_rodata_1D8, speed.y); Vec3 rot1;
 fn_27_89D08(1,a,0,&gravity,fn_110_CC98(&rot1,lbl_110_rodata_1D8,lbl_110_rodata_1D8,lbl_110_rodata_1D8));
 Vec2 motion(speed.x,lbl_110_rodata_1D8); Vec3 rot2;
 fn_27_89D08(3,a,6,&motion,fn_110_CC98(&rot2,lbl_110_rodata_1D8,lbl_110_rodata_1D8,lbl_110_rodata_1D8));
 Energy* energy = a->modules->kinetic->fn_110_CFD4(4);
 bool one = energy->enable();
 float* p = fn_110_1EF78(__dynamic_cast(a->owner,0x3c,lbl_110_data_62B8,lbl_110_data_212C,one))->values;
 char* e = (char*)__dynamic_cast(a->modules->kinetic->fn_110_CFD4(1),0,lbl_110_data_617C,lbl_110_data_168C,one);
 *(float*)(e+0x10) = -p[0]; *(float*)(e+0x1c) = p[1];
}
}
