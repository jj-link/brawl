#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <mt/mt_coll2d.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off
#pragma inline all
extern "C" {
Vec2f fn_27_312B0(void*, const Vec2f*, float);
u32 fn_80111CB0(void*,void*);
u32 fn_80115000(void*,void*);
void getSegment__11grCollisionFP11clSegment2DP15grCollisionLine(void*,void*,void*);
void fn_800407A0(clSegment2D*,Vec2f*,Vec2f*);
float fn_800405E0(clSegment2D*,Vec2f*);
extern const float lbl_27_rodata_450[];
}
#define V10(p) virtual void v##p##0(); virtual void v##p##1(); virtual void v##p##2(); virtual void v##p##3(); virtual void v##p##4(); virtual void v##p##5(); virtual void v##p##6(); virtual void v##p##7(); virtual void v##p##8(); virtual void v##p##9();
namespace matching {
struct GroundBase { u32 unk0, unk4; };
class Ground : public GroundBase {
public:
V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
virtual void v80(); virtual void v81(); virtual void v82();
virtual Vec2f getPosA(int);
virtual void v84(); virtual void v85();
virtual Vec2f getPosB(int);
virtual void v87(); virtual void v88(); virtual void v89();
V10(9)
virtual void v100();
virtual void getRhombus(clRhombus2D*,clRhombus2D*,int);
};
struct Id { u32 v; };
class soNullable {
public:
virtual void isNull();
virtual void fn_27_31270();
virtual int fn_27_31C88();
virtual void fn_27_31DCC();
virtual void fn_27_31E40();
virtual void fn_27_32460();
virtual void fn_27_325B8();
virtual void fn_27_327D8();
virtual void fn_27_32E84();
virtual void fn_27_332E8();
virtual void fn_27_33E20();
virtual void fn_27_33EA8();
virtual void fn_27_34058();
virtual float fn_27_340BC(Ground*,int,int);
u32 unk4;
Id id;
u8 padC[8];
Vec2f position;
u8 pad1C[9],flag;
};
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual Vec3f slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
};
}
using namespace matching;
struct Info {
void* line; void* data; void* collision;
u8 tail; u8 high:1; u8 rest:7;
};
inline float lenSq(const Vec2f& v) {
return v.m_x*v.m_x+v.m_y*v.m_y;
}
inline float sqrtSafe(float sq,const float* k) {
return ((float)(double)nw4r::math::FAbs(sq)<=k[8]) ? k[0] : sq*rsqrtf(sq);
}
inline float len(const Vec2f& v,const float* k) {
return sqrtSafe(lenSq(v),k);
}
inline bool isWithin(const Vec2f& v,float size,const float* k) {
return len(v,k)<=size;
}
inline Vec2f calcCenter(soNullable* self, Vec2f pos, float t) {
Vec2f off;
Vec2f::copy(off,fn_27_312B0(self,&pos,t));
Vec2f r;
Vec2f::copy(r,self->position+off);
return r;
}
inline float getSize(Ground* ground,const float* k) {
clRhombus2D a,b;
ground->getRhombus(&a,&b,0);
Vec2f d;
Vec2f::copy(d,b.m_downPos-a.m_downPos);
return len(d,k);
}
inline bool checkNear(soNullable* self,Object_vptr_0* src,Ground* ground,int index,float t,const float* k) {
Vec3f p=src->slot4();
Vec2f initial(p.m_x,p.m_y);
Vec2f adjusted;
if(self->flag) adjusted=initial;
else {
Vec2f movement;
Vec2f::copy(movement,ground->getPosA(index)-ground->getPosB(index));
adjusted=initial-movement;
}
Vec2f center;
Vec2f::copy(center,calcCenter(self,ground->getPosB(index),t));
return isWithin(adjusted-center,getSize(ground,k),k);
}
extern "C" int fn_27_327D8(soNullable* self,Object_vptr_0* src,Ground* ground,int index,float t) {
const float* k=lbl_27_rodata_450;
gfTaskScheduler* scheduler=gfTaskScheduler::getInstance();
bool mode;
if(scheduler == 0) mode=false;
else mode=(s32)((*(u32*)scheduler<<8)&0xff800000)>>24>=6;
if(!mode) return 0;
if(!self->fn_27_31C88())return 0;
if(checkNear(self,src,ground,index,t,k)==true)return 1;
float angle=self->fn_27_340BC(ground,index,0);
float l=getSize(ground,k);
if((float)(double)nw4r::math::FAbs(t-angle)>=l)return 0;
int valid=0;
Info info;
info.line=0; info.data=0; info.collision=0; info.tail=0; info.high=0;
int ok;
if(self->id.v==0xffff)ok=0;
else {
Id id;
id=self->id;
if(!fn_80111CB0(&id,&info))ok=0;
else {
if(info.line&&info.data&&info.collision)valid=1;
int enabled;
if(valid&&((*(u8*)((char*)info.data+0x54)>>4)&1)&&((*(u8*)((char*)info.collision+0x2c)>>7)&1))enabled=1;
else enabled=0;
ok=enabled!=0;
}
}
if(!ok)return 0;
Vec2f point;
Vec2f::copy(point,ground->getPosB(index));
clSegment2D seg;
getSegment__11grCollisionFP11clSegment2DP15grCollisionLine(info.collision,&seg,info.line);
int dir=fn_80115000(&info,&self->position);
Vec2f intersection;
Vec2f end;
Vec2f::copy(end,calcCenter(self,point,t));
fn_800407A0(&seg,&end,&intersection);
if(!fn_80115000(&info,&end)) {
seg.m_p0Pos=intersection;
} else {
seg.m_p1Pos=intersection;
}
float res=fn_800405E0(&seg,&point);
if(res>k[0]&&res<k[9])return 0;
if(dir==0&&res<=k[0])return 1;
if((u32)dir==1&&res>=k[9])return 1;
return 0;
}
