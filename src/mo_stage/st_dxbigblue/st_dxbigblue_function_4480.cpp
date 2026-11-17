#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <mt/mt_trig.h>
#pragma force_active on
extern "C" const float lbl_81_rodata_98[];
struct Vec3 { float x,y,z; Vec3() {} Vec3(float a,float b,double c):x(a),y(b),z(c) {} };
struct Locals { float c,s; Vec3 a,b; Locals(float x,float y,double z):a(x,y,z) {} };
inline float clampFactor(float t, const float* f) {
 float v;
 if(t<f[0]) { v=t/f[0]; if(v<f[1]) v=f[1]; if(v>f[2]) v=f[2]; }
 else { v=f[2]-(t-f[0])/f[0]; if(v<f[1]) v=f[1]; if(v>f[2]) v=f[2]; }
 return v;
}
extern "C" void fn_81_4480(char* self) {
 const float* f=lbl_81_rodata_98;
 char* p=self+0xd0;
 if(p!=0) {
  nw4r::g3d::ScnMdlSimple* m=*(nw4r::g3d::ScnMdlSimple**)(*(char**)(self+0x44));
  if(m!=0) {
   if(m->m_calcWorldCallBack==0) {
    *(int*)(p+0xc)=0; *(int*)(*(char**)(p+4))=*(int*)(self+0xc4);
    m->m_calcWorldCallBack=(nw4r::g3d::ICalcWorldCallBack*)p;
    m->EnableScnMdlCallbackTiming(1);
    m->m_nodeIndex=(short)*(int*)(*(char**)(p+4));
   }
   if (*(Vec3**)(self+0x158)!=0) {
    Vec3* sc=*(Vec3**)(self+0x160);
    if(sc!=0) {
     float amp;
     float factor=clampFactor(sc->z,f);
     double neg;
     float y;
     float x;
     x=sc->x;
     y=sc->y;
     neg=-sc->z;
     amp=f[3]*factor;
     Vec3 b;
     Vec3 a;
     a.x=x;
     a.y=y;
     a.z=-sc->z;
     float s,c;
     mtSinCosf(f[5]*((float)neg-f[4]),&s,&c);
     Vec3* base=*(Vec3**)(self+0x158);
     char* dst=*(char**)(p+4);
     b.x=base->x+amp*c;
     b.y=base->y+amp*s;
     b.z=base->z;
     *(Vec3*)(dst+8)=b;
     dst=*(char**)(p+4);
     *(Vec3*)(dst+0x14)=a;
    }
   }
  }
 }
}
