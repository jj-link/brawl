#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_74D8;
struct KineticWords { u32 x,y; };
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual KineticWords slot13(s16*); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual class Class_90D8* slot23();
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base { public:
virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28(); virtual void fn_27_7AB50(); virtual float fn_27_7B2EC(void*,u32,u32);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; char pad2[0x14]; Object_vptr_0* kinetic; };
struct Access { char pad[0xD8]; Modules* modules; };
struct Target { char pad0[0x15]; u8 flag15; char pad16[2]; float f18,f1c,f20,f24,f28,f2c,f30,f34,f38,f3c; char pad40[0x15]; u8 flag55; char pad56[2]; float f58,f5c,f60; };
struct V2 { float x,y; };
#pragma optimization_level 4
extern "C" void fn_27_31A3D0(void*, Target* target, Access* access) {
Object_vptr_0* kinetic = access->modules->kinetic;
s16 value = -1;
Vec2f result;
KineticWords raw = kinetic->slot13(&value);
__memcpy(&result, &raw, sizeof(result));
kinetic->slot12();
Class_90D8* values = access->modules->work->slot23();
float a = values->fn_27_7B2EC(access,0xFA5,0);
float b = values->fn_27_7B2EC(access,0xFA4,0);
float c = values->fn_27_7B2EC(access,0xFA6,0);
float d = values->fn_27_7B2EC(access,0xFA7,0);
float zero = lbl_27_rodata_74D8;
float x = result.m_x;
float y = result.m_y;
V2 v4, v3, v2, v1, v0;
v4.x=x; v4.y=zero; v3.x=zero; v3.y=zero; v2.x=a; v2.y=zero; v1.x=b; v1.y=zero; v0.x=b; v0.y=zero;
target->f18=v4.x; target->f1c=v4.y; target->f20=v3.x; target->f24=v3.y;
target->f30=v2.x; target->f34=v2.y; target->f38=v1.x; target->f3c=v1.y; target->f28=v0.x; target->f2c=v0.y; target->flag15 |= 0x80;
target->f58=y; target->f5c=-c; target->f60=d; target->flag55 |= 0x80;
}
