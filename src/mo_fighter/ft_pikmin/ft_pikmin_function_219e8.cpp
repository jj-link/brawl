#pragma force_active on
#include <mt/mt_common.h>

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

union U {
    unsigned long long r;
    Vec2 v;
};

struct Acc;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(Acc*);
    virtual unsigned long long slot2();
    virtual void slot3();
    virtual Vec3 slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);

    int pad;
    Vec2 value;
};

class Work_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
};

struct Mods {
    char pad[0xc];
    Object_vptr_0* pos;
    char pad2[0x54];
    Work_vptr_0* work;
};

struct Acc {
    char pad[0xd8];
    Mods* mods;
};

extern "C" {
extern const float lbl_113_rodata_90;
extern const double lbl_113_rodata_B0;
Vec2* fn_113_C30C(Vec2*, float, float);
unsigned long long fn_113_BFB0(const Vec2*, const Vec2*);
float fn_113_182E4(Vec2*);
void fn_113_BC00(Vec2*, const Vec2*);
void fn_8003DBA8(Vec2*);
void fn_113_1E5B8(Vec2*, float);
}

extern "C" void fn_113_219E8(void*, Object_vptr_0* obj, Acc* acc) {
    Object_vptr_0* pm = acc->mods->pos;
    Vec2 pos;
    fn_113_C30C(&pos, pm->slot4().x, pm->slot4().y);
    Work_vptr_0* w = acc->mods->work;
    float ty = w->slot12(0x11000005);
    U diff;
    U r;
    Vec2 tgt;
    r.r = fn_113_BFB0(fn_113_C30C(&tgt, w->slot12(0x11000004), ty), &pos);
    diff = r;
    float len = fn_113_182E4(&diff.v);
    if (lbl_113_rodata_90 == len) {
        Vec2 z;
        z.x = lbl_113_rodata_90;
        z.y = lbl_113_rodata_90;
        fn_113_BC00(&obj->value, &z);
        return;
    }
    int n = acc->mods->work->slot4(0x1000000A);
    if (n <= 0) {
        n = 1;
    }
    if (n > 1) {
        fn_8003DBA8(&diff.v);
        fn_113_1E5B8(&diff.v, len / (float)n);
    }
    fn_113_BC00(&obj->value, &diff.v);
}
