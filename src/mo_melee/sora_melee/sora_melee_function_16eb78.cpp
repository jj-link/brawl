#include <types.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(int, int, Vec3f*, Vec3f*, Vec3f*, Vec3f*, int, int, float);
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
    virtual void slot55(int, int, int, int);
};

class Object_vptr_8 {
    int pad[2];
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual int s33(int);
};

struct Modules {
    char pad00[4];
    Object_vptr_8* m4;
    char pad08[0x54];
    Object_vptr_0* m5c;
    char pad60[0x28];
    Object_vptr_0* m88;
};

struct Obj {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_16EB78(void*, Obj* obj) {
    int r = obj->modules->m4->s33(300);
    Vec3f a, b, c, d;
    d.x = 0.0f;
    d.y = 0.0f;
    d.z = 0.0f;
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = 0.0f;
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = 0.0f;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    obj->modules->m88->slot8(4, r, &a, &b, &c, &d, 0, 0, 1.0f);
    obj->modules->m5c->slot55(0x19, 0, 0, -1);
}
