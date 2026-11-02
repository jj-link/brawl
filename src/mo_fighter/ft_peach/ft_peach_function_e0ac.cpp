#include <types.h>
#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct WorkModule {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int isFlag(u32);
    virtual void onFlag(u32);
};

struct Modules {
    char pad[0x64];
    WorkModule* work;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

struct Owner {
    char pad[0x7c];
    float a;
    float b;
    char pad2[0x108 - 0x84];
    Vec2 v0;
    Vec2 v1;
    Vec2 v2;
    Vec2 v3;
};

extern "C" {
extern const float lbl_103_rodata_14;
extern const float lbl_103_rodata_18;

float fn_27_192278(void*, unsigned long);
Vec3* fn_103_9594(Vec3*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2*, Vec3*);
Vec2* fn_103_C174(Vec2*, const Vec2*);

void fn_103_E0AC(void*, Owner* owner, const float* source, soModuleAccesser* accesser) {
    struct Locals {
        bool flag2;
        bool flag1;
        Vec2 e, f, g, h, i, j, k;
        Vec3 l, m, n;
    } locals;

    locals.k.x = *source;
    locals.k.y = lbl_103_rodata_14;
    fn_27_89D08(3, accesser, 6, &locals.k,
        fn_103_9594(&locals.n, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
    locals.flag1 = false;

    locals.j.x = lbl_103_rodata_14;
    locals.j.y = lbl_103_rodata_14;
    fn_103_C174(&owner->v0, &locals.j);

    locals.i.x = lbl_103_rodata_14;
    locals.i.y = lbl_103_rodata_14;
    fn_103_C174(&owner->v1, &locals.i);

    locals.h.x = fn_27_192278(accesser, 0xfa1);
    locals.h.y = lbl_103_rodata_18;
    fn_103_C174(&owner->v2, &locals.h);

    locals.g.x = lbl_103_rodata_18;
    locals.g.y = lbl_103_rodata_18;
    fn_103_C174(&owner->v3, &locals.g);

    if (accesser->modules->work->isFlag(0x1200003d) == 0) {
        float y = fn_27_192278(accesser, 0xfa2);
        locals.f.x = lbl_103_rodata_14;
        locals.f.y = y;
        fn_27_89D08(1, accesser, 0, &locals.f,
            fn_103_9594(&locals.m, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
        accesser->modules->work->onFlag(0x1200003d);
    } else {
        locals.e.x = lbl_103_rodata_14;
        locals.e.y = lbl_103_rodata_14;
        fn_27_89D08(1, accesser, 0, &locals.e,
            fn_103_9594(&locals.l, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
    }
    locals.flag2 = false;

    owner->a = -fn_27_192278(accesser, 0xfa3);
    owner->b = fn_27_192278(accesser, 0xfa4);
}
}
