#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
class Object_vptr_0 { public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(int,float); virtual void slot14(); virtual void slot15(); virtual float slot16();
};
struct Modules { char pad[0x5c]; Object_vptr_0* a; char pad2[4]; Object_vptr_0* b; };
struct Access { char pad[0xd8]; Modules* modules; };
extern const float lbl_27_rodata_1FF0[];
extern "C" void fn_27_165458(soModuleAccesser* self,int id,float x,float rate,float a,float b,float c,float d) {
 const float* k=lbl_27_rodata_1FF0;
 Access* p=(Access*)self;
 float dir=p->modules->a->slot16();
 float t=b/rate;
 float v=d*(dir*(a/rate));
 float add;
 if(dir>k[7]) add=t*d; else add=-t*d;
 float target=dir*d;
 v+=add;
 bool zero;
 if(target<k[8] && target>k[9]) zero=true; else zero=false;
 if(!zero) {
  float ratio=x/target;
  if(ratio>k[7] && ratio<k[6]) { float factor=k[6]-ratio; factor*=c; v*=factor; }
 } else v=k[7];
 float limit=soValueAccesser::getConstantFloat(self,0xbbc,0)/rate;
 if(k[7]==target) {
  float ax=(float)(double)nw4r::math::FAbs(x); float al=(float)(double)nw4r::math::FAbs(limit);
  if(al>ax) v=-x; else { if(x>k[7]) limit=-limit; v=limit; }
 } else if(v>k[7]) {
  if(x+v>target) { v=-limit; if(x+v<target) v=target-x; }
 } else if(x+v<target) { v=limit; if(x+limit>target) v=target-x; }
 p->modules->b->slot13(id,x+v);
}