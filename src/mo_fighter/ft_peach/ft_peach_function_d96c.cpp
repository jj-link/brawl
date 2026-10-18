#pragma scheduling off
#pragma optimize_for_size on

#include <types.h>
#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float facing();
};

struct Modules {
    char pad[12];
    Posture* posture;
};

struct soModuleAccesser {
    char pad[0xd8];
    Modules* modules;
};

struct State {
    char pad[0xb0];
    Vec2 first, second;
};

extern "C" {
extern const float lbl_103_rodata_14;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
Vec3* fn_103_9594(Vec3*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2*, Vec3*);
Vec2* fn_103_C174(Vec2*, const Vec2*);

void fn_103_D96C(void*, State* state, void*, soModuleAccesser* accesser) {
    struct Locals {
        bool flag;
        Vec2 zero, second, first, speed;
        Vec3 rotation2, rotation;
    } locals;

    float x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfa5, 0);
    if (accesser->modules->posture->facing() >= lbl_103_rodata_14)
        x = -x;

    locals.speed.x = x;
    locals.speed.y = lbl_103_rodata_14;
    fn_27_89D08(2, accesser, 0, &locals.speed,
        fn_103_9594(&locals.rotation, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));

    locals.flag = false;

    float y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfa6, 0);
    if (accesser->modules->posture->facing() >= lbl_103_rodata_14)
        y = -y;

    locals.first.x = y;
    locals.first.y = lbl_103_rodata_14;
    fn_103_C174(&state->first, &locals.first);

    locals.second.x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xfa7, 0);
    locals.second.y = lbl_103_rodata_14;
    fn_103_C174(&state->second, &locals.second);

    locals.zero.x = lbl_103_rodata_14;
    locals.zero.y = lbl_103_rodata_14;
    fn_27_89D08(0, accesser, 6, &locals.zero,
        fn_103_9594(&locals.rotation2, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));
}
}
