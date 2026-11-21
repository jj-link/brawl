#pragma force_active on
#pragma fp_contract off
#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_matrix.h>
struct Vec2 { float x,y; };
struct SelObj {
virtual void m00(); virtual void m01(); virtual void m02(); virtual void m03();
virtual void m04(); virtual void m05(); virtual void m06(); virtual void m07();
virtual void m08(); virtual void m09(); virtual void m10();
virtual void m13(void*,void*); virtual void m14(); virtual void m15(void*);
char pad[0xe0]; void* member_e4;
};
extern "C" {
u64 fn_10_1BC38(void*);
float rsqrtf__Ff(float);
void fn_801AAF04(void*,int,Matrix*);
extern const float lbl_10_rodata_7D0[];
}
inline Vec2f convert(Vec2 p) { return *(Vec2f*)&p; }
inline Vec2f position(u8* self) { Vec2 p; p.y=*(float*)(self+0x94); p.x=*(float*)(self+0x90); return *(Vec2f*)&p; }
extern "C" void fn_10_1B52C(u8* self) {
const float* k=lbl_10_rodata_7D0;
Vec2f current;
Vec2f delta;
Vec2f target;
u64 p=fn_10_1BC38(*(void**)(self+0xa0));
Vec2f::copy(target, *(Vec2f*)&p);
current=position(self);
delta=*(Vec2f*)&target-current;
float sq=delta.m_x * delta.m_x + delta.m_y * delta.m_y;
float mag;
if ((float)(double)nw4r::math::FAbs(sq)<=k[30]) mag=k[1];
else mag=sq*rsqrtf__Ff(sq);
int b;
int flag;
if(mag>k[33]) { float sc=k[33]/mag; delta.m_x*=sc; delta.m_y*=sc; flag=0; }
else flag=1;
float s=*(float*)(self+0xcc);
current.m_x+=delta.m_x; current.m_y+=delta.m_y;
*(float*)(self+0x90)=current.m_x; *(float*)(self+0x94)=current.m_y;
Vec3f scale,rot;
scale.m_x=s; scale.m_y=scale.m_x; scale.m_z=k[0];
rot.m_x=k[1]; rot.m_y=k[1]; rot.m_z=k[1];
Matrix matrix;
matrix.setSRT(scale,rot,*(Vec3f*)(self+0x90));
fn_801AAF04(*(void**)(self+0x44),0,&matrix);
if(flag) {
b=(*(u32*)(*(u8**)(self+0x9c)+0x1dc)>>31)^1;
SelObj* o=*(SelObj**)(self+0x40);
o->m15(*(void**)(self+0x44));
if(b && !self[0xdc]) {o=*(SelObj**)(self+0x40); o->m13(o->member_e4,*(void**)(self+0x44));}
self[0xd0]=b; *(int*)(self+0xa4)=0; *(int*)(self+0xa8)=0;
}
}