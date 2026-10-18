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

extern "C" {
extern const float lbl_103_rodata_14;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
Vec3* fn_103_9594(Vec3*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2*, Vec3*);

void fn_103_DE7C(void*, void*, void*, soModuleAccesser* accesser) {
    float x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfb0, 0);
    if (accesser->modules->posture->facing() < lbl_103_rodata_14)
        x = -x;

    Vec2 first;
    first.x = x;
    first.y = lbl_103_rodata_14;
    Vec3 rotation;
    fn_27_89D08(
        2, accesser, 0, &first,
        fn_103_9594(&rotation, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));

    float y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xfb1, 0);
    Vec2 second;
    second.x = lbl_103_rodata_14;
    second.y = y;
    Vec3 rotation2;
    fn_27_89D08(
        1, accesser, 0, &second,
        fn_103_9594(&rotation2, lbl_103_rodata_14,
                    lbl_103_rodata_14, lbl_103_rodata_14));
}
}
