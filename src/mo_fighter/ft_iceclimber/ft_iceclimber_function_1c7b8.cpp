#include <mt/mt_vector.h>
#include <so/so_value_accesser.h>
#pragma force_active on
struct Range { float minimum, maximum; };
struct Config { const void* vtable; unsigned char state; unsigned char enabled : 1; unsigned char flags : 7; unsigned char state2; unsigned char pad; Range ranges[5]; bool firstFlag, secondFlag, initialized; };
struct Flag { unsigned char value; };
class Work { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual float getF(unsigned long);
};
class Posture { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual Vec3f getPos();
};
class Kinetic { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void update();
};
struct Modules { char pad0[0x0C]; Posture* posture; char pad1[0x54]; Work* work; char pad2[0x14]; Kinetic* kinetic; };
struct Accesser { char pad[0xD8]; Modules* mods; };
extern "C" {
extern const double lbl_105_rodata_108;
extern const float lbl_105_rodata_100;
extern const float lbl_105_rodata_104;
void fn_105_1C698(Config*, const Range*, const Range*, const Range*, const Range*, const Range*, bool, bool);
void fn_105_1C734(void*, void*);
void fn_105_1C720(void*, const Vec2f*);
void* fn_105_3710(void*, short);
}
extern "C" void fn_105_1C7B8(void*, char* owner, Accesser* accesser) {
accesser->mods->kinetic->update();
float first = accesser->mods->work->getF(0x11000004UL);
float scale = soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xFA2UL, 0);
float second = scale * accesser->mods->work->getF(0x11000002UL);
Config config;
Range e,d,c,b,a;
float posY = accesser->mods->posture->getPos().m_y;
float height = first - second - posY;
float divisor = (float)soValueAccesser::getConstantInt((soModuleAccesser*)accesser, 0x5DC1UL, 0);
Flag flag = {0};
char* object = owner + 0x10;
a.minimum = lbl_105_rodata_100; a.maximum = lbl_105_rodata_100;
b.minimum = lbl_105_rodata_104; b.maximum = lbl_105_rodata_104;
c.minimum = lbl_105_rodata_100; c.maximum = lbl_105_rodata_100;
d.minimum = lbl_105_rodata_104; d.maximum = lbl_105_rodata_104;
e.minimum = lbl_105_rodata_104; e.maximum = lbl_105_rodata_104;
fn_105_1C698(&config, &e, &d, &c, &b, &a, 0, 0);
fn_105_1C734(object, &config);
fn_105_3710(&config, 0);
Vec2f velocity;
velocity.m_x = lbl_105_rodata_104;
velocity.m_y = height / divisor;
fn_105_1C720(object, &velocity);
object[5] |= 0x80;
}