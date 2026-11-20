#include <types.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma opt_lifetimes off
struct Vec2Work { float m_x, m_y; };
struct Vec2Return { u32 x, y; };
#define V(n) virtual void slot##n();
class State { public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
 virtual int kind(); V(17) V(18) V(19) V(20)
};
class Work { public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11)
 virtual float get(int); virtual void set(float,int); V(14) V(15) V(16)
 virtual u32 test(int); virtual void on(int); virtual void off(int); V(20)
};
class ControlInput { public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
 virtual float x(); V(17) virtual float y(); V(19) virtual float angle();
};
class Posture { public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8)
 virtual float lr();
 V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20)
};
class Motion { public:
 V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
 virtual void rate(float); V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20)
};
class Energy { public:
 V(0) V(1) virtual Vec2Return speed();
 V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20)
 int pad; float x,y;
};
class Kinetic { public:
 V(0) V(1) V(2) V(3) V(4) V(5) virtual void* get(int);
 V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20)
};
#undef V
struct Modules {
 char pad0[8]; Motion* motion; Posture* posture;
 char pad10[0x4c]; ControlInput* input; char pad60[4]; Work* work;
 char pad68[8]; State* state; char pad74[8]; Kinetic* kinetic;
};
extern "C" {
extern const float lbl_27_rodata_2078[];
extern char lbl_27_data_2E5F8[],lbl_27_data_CDF8[];
void* __dynamic_cast(void*,long,const void*,const void*,long);
void fn_8003DC64(Vec2f*,Vec2f*,float);
Vec2Return fn_27_895B8(const Vec2Return&,const Vec2Work*,const Vec2Work*,const Vec2Work*);
Vec2Return fn_27_897E0(const Vec2f&,const Vec2Work*);
}
inline const Vec2f& asVector(const Vec2Return& value) {
 return reinterpret_cast<const Vec2f&>(value);
}
inline float squaredLength(const Vec2Return& bits) {
 const Vec2f& value=asVector(bits);
 return value.m_x*value.m_x+value.m_y*value.m_y;
}
inline float clampValue(float value,float low,float high) {
 float t=nw4r::math::FSelect(value-low,value,low);
 return nw4r::math::FSelect(t-high,high,t);
}
extern "C" void fn_27_1680F4(void*,soModuleAccesser* access) {
 float sq;
 Vec2f result,source;
 Vec2Work first,second,third,fourth;
 Vec2Return delta,newSpeed;
 Vec2f stick;
 const float* c=lbl_27_rodata_2078;
#define modules ((Modules*)access->m_enumerationStart)
 if(modules->state->kind()!=0x85) return;
 float direction=modules->posture->lr();
 float* p=(float*)soValueAccesser::getConstantIndefinite(access,0xA80B,0);
 Energy* e=(Energy*)__dynamic_cast(modules->kinetic->get(3),0,lbl_27_data_2E5F8,lbl_27_data_CDF8,1);
 float velocity;
 float speed=modules->work->get(0x21000004);
 velocity=modules->work->get(0x21000007);
 float a=modules->input->angle();
 float angle;
 if(direction>c[0]) angle=c[3]*a;
 else { float t=c[3]*a; angle=c[5]*(t>c[0]?c[2]:c[4])-t; }
 float sx=modules->input->x();
 stick.m_y=modules->input->y();
 stick.m_x=sx;
 sq = stick.lengthSq();
 float mag;
 if((float)(double)nw4r::math::FAbs(sq)<=c[6]) mag=c[0];
 else mag=sq*rsqrtf(sq);
 if(mag>p[15]) {
  float sign;
  if(angle>=c[0]) sign=angle<c[7]?-p[17]:p[16];
  else sign=angle<c[8]?p[16]:-p[17];
  float delta=sign*((mag-p[15])/(c[2]-p[15]));
  if(velocity*delta<c[0]) velocity=c[0];
  velocity+=delta;
  float out=clampValue(velocity,-p[18],p[18]);
  modules->work->set(out,0x21000007); speed+=out;
 } else if(modules->work->test(0x22000010)==1) {
  if(velocity<c[0]) velocity=c[0];
  velocity+=p[19];
  float out=clampValue(velocity,-p[18],p[18]);
  modules->work->set(out,0x21000007); speed+=out;
 }
 float decay;
 float clamped=clampValue(speed,p[1],p[0]);
 if(!modules->work->test(0x22000010)) {
  decay=modules->work->get(0x21000005)-p[6]*(clamped/c[1]);
  if(modules->work->test(0x22000013)==1) decay-=c[10];
  if(decay<c[0]) decay=c[0];
  if(modules->work->test(0x22000012)) {
   if(clamped>c[0]) modules->work->off(0x22000012);
  } else if(clamped<p[12]) decay+=p[13]*((p[12]-clamped)/(p[12]-p[1]));
  source.m_x=decay*modules->posture->lr(); source.m_y=c[0];
  fn_8003DC64(&source,&result,c[11]*(clamped*modules->posture->lr()));
  float v=modules->work->get(0x21000006);
  v+=p[9];
  float amount=clampValue(v,-p[10],p[10]);
  modules->work->set(amount,0x21000006); result.m_y-=amount;
  sq=result.m_x*result.m_x+result.m_y*result.m_y;
  float length;
  if((float)(double)nw4r::math::FAbs(sq)<=c[6]) length=c[0];
  else length=sq*rsqrtf(sq);
  if(length>p[7]) result=result*(p[7]/length);
  if(length<p[8]||decay<=c[0]) {
   modules->work->on(0x22000010); modules->work->set(c[0],0x21000007);
  }
  e->x=result.m_x; e->y=result.m_y;
  modules->work->set(decay,0x21000005);
 } else {
  first.m_x=soValueAccesser::getConstantFloat(access,0xBD5,0); first.m_y=c[4];
  float tmp=soValueAccesser::getConstantFloat(access,0xBD0,0);
  second.m_x=soValueAccesser::getConstantFloat(access,0xBD8,0); second.m_y=tmp;
  third.m_y=-soValueAccesser::getConstantFloat(access,0xBCF,0); third.m_x=c[0];
  fourth.m_x=soValueAccesser::getConstantFloat(access,0xBD6,0); fourth.m_y=c[0];
  delta=fn_27_895B8(e->speed(),&third,&first,&fourth);
  newSpeed=fn_27_897E0(asVector(e->speed())+asVector(delta),&second);
  e->x=asVector(newSpeed).m_x; e->y=asVector(newSpeed).m_y;
  if(clamped<p[11]) {
   sq=squaredLength(e->speed());
   float length;
   if((float)(double)nw4r::math::FAbs(sq)<=c[6]) length=c[0]; else length=sq*rsqrtf(sq);
   if(length>p[8]) {
    modules->work->set(length,0x21000005); modules->work->off(0x22000010);
   }
  }
 }
 modules->motion->rate(c[1]-clamped); modules->work->set(clamped,0x21000004);
#undef modules
}