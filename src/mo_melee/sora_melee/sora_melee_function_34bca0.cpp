#include <so/so_value_accesser.h>
#pragma force_active on
#pragma fp_contract off
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual int slot4(unsigned);
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8(unsigned);
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual float slot12(unsigned);
virtual void slot13(unsigned, float);
virtual unsigned slot14(int,int);
virtual void slot15();
virtual int slot16();
virtual void slot17(int,int,int);
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual float slot21();
virtual void slot22();
virtual void slot23(float);
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29(int,int,int);
virtual void slot30();
virtual void slot31(int,int,int);
virtual void slot32();
virtual void slot33(int,int,int);
};
struct Modules {
char pad0[0xc]; Object_vptr_0* posture;
char pad10[0xc]; Object_vptr_0* motion;
char pad20[0x44]; Object_vptr_0* work;
char pad68[8]; Object_vptr_0* status;
};
struct Access { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x60]; Access* access; };
extern "C" void fn_27_1D9FF8(void*);
extern "C" void fn_27_34BCA0(Self* self) {
int max;
Object_vptr_0* work;
Object_vptr_0* work2;
Access* access2;
Object_vptr_0* posture;
fn_27_1D9FF8(self);
if (self->access->modules->status->slot16() == 1) {
if (self->access->modules->work->slot4(0x10000005) >= 0)
self->access->modules->work->slot8(0x10000005);
work = self->access->modules->work;
max = soValueAccesser::getConstantInt((soModuleAccesser*)self->access,0x5dc4,0);
if (work->slot4(0x10000005) < max) {
posture = self->access->modules->posture;
float scale = soValueAccesser::getConstantFloat((soModuleAccesser*)self->access,0xfa5,0);
float v = posture->slot21();
posture->slot23(v * scale);
if (self->access->modules->motion->slot14(0,0) == 1) {
float value = self->access->modules->work->slot12(0x11000001);
value *= soValueAccesser::getConstantFloat((soModuleAccesser*)self->access,0xfa6,0);
self->access->modules->work->slot13(0x11000001,value);
self->access->modules->motion->slot17(0,(int)value,0);
access2 = self->access;
work2 = access2->modules->work;
max = soValueAccesser::getConstantInt((soModuleAccesser*)access2,0x5dc4,0);
max -= soValueAccesser::getConstantInt((soModuleAccesser*)access2,0x5dc3,0);
if (work2->slot4(0x10000005) < max) {
self->access->modules->motion->slot29(0,0,0);
self->access->modules->motion->slot31(0,0,0);
self->access->modules->motion->slot33(0,0,0);
}
}
}
}
}
