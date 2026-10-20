#pragma force_active on
typedef unsigned int u32;
struct Vec3f { float x,y,z; };
struct Attack {
 int damage; Vec3f pos; float size; int angle, growth, fixed, base;
 char pad[12];
 struct { u32 top:9; u32 mask:10; u32 type:3; u32 flag:1; u32 sound:4; u32 low:5; } a;
 struct B { u32 top:10; u32 flag:1; u32 type:2; u32 rest:19; } b;
 struct C { u32 top:16; u32 flag:1; u32 mid:10; u32 rest:5; } c;
 u32 d;
};
struct Work { char pad[40]; int value; };
struct grMadein {
 char pad[0x15c]; Work* work;
 void setAttack(float,Vec3f*);
 Attack* getOverwriteAttackData();
};
struct Stage { char pad[0x210]; grMadein* ground; };
extern "C" const float lbl_53_rodata_50;
extern "C" void fn_53_3CA0(Stage* self,Vec3f* pos) {
 self->ground->setAttack(lbl_53_rodata_50,pos);
 Attack* a=self->ground->getOverwriteAttackData();
 a->a.top=0;
 a->damage=30;
 a->angle=362;
 a->growth=50;
 a->fixed=0;
 a->base=80;
 a->size=lbl_53_rodata_50;
 a->pos=*pos;
 Attack::B b=a->b;
 Attack::C c=a->c;
 a->a.low=0;
 a->a.type=7;
 a->a.mask=1023;
 a->a.flag=0;
 a->a.sound=15;
 b.top=0;
 b.flag=1;
 b.type=0;
 a->b=b;
 c.flag=0;
 c.top=60;
 c.mid=0;
 a->c=c;
 a->d |= 0x80000000;
 self->ground->work->value=4;
}