#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>
typedef unsigned long long u64;
struct Vec2 { float x,y; };
struct Vec3 { float x,y,z; Vec3() {} };
inline Vec2 unpack(u64 bits) { return *(Vec2*)&bits; }
struct Dst { virtual void d0(); virtual void d1(); virtual u64 d2(); };
struct Energy { virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual void e5(); virtual void* get(int); };
struct Posture {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
virtual Vec3 s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
virtual float direction(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
virtual void setRot(const Vec3*,int); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual float s22();
};
struct ModelBase { char pad[8]; };
struct Model : ModelBase {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21();
virtual void setSRT(int,const Vec3*,const Vec3*,const Vec3*);
};
struct Modules { char pad0[4]; Model* model; char pad1[4]; Posture* posture; char pad2[0x6c]; Energy* energy; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x60]; Access* access; };
extern "C" {
extern char lbl_27_data_457C0[],lbl_27_data_CDF8[];
extern const float lbl_27_rodata_63B8[];
void* __dynamic_cast(void*,long,const void*,const void*,short);
float rsqrtf__Ff(float);
double atan2(double,double);
void fn_27_2E466C(void* arg0) {
const float* k=lbl_27_rodata_63B8;
Access* access=((Self*)arg0)->access;
float s=access->modules->posture->s22();
Vec3 pos=access->modules->posture->s4();
Dst* dst=(Dst*)__dynamic_cast(access->modules->energy->get(0),0,lbl_27_data_457C0,lbl_27_data_CDF8,1);
float dir=access->modules->posture->direction();
u64 bits=dst->d2();
Vec2 v=unpack(bits);
float sum=v.x*v.x+v.y*v.y;
float mag;
if ((float)(double)nw4r::math::FAbs(sum)<=k[4]) mag=k[1]; else mag=sum*rsqrtf__Ff(sum);
float angle;
if(mag>k[5]) angle=-(float)atan2(v.y,v.x*dir); else angle=k[1];
Vec3 rot,scale;
rot.x=k[6]*angle; rot.y=(k[2]==dir)?k[7]:k[8]; rot.z=k[1];
scale.x=s; scale.y=s; scale.z=s;
access->modules->model->setSRT(0,&scale,&rot,&pos);
access->modules->posture->setRot(&rot,0);
}
}