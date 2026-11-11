#pragma force_active on
extern "C" {
extern float lbl_805A13F8, lbl_805A13FC, lbl_805A1400, lbl_805A1404, lbl_805A1408, lbl_805A140C, lbl_805A1410, lbl_805A1414;
extern int lbl_8059FFC0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_80019FEC();
void fn_80018778(void*);
}
struct Mgr { unsigned char pad0[0x738]; float f738, f73C; };
struct Obj {
unsigned char pad0[0x60];
float f60,f64,f68,f6C,f70,f74;
unsigned char pad78[0xc];
float f84,f88,f8C,f90,f94,f98,f9C,fA0,fA4,fA8,fAC,fB0,fB4,fB8,fBC;
unsigned char padC0[8];
float fC8,fCC,fD0,fD4,fD8,fDC,fE0,fE4,fE8,fEC,fF0,fF4;
short fF8,fFA; int fFC,f100;
unsigned char pad104[0x10];
float f114,f118,f11C,f120,f124,f128;
short f12C,f12E,f130,f132;
};
extern "C" void fn_80018610(Obj* obj) {
{
float v0, v1, v2, v3;
v3 = 0.0f;
v1 = 1.0f;
v2 = 85.0f;
v0 = 0.5235987901687622f;
obj->fFC=0; obj->f6C=v3; obj->f70=v3; obj->f74=v2;
obj->f60=v3; obj->f64=v3; obj->f68=v3; obj->fCC=v2;
obj->f84=v3; obj->f88=v1; obj->f8C=v3; obj->f90=v1;
obj->f94=v3; obj->f98=v3; obj->f9C=v3; obj->fA0=v3;
obj->fA4=v3; obj->fA8=v3; obj->fAC=v3; obj->fB0=v3;
obj->fB4=v3; obj->fB8=v3; obj->fBC=v3; obj->fC8=v3;
obj->fD4=v1; obj->fD0=v0;
}
if (lbl_8059FFC0 == 0 && lbl_8059FFC0 == 0 && __nw__FUlQ25Heaps8HeapType(0x740, 1) != 0) fn_80019FEC();
Mgr* mgr=(Mgr*)lbl_8059FFC0;
{
float f_j, f_g, f_c, f_a, f_h, f_i, f_d0, f_mult;
f_d0=obj->fD0;
f_mult=mgr->f73C*mgr->f738;
f_a=lbl_805A13F8;
f_c=lbl_805A140C;
f_g=lbl_805A1410;
f_i=lbl_805A1400;
f_h=lbl_805A1408;
f_j=lbl_805A1414;
obj->fE4=f_mult; obj->fD8=f_d0; obj->fDC=f_i; obj->fE0=f_h;
obj->fF8=0x43; obj->fFA=0;
obj->f114=f_a; obj->f118=f_a; obj->f11C=f_c; obj->f120=f_g; obj->f124=f_a; obj->f128=f_j;
obj->f12C=0; obj->f12E=0; obj->f130=0x280; obj->f132=0x1e0;
obj->f100=1; obj->fE8=f_a; obj->fF0=f_a; obj->fEC=f_g; obj->fF4=f_c;
fn_80018778(obj);
}
}