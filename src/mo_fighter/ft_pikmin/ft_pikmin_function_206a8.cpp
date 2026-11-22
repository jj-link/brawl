#include <so/so_value_accesser.h>

#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

struct Vec2 {
    float x, y;
};

struct Temp {
    char data[0x14];
};

struct Flag {
    unsigned char value;
};

struct Attr {
    short v;
};

struct W {
    unsigned int a, b;
};

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void unableAll();
    virtual W getSum(Attr*);
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
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
};

struct Modules {
    char p[0x7c];
    Kinetic* kinetic;
};

struct Access {
    char p[0xd8];
    Modules* mods;
};

extern "C" {
extern const float lbl_113_rodata_90, lbl_113_rodata_94;
Temp* fn_113_205EC(Temp*, float, float, float);
void fn_113_20654(void*, Temp*);
void fn_113_4730(Temp*, short);
void fn_113_BC00(Vec2*, const Vec2*);
float fn_113_226DC(Access*);
}

extern "C" void fn_113_206A8(void*, unsigned char* owner, Access* access) {
    access->mods->kinetic->unableAll();

    Attr attr;
    attr.v = 1;
    W s;
    W r = access->mods->kinetic->getSum(&attr);
    s.a = r.a;
    s.b = r.b;

    Flag flag = {0};
    unsigned char* obj = owner + 0x10;
    obj[0x30] = 0;
    ((Object_vptr_0*)(owner + 0x10))->slot13();

    Vec2 vel;
    vel.x = *(float*)&s.a;
    vel.y = lbl_113_rodata_90;
    fn_113_BC00((Vec2*)(obj + 8), &vel);

    fn_113_226DC(access);

    float c1 = soValueAccesser::getConstantFloat((soModuleAccesser*)access, 0xfc7, 0);
    Vec2 p1;
    p1.x = c1;
    p1.y = c1;
    fn_113_BC00((Vec2*)(obj + 0x18), &p1);

    float c2 = soValueAccesser::getConstantFloat((soModuleAccesser*)access, 0xfc8, 0);
    Vec2 p2;
    p2.x = c2;
    p2.y = c2;
    fn_113_BC00((Vec2*)(obj + 0x20), &p2);

    float v3 = soValueAccesser::getConstantFloat((soModuleAccesser*)access, 0xfc9, 0);
    Vec2 p3;
    p3.x = v3;
    p3.y = v3;
    fn_113_BC00((Vec2*)(obj + 0x28), &p3);

    obj[5] |= 0x80;

    Flag flag2 = {0};
    unsigned char* obj2 = owner + 0x50;
    Temp temp;
    fn_113_205EC(&temp, lbl_113_rodata_90, lbl_113_rodata_90, lbl_113_rodata_94);
    fn_113_20654(obj2, &temp);
    fn_113_4730(&temp, 0);
    *(float*)(obj2 + 0x10) = v3;
    *(float*)(obj2 + 8) = *(float*)&s.b;
}
