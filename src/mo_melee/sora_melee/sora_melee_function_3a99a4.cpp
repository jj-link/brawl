#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_common.h>
#include <math.h>
#pragma force_active on
#pragma fp_contract off
struct Vec2 { float x,y; };
struct Vec3 { float x,y,z; Vec3() {} };
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual unsigned long long slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void* slot6(int);
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
};
struct Posture {
virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
virtual Vec3 position();
virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8();
virtual float direction();
virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
virtual void setRotation(Vec3*,int);
virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21();
virtual float scale();
};
struct ModelBase { char pad[8]; };
struct Model : ModelBase {
virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21();
virtual void setTransform(int,Vec3*,Vec3*,const Vec3*);
};
struct Modules { char pad[4]; Model* model; char gap[4]; Posture* posture; char gap2[0x6c]; Object_vptr_0* kinetic; };
struct Obj { char pad[0xd8]; Modules* modules; };
struct Wrap { char pad[0x60]; Obj* obj; };
struct Consts { float a0,zero,one,aC,epsilon,threshold,degrees,positive,negative; };
extern "C" {
extern const Consts lbl_27_rodata_7EF0;
extern char lbl_27_data_457C0[],lbl_27_data_CDF8[];
void* __dynamic_cast(void*,long,const void*,const void*,short);
}
inline Vec2 unpack(unsigned long long bits) { return *(Vec2*)&bits; }
extern "C" void fn_27_3A99A4(Wrap* arg0) {
const Consts* c=&lbl_27_rodata_7EF0;
Obj* obj=arg0->obj;
float size=obj->modules->posture->scale();
Vec3 position=obj->modules->posture->position();
Vec3 rotation,scale;
void* p=obj->modules->kinetic->slot6(0);
Object_vptr_0* energy=(Object_vptr_0*)__dynamic_cast(p,0,lbl_27_data_457C0,lbl_27_data_CDF8,1);
float direction=obj->modules->posture->direction();
Vec2 velocity=unpack(energy->slot2());
float sum=velocity.x*velocity.x+velocity.y*velocity.y;
float magnitude;
if ((float)(double)nw4r::math::FAbs(sum)<=c->epsilon) magnitude=c->zero;
else magnitude=sum*rsqrtf(sum);
float angle;
if(magnitude>c->threshold) angle=-(float)atan2(velocity.y,velocity.x*direction);
else angle=c->zero;
rotation.x=c->degrees*angle;
rotation.y=c->one==direction?c->positive:c->negative;
rotation.z=c->zero;
scale.x=size; scale.y=size; scale.z=size;
obj->modules->model->setTransform(0,&scale,&rotation,&position);
obj->modules->posture->setRotation(&rotation,0);
}
