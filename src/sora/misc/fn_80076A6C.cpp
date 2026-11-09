#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(int,int); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(int,float);
};
inline float clamp(float x,float hi,float lo) {
float m=nw4r::math::FSelect(hi-x,x,hi);
return nw4r::math::FSelect(lo-m,lo,m);
}
extern const float lbl_805A1AC8;
extern const float lbl_805A1ACC;
extern "C" int fn_80076A6C(unsigned char* self,int arg) {
if(self[0x6ef]==0)return 0;
if(self[0x720]==0)return 0;
self[0x720]=0;
if(*(int*)(self+0x724)==1) {
Object_vptr_0* s=*(Object_vptr_0**)(self+0x6e0);
if(s)s->slot5(0,0);
} else if(arg) {
Object_vptr_0* s=*(Object_vptr_0**)(self+0x6e0);
float r=clamp(*(float*)(self+0x700),lbl_805A1AC8,lbl_805A1ACC);
*(float*)(self+0x708)=lbl_805A1AC8;
*(float*)(self+0x700)=r;
float v=*(float*)(self+0x714)*(*(float*)(self+0x704)*((float)(double)r*lbl_805A1AC8));
if(s)s->slot12(0,v);
}
unsigned char* e=self;
for(unsigned int i=0;i<32;i++,e+=0x20) {
if(*(unsigned int*)(e+0x2dc)!=0x10000u) {
int t=0;
if(*(unsigned int*)(e+0x2e0)+0x10000!=0xffff && *(unsigned short*)(e+0x2f0)!=0)t=1;
int r;
if(t)r=1;else r=*(Object_vptr_0**)(e+0x2d4)!=0;
if(r && *(Object_vptr_0**)(e+0x2d4))(*(Object_vptr_0**)(e+0x2d4))->slot5(0,0);
}
}
return 1;
}
