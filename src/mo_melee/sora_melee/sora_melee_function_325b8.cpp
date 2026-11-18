#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <mt/mt_coll2d.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off
#pragma inline all
extern "C" {
Vec2f fn_27_312B0(void*, const Vec2f*, float);
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
virtual Vec2f fn_27_325B8();
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
}
using namespace matching;
inline Vec2f calcCenter(soNullable* self, Vec2f pos, float t) {
Vec2f off;
Vec2f::copy(off,fn_27_312B0(self,&pos,t));
Vec2f r;
Vec2f::copy(r,self->position+off);
return r;
}
extern "C" Vec2f fn_27_325B8(soNullable* self,Ground* ground,int index,float t) {
Vec2f center;
Vec2f movement;
gfTaskScheduler* scheduler=gfTaskScheduler::getInstance();
bool mode;
if(scheduler == 0) mode=false;
else mode=(s32)((*(u32*)scheduler<<8)&0xff800000)>>24>=6;
if(!mode) {
Vec2f zero(lbl_27_rodata_450[0],lbl_27_rodata_450[0]);
return zero;
}
if(!self->fn_27_31C88()) {
Vec2f zero(lbl_27_rodata_450[0],lbl_27_rodata_450[0]);
return zero;
}
Vec2f::copy(center,calcCenter(self,ground->getPosB(index),t));
if(self->flag) return center;
Vec2f::copy(movement,ground->getPosA(index)-ground->getPosB(index));
return center+movement;
}
