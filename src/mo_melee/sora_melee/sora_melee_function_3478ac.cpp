#pragma force_active on
#pragma scheduling on
#include <types.h>
#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
extern "C" const float lbl_27_rodata_78A8;
struct Access;
union VectorResult { unsigned long long bits; struct { float x,y; } vector; };
struct Vector { float x,y; Vector() {} Vector(float v):x(v),y(lbl_27_rodata_78A8) {} };
class Object_vptr_0 { public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual float slot12(u32); };
struct GroundBase { char pad[8]; };
class Ground: public GroundBase { public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
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
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual u32 test(u32,u32); virtual void slot56(); virtual unsigned long long result(u32,u32); };
struct Modules { char pad0[0x10]; Ground* ground; char pad14[0x50]; Object_vptr_0* work; };
struct Access { char pad[0xD8]; Modules* modules; };
class Self { public: virtual void slot0(); virtual void slot1(Access*); virtual unsigned long long getVector();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
unsigned char unk4; unsigned char f5a:1; unsigned char f5b:7; unsigned char unk6,unk7;
float x,y; char pad10[0x2C]; float value3C;
void setVector(const Vector& v) { y=v.y; x=v.x; }
};
inline float constantFloat(Access* a,u32 id) { return soValueAccesser::getConstantFloat(reinterpret_cast<soModuleAccesser*>(a),id,0); }
inline float valueFloat(Access* a,u32 id) { return soValueAccesser::getValueFloat(reinterpret_cast<soModuleAccesser*>(a),id,0); }
extern "C" void fn_27_3478AC(Self* self, Access* access) {
float sign; float magnitude; float base;
base=lbl_27_rodata_78A8;
float threshold=constantFloat(access,0xFAE);
if(valueFloat(access,0x3F5)>=threshold) base=access->modules->work->slot12(0x21000004);
self->value3C=base;
if(access->modules->ground->test(8,0)==1) {
VectorResult value; value.bits=access->modules->ground->result(8,0);
float scaled=value.vector.x*constantFloat(access,0xFA8);
VectorResult current; current.bits=self->getVector();
scaled+=current.vector.x; Vector result(scaled); self->x=result.x; self->y=result.y;
}
if((u32)(!!self->f5a)==1 && self->unk6==0) self->slot1(access);
int flag=true;
{
bool contact=false; VectorResult speed; speed.bits=self->getVector();
if(speed.vector.x>=lbl_27_rodata_78A8) { if(access->modules->ground->test(4,0)!=0) contact=true; }
if(!contact) { bool contact2=false; VectorResult speed2; speed2.bits=self->getVector();
if(speed2.vector.x<=lbl_27_rodata_78A8) { if(access->modules->ground->test(2,0)!=0) contact2=true; }
if(!contact2) flag=false;
}
}
if(flag) {
VectorResult speed; speed.bits=self->getVector();
magnitude=(float)(double)nw4r::math::FAbs(speed.vector.x);
if(magnitude<constantFloat(access,0xFBA)) {
Vector result; VectorResult current; current.bits=self->getVector();
int s=(current.vector.x<lbl_27_rodata_78A8)?-1:1;
sign=(float)s; float scale=constantFloat(access,0xFBA);
result.x=scale*-sign; result.y=lbl_27_rodata_78A8; self->setVector(result);
} else {
Vector result; VectorResult current; current.bits=self->getVector();
float scale=-constantFloat(access,0xFB9);
result.x=current.vector.x*scale; result.y=lbl_27_rodata_78A8;
self->x=result.x; self->y=result.y;
}
}
}
