#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>
struct ModuleA {
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual float getValue(u32); virtual void setValue(u32,float);
virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30();
};
struct ModuleB {
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual float call44(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void call80(void*);
};
struct Modules { char pad00[8]; ModuleB* moduleB; char pad0C[0x58]; ModuleA* moduleA; };
struct Access { char pad00[0xD8]; Modules* modules; };
inline float clampValue(float v,float lo,float hi) {
float t=nw4r::math::FSelect(v-lo,v,lo);
return nw4r::math::FSelect(t-hi,hi,t);
}
extern "C" {
extern const float lbl_27_rodata_7C38[];
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Access*,u32,u32);
void fn_27_3865CC(void*,Access* self) {
const float* ro=lbl_27_rodata_7C38;
float val_a=self->modules->moduleA->getValue(0x11000018);
float val_b=self->modules->moduleA->getValue(0x11000016);
float max_step=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFA2,0);
float upper=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFA3,0);
float direction;
float clamped=clampValue(val_b,-upper,upper);
float diff=clamped-val_a;
if(diff>ro[2]) direction=ro[0]; else direction=ro[1];
float abs_diff=(float)(double)nw4r::math::FAbs(diff);
if(abs_diff>max_step) diff=max_step*direction;
Modules* modules=self->modules;
float updated_value=val_a+diff;
modules->moduleA->setValue(0x21000005,updated_value);
int id;
if(direction<ro[2]) id=0x1D2; else id=0x1D3;
struct Param { int id; float f; float g; unsigned char b[4]; } param;
param.id=id; param.f=ro[2]; param.g=ro[0];
param.b[0]=0; param.b[1]=0; param.b[2]=0; param.b[3]=0;
self->modules->moduleB->call80(&param);
float rate=self->modules->moduleB->call44();
self->modules->moduleA->setValue(0x21000004,diff/(rate-ro[0]));
}
}