#include <ft/fighter.h>
#pragma force_active on

class Class_6EB8 {
public:
 virtual void fn_116_DEEC(); virtual void fn_116_DD40(); virtual void fn_116_DD48();
 virtual void fn_116_DD44(); virtual void fn_116_DEE8(); virtual void fn_116_DEE4();
 virtual void fn_116_DEE0(); virtual void fn_116_DEDC(void*); virtual void fn_116_DED8();
 virtual void fn_116_DED0(); virtual void fn_116_DECC(); virtual void fn_116_DEC4();
 virtual void fn_116_DEC0(); virtual void fn_116_DEB8();
};
class Class_7624 {
public:
 virtual void fn_116_7384(); virtual void fn_116_101BC();
 virtual Class_6EB8** fn_116_11518(int); virtual void fn_116_11510();
 virtual int fn_116_11508(); virtual void fn_116_11500();
 virtual void fn_116_114F8(); virtual void fn_116_114F0();
 virtual void fn_116_114E8(); virtual void fn_116_114E0();
 virtual void fn_116_114D8(); virtual void fn_116_114D0();
 virtual void fn_116_114C8(); virtual void fn_116_114C0();
};
class Work {
public:
 virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
 virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
 virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34();
 virtual void v38(); virtual void setFloat(float, int);
};
struct Vect { float x,y,z; };
class Effect {
public:
 virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
 virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
 virtual void v28(); virtual void v2c(); virtual void v30();
 virtual void invoke(unsigned int, unsigned int, Vect*, Vect*, float, int, int, int, int);
};
struct Modules { char pad[0x64]; Work* work; char pad68[0x20]; Effect* effect; };
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" {
void* fn_116_972C();
void fn_27_368D00(void*, void*);
void fn_27_12BAF8(void*, int);
Class_7624* fn_116_9570(void*);
void fn_27_3689A4(void*);
int fn_27_111E30(void*);
Vect* fn_116_971C(Vect*, float, float, float);
extern const float lbl_116_rodata_4, lbl_116_rodata_8;
void fn_116_93B0(char* self, int arg) {
 void* value;
 int i;
 Class_7624* mgr;
 Accesser* accesser = *(Accesser**)(self + 0x60);
 fn_27_368D00(fn_116_972C(), accesser);
 fn_27_12BAF8(self, arg);
 value = *(void**)(self + 0x28);
 mgr = fn_116_9570(self + 0x17fbc);
 for (i = 0; i < mgr->fn_116_11508(); i++)
  (*mgr->fn_116_11518(i))->fn_116_DEDC(value);
 if (arg != 6 && arg != 7) fn_27_3689A4(self + 0x17fa4);
 float f = *(float*)(self + 0x17fb0);
 accesser->modules->work->setFloat(f, 0x11000013);
 f = *(float*)(self + 0x17fb8);
 accesser->modules->work->setFloat(f, 0x11000014);
 if (fn_27_111E30(((Fighter*)self)->getOwner()) == 0) {
  Effect* effect = accesser->modules->effect;
  Vect a,b;
  effect->invoke(0x1e0001, 0x14,
   fn_116_971C(&a,lbl_116_rodata_8,lbl_116_rodata_8,lbl_116_rodata_8),
   fn_116_971C(&b,lbl_116_rodata_8,lbl_116_rodata_8,lbl_116_rodata_8),
   lbl_116_rodata_4,1,0x10,0,-1);
 }
}
}