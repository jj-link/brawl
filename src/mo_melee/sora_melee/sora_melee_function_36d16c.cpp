#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const f32 lbl_27_rodata_7B40[];
typedef Vec3f Vec3;
struct Pair { s32 a,b; };
union PairValue { long long value; Pair pair; };
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual Vec3 slot4();
virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
virtual f32 slot9();
virtual void slot10(); virtual void slot11(); virtual void slot12();
virtual long long slot13(void*);
virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
virtual f32 slot22(void*);
};
struct Pad { char data[8]; };
class Model : public Pad {
public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21();
virtual void v22(int,Vec3*,Vec3*,const Vec3*);
};
#define SELF_D8(s) (*(char**)(*(char**)((s)+0x60)+0xd8))
extern "C" void fn_27_36D16C(char* self) {
const f32* k=lbl_27_rodata_7B40;
Vec3 va;
PairValue q;
PairValue p;
s16 sp8;
f32 t=((Object_vptr_0*)*(char**)(SELF_D8(self)+0xc))->slot22(*(char**)(self+0x60));
va.m_z=t; va.m_y=t; va.m_x=t;
Vec3 vc=((Object_vptr_0*)*(char**)(SELF_D8(self)+0xc))->slot4();
Vec3 vb;
sp8=1;
p.value=((Object_vptr_0*)*(char**)(SELF_D8(self)+0x7c))->slot13(&sp8);
q=p;
f32 f1v=((Object_vptr_0*)*(char**)(SELF_D8(self)+0xc))->slot9();
f32 x=*(f32*)&q.pair.b;
f32 y=*(f32*)&q.pair.a*f1v;
f32 ang=(f32)atan2(x,y);
vb.m_x=k[4]*-ang;
f32 var;
if(k[2]==f1v) var=k[5]; else var=k[6];
vb.m_y=var; vb.m_z=k[1];
((Model*)*(char**)(SELF_D8(self)+0x4))->v22(0,&va,&vb,&vc);
}
