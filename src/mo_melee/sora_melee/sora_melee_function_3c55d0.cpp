#pragma force_active on
#include <nw4r/math/math_arithmetic.h>
extern "C" float lbl_27_rodata_8084;
extern "C" float fn_27_192278(void*, unsigned long);
class Obj1 { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual int getA(); };
class Obj2 { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void setA(int,int); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual float getFloat(int); };
class Obj4 { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void setB(int,void*); };
struct BaseObj { char pad[0x3c]; };
class Obj5 : public BaseObj { public: virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual int methodA8(); };
struct Inner { char pad14[0x14]; Obj1* p14; char pad64[0x64-0x18]; Obj2* p64; char pad70[0x70-0x68]; Obj4* p70; };
struct Self { char pad8[8]; Obj5* p8; char padD8[0xD8-0xC]; Inner* pD8; };
extern "C" void fn_27_3C55D0(int a, Self* r) {
 if(r->pD8->p14->getA()!=0)return;
 float fa=r->pD8->p64->getFloat(0x21000010); float fb=r->pD8->p64->getFloat(0x21000004); float f0=lbl_27_rodata_8084;
 if(fb>f0){if(fa<f0){float ab=nw4r::math::FAbs(fa);float sp=fn_27_192278(r,0xfc3);float prod=nw4r::math::FAbs(fb*sp);if(ab>=prod){int st=r->p8->methodA8();if(st==5){r->pD8->p64->setA(0x189,0x20000009);r->pD8->p70->setB(0x187,r);}else{r->pD8->p64->setA(0x11b,0x20000009);r->pD8->p70->setB(0x119,r);}}}}else if(fa>f0){float ab=nw4r::math::FAbs(fa);float sp=fn_27_192278(r,0xfc3);float prod=nw4r::math::FAbs(fb*sp);if(ab>=prod){int st=r->p8->methodA8();if(st==5){r->pD8->p64->setA(0x189,0x20000009);r->pD8->p70->setB(0x187,r);}else{r->pD8->p64->setA(0x11b,0x20000009);r->pD8->p70->setB(0x119,r);}}}
}