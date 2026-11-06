#pragma force_active on
struct Vec3 { float x; float y; float z; };
struct FloatAt8 { char pad[8]; float f8; };
struct Sub84 { char pad[0x84]; FloatAt8* sub; };
class Class_9C3C {
public:
 virtual void fn_107_8720();
 virtual void fn_107_160EC();
 virtual void fn_107_166C8();
 virtual void fn_107_166C4();
 virtual void fn_107_166C0();
 virtual void fn_107_166BC();
 virtual void fn_107_166B4();
 virtual void fn_107_166FC();
 virtual void fn_107_166F4();
 virtual void fn_107_166EC();
 virtual void fn_107_166E4();
 virtual void fn_107_166DC();
 virtual void fn_107_16674();
 virtual void fn_107_166A8(float a, int b);
 virtual void fn_107_1669C();
 virtual void fn_107_16694(int a, int b);
};
class Class_9E14 {
public:
 virtual void fn_107_8720();
 virtual void fn_107_16090();
 virtual void fn_107_168B4();
 virtual void fn_107_168AC();
 virtual void fn_107_168A4();
 virtual void fn_107_1689C();
 virtual void fn_107_16894();
 virtual void fn_107_1688C();
 virtual void fn_107_16884();
 virtual void fn_107_1687C();
 virtual void fn_107_16874();
 virtual void fn_107_1686C();
 virtual void fn_107_16864();
 virtual void fn_107_1685C();
 virtual void fn_107_1680C();
 virtual void fn_107_16854(Vec3* a, int b);
};
struct Modules { char pad0[0x0c]; Class_9E14* c0c; char pad1[0x54]; Class_9C3C* c64; char pad2[0x1c]; Class_9C3C* c84; };
struct Accesser { char pad0[0xd8]; Modules* modules; };
extern "C" void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
extern "C" Vec3* fn_107_B444(Vec3*, float, float, float);
extern unsigned char g_ftCommonDataAccesser[];
extern const float lbl_107_rodata_50;
extern "C" void fn_107_12048(void* unused, Accesser* accesser, int kind) {
 if (kind == 0x19) {
  Sub84* data = (Sub84*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12);
  accesser->modules->c64->fn_107_166A8(data->sub->f8, 0x11000000);
 }
 if (kind != 0x117) accesser->modules->c84->fn_107_16694(2, 0);
 Class_9E14* c0c = accesser->modules->c0c;
 Vec3 rot;
 c0c->fn_107_16854(fn_107_B444(&rot, lbl_107_rodata_50, lbl_107_rodata_50, lbl_107_rodata_50), 0);
}