#pragma scheduling on
#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;
extern "C" float lbl_27_rodata_78DC;
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3(int,void*);
virtual int slot4(int);
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10(int,int);
virtual void slot11();
virtual void slot12();
virtual _VEC2 slot13(short*);
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18(int,void*);
};
class Posture {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual VEC3 slot4();
};
struct Data {
char pad[0xc]; Posture* c;
char pad1[0x54]; Object_vptr_0* obj64;
char pad2[8]; Object_vptr_0* obj70;
char pad3[8]; Object_vptr_0* obj7C;
};
struct Mod { char pad[0xd8]; Data* data; };
struct Fighter { char pad[0x60]; Mod* mod; };
struct Input { char pad[4]; float y,z; char pad2[0x74]; VEC3 pos; };
inline void subtractPosition(const VEC3* pos,const VEC3* target,VEC3* out) { VEC3Sub(out,target,pos); }
inline float directionSign(float v) { return v < lbl_27_rodata_78DC ? -1 : 1; }
extern "C" void fn_27_34BF64(Fighter* self,Input in) {
int value=(int)in.y;
self->mod->data->obj64->slot10(value,0x10000006);
if(self->mod->data->obj64->slot4(0x10000006)<0) {
self->mod->data->obj70->slot3(2,self->mod);
return;
}
if(in.z>lbl_27_rodata_78DC) {
VEC3 diff;
VEC3 pos=self->mod->data->c->slot4();
short flag=-1;
subtractPosition(&pos,&in.pos,&diff);
VEC2 delta;
delta.x=diff.x; delta.y=diff.y;
_VEC2 vec=self->mod->data->obj7C->slot13(&flag);
float a=vec.x<lbl_27_rodata_78DC ? -1 : 1;
float b=directionSign(delta.x);
bool match=b==a;
if(match) self->mod->data->obj64->slot18(0x12000004,self->mod);
}
}
