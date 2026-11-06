#pragma force_active on
#pragma fp_contract off
typedef unsigned int u32;
struct Work { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual int getInt(u32); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slotA(); virtual void slotB(); virtual void slotC(); virtual void slotD(); virtual void slotE(); virtual void slotF(); virtual void slot10(); virtual u32 isFlag(u32); };
struct Modules { char pad00[0x64]; Work* work; };
struct Access { char pad00[0xD8]; Modules* modules; };
struct Constants { float zero; float pad04[3]; float one; float pad14[2]; float half; };
extern "C" {
extern const unsigned char lbl_27_rodata_26B0[];
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Access*, u32, u32);
float randf__Fv();
int fn_27_194230(Access* access, int mode, float factor) {
const Constants* c = (const Constants*)lbl_27_rodata_26B0;
if (access->modules->work->isFlag(0x12000025) != 1) {
if (access->modules->work->getInt(0x1000000a) <= 0) {
float chance = c->zero;
switch (mode) {
case 0: {
float a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xC86, 0);
float b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xC87, 0);
float t = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xDB2, 0);
t = c->one + t; t *= c->half; chance = t * (a - b) + b;
break;
}
default: break;
}
if (c->zero != chance) { float adjusted = chance + factor; if (c->zero != adjusted) { if (adjusted >= randf__Fv()) return 1; } }
}
}
return 0;
}
}