#pragma force_active on
#include <mt/mt_common.h>
#include <so/so_value_accesser.h>

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
    virtual void fn_113_80F4();
    virtual void slot1(Acc*);
    virtual unsigned long long slot2();
    virtual void slot3();
    virtual Vec3 slot4();
    virtual void slot5();
    virtual unsigned int slot6(unsigned int);
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned int slot17(unsigned int);

    int pad;
    Vec2 value;
    Vec2 other;
};

class Work {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned int slot17(unsigned int);
};

struct Mods {
    char pad[0xc];
    Object_vptr_0* pos;
    char pad2[0x54];
    Work* work;
};

struct Acc {
    char pad[0xd8];
    Mods* mods;
};

extern "C" {
extern const float lbl_113_rodata_90;
Vec2* fn_113_C30C(Vec2*, float, float);
unsigned long long fn_113_BFB0(const Vec2*, const Vec2*);
float fn_113_BF74(const Vec2*);
void fn_113_BC00(Vec2*, const Vec2*);
float fn_113_226DC(Acc*);
void fn_8003DBA8(Vec2*);
void fn_113_1E5B8(Vec2*, float);
}

extern "C" void fn_113_20ED0(void*, Object_vptr_0* obj, Acc* acc) {
    Vec2 pos;
    U diff;
    U nl;
    Object_vptr_0* pm = acc->mods->pos;
    fn_113_C30C(&pos, pm->slot4().x, pm->slot4().y);

    Work* w = acc->mods->work;
    float ty = w->slot12(0x11000005);
    U r;
    Vec2 tgt;
    r.r = fn_113_BFB0(&pos, fn_113_C30C(&tgt, w->slot12(0x11000004), ty));
    diff = r;
    float len = fn_113_BF74(&diff.v);

    if (lbl_113_rodata_90 == len) {
        Vec2 z;
        z.x = lbl_113_rodata_90;
        z.y = lbl_113_rodata_90;
        fn_113_BC00(&obj->value, &z);
    } else {
        unsigned int flags = acc->mods->work->slot4(0x10000011);
        float speed = fn_113_226DC(acc);
        if ((flags & 2) || acc->mods->work->slot17(0x22000000) == 1) {
            speed += soValueAccesser::getConstantFloat(
                reinterpret_cast<soModuleAccesser*>(acc), 0xfcf, 0);
        }
        if (acc->mods->pos->slot9() > lbl_113_rodata_90) {
            speed = -speed;
        }

        Vec2 velocity;
        velocity.x = speed;
        velocity.y = lbl_113_rodata_90;
        fn_113_BC00(&obj->other, &velocity);
        obj->slot1(acc);

        U sv;
        sv.r = obj->slot2();
        if (fn_113_BF74(&sv.v) > len) {
            U s;
            s.r = obj->slot2();
            nl = s;
            fn_8003DBA8(&nl.v);
            fn_113_1E5B8(&nl.v, mtSqrtf(len));
            fn_113_BC00(&obj->value, &nl.v);
        }
    }
}
