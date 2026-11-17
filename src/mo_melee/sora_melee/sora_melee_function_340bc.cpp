#include <gf/gf_task_scheduler.h>
#include <gr/collision/gr_collision.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma fp_contract off
extern const float lbl_27_rodata_450[];
extern "C" int fn_80111CB0(void*, void*);
extern "C" void fn_80040680(clSegment2D*, Vec2f*, Vec2f*, float, float);
extern "C" void fn_800407A0(clSegment2D*, Vec2f*, Vec2f*);
struct Id { unsigned int v; };
class soNullable { public: virtual void isNull(); virtual void fn_27_31270(); virtual bool fn_27_31C88(); unsigned int unk4; Id id; };
struct Bits { unsigned char top:1; unsigned char rest:7; };
struct Result { grCollisionLine* line; void* object; grCollision* collision; unsigned char byte; Bits bits; };
struct PairU32 { unsigned int x,y; };
struct Prefix { unsigned int a,b; };
#define V10(n) virtual void f##n##0(); virtual void f##n##1(); virtual void f##n##2(); virtual void f##n##3(); virtual void f##n##4(); virtual void f##n##5(); virtual void f##n##6(); virtual void f##n##7(); virtual void f##n##8(); virtual void f##n##9();
class PositionSource: public Prefix { public:
 V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
 virtual void f80(); virtual void f81(); virtual void f82(); virtual void f83(); virtual void f84(); virtual void f85();
 virtual PairU32 getPos(int);
};
#undef V10
inline bool isValid(soNullable* self, Result& result, bool& complete) {
 if(self->id.v==0xffff)return false;
 Id id;
 id=self->id;
 if(!fn_80111CB0(&id,&result))return false;
 if(result.line&&result.object&&result.collision)complete=true;
 int value;
 if(complete&&((((unsigned char*)result.object)[0x54]>>4)&1)&&((((unsigned char*)result.collision)[0x2c]>>7)&1))value=1;
 else value=0;
 return value!=0;
}
extern "C" float fn_27_340BC(soNullable* self, PositionSource* source, int index, unsigned int mode) {
 const float* k=lbl_27_rodata_450;
 gfTaskScheduler* scheduler=gfTaskScheduler::getInstance();
 bool running;
 if(scheduler==0)running=false;
 else running=(int)((int)((*(unsigned int*)scheduler<<8)&0xff800000)>>24)>=6;
 if(!running)return k[7];
 if(!self->fn_27_31C88())return k[7];
 Result result;
 bool complete=false;
 result.line=0; result.object=0; result.collision=0; result.byte=0; result.bits.top=0;
 if(!isValid(self,result,complete))return k[7];
 PairU32 b;
 PairU32 a;
 PairU32 point=source->getPos(index);
 b=point;
 a=point;
 clSegment2D segment;
 result.collision->getSegment(&segment,result.line);
 if(mode==1)fn_80040680(&segment,(Vec2f*)&b,(Vec2f*)&a,k[0],k[9]);
 else fn_800407A0(&segment,(Vec2f*)&b,(Vec2f*)&a);
 Vec2f delta;
 delta.m_x=((Vec2f*)&b)->m_x-((Vec2f*)&a)->m_x;
 delta.m_y=((Vec2f*)&b)->m_y-((Vec2f*)&a)->m_y;
 float len2=delta.m_x*delta.m_x+delta.m_y*delta.m_y;
 if((float)(double)nw4r::math::FAbs(len2)<=k[8])return k[0];
 return len2*rsqrtf(len2);
}