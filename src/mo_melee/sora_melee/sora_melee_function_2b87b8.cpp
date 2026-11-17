#include <types.h>
#include <it/item.h>
#include <mt/mt_vector.h>
#pragma force_active on
#pragma opt_propagation off
extern "C" const float lbl_27_rodata_5EB8[];
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
};
union Pair { struct {float x,y;}; unsigned int bits[2]; };
struct Flags {u8 active:1;u8 other:7;};
class Module40 {public:
virtual void s0();virtual void s1();virtual void s2();virtual void s3();
virtual void s4();virtual void s5();virtual void s6();virtual void s7();
};
class Module {public:
virtual void s0(); virtual void s1(); virtual Pair s2();virtual void s3();virtual void s4();
virtual void s5(int,Vec2f*,Vec3f*,void*);
};
struct Class_1E0A8_base {char pad[0xf8];};
class Class_1E0A8:public Class_1E0A8_base {public:
virtual void fn_27_E6C88();virtual void fn_27_E640C();virtual Pair fn_27_E641C();
virtual void fn_27_CCA6C();virtual void fn_27_CCA8C();virtual void fn_27_CC984(int,Vec2f*,Vec3f*,void*);
};
static inline void setVector(Vec2f* dst, const Vec2f& src) {
dst->m_x=src.m_x; dst->m_y=src.m_y;
}
extern "C" void fn_27_2B87B8(char* self,char* other) {
const float* k=lbl_27_rodata_5EB8;
BaseItem* item=*(BaseItem**)(other+8);
char* acc=*(char**)(other+0xd8);
(*(Object_vptr_0**)(acc+0x14))->slot3();
Vec3f p(k[1],k[1],k[1]);
Vec3f unused1; unused1.m_x=k[1];
Vec3f v1;
Vec3f v2;
Vec3f unused3;
Vec3f unused2;
unused2.m_y=k[1];
unused3.m_z=k[1];
Pair destination;
((Module40*)(self+0x40))->s7();
((Flags*)(self+0x45))->active=0;
Pair a=((Module*)(self+0xf8))->s2();
p.m_x=p.m_x+a.x;
v1.m_x=k[1]; v1.m_y=k[1]; v1.m_z=k[1];
Vec2f initial(k[1],k[1]);
((Module*)(self+0xf8))->s5(-1,&initial,&v1,other);
float zero;
float limitY;
float limitX;
float speedX;
limitX=k[36];
limitY=k[2];
speedX=p.m_x;
zero=k[1];
Vec2f limit;
limit.m_x=limitX; limit.m_y=limitY;
setVector((Vec2f*)(self+0x120),limit);
Vec2f speed;
speed.m_x=speedX; speed.m_y=zero;
setVector((Vec2f*)(self+0x100),speed);
*(u8*)(self+0xfd)|=0x80;
destination=((Module*)(self+0xd8))->s2();
destination.y=destination.y+p.m_y;
v2.m_x=k[1]; v2.m_y=k[1]; v2.m_z=k[1];
((Module*)(self+0xd8))->s5(-1,(Vec2f*)&destination,&v2,other);
*(float*)(self+0xe4)=-item->getParam((itValueAccesser::ParamFloat)0xd50);
*(float*)(self+0xf0)=item->getParam((itValueAccesser::ParamFloat)0xd51);
*(int*)(self+0xf4)=11;
*(u8*)(self+0xdd)|=0x80;
*(u8*)(self+0x255)|=0x80;
}