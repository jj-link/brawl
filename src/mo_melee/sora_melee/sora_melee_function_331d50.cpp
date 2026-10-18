#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
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

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern const float lbl_27_rodata_76AC;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);
Vec3* fn_27_331BEC(Vec3*, float, float, float);
void fn_27_89D08(int, Accesser*, int, Vec2*, Vec3*);
void fn_27_331AF0(void*, const Vec2*);

void fn_27_331D50(void*, char* object, void*, Accesser* a) {
    struct Locals {
        bool flag;
        Vec2 speed4, speed3, speed2, speed;
        Vec3 rotation2, rotation;
    } local;

    float value =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xfa5, 0);
    if (a->modules->posture->facing() >= lbl_27_rodata_76AC)
        value = -value;

    local.speed.x = value;
    local.speed.y = lbl_27_rodata_76AC;
    fn_27_89D08(
        2, a, 0, &local.speed,
        fn_27_331BEC(&local.rotation, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    local.flag = false;

    value =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xfa6, 0);
    if (a->modules->posture->facing() >= lbl_27_rodata_76AC)
        value = -value;

    local.speed2.x = value;
    local.speed2.y = lbl_27_rodata_76AC;
    fn_27_331AF0(object + 0xb0, &local.speed2);

    local.speed3.x =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xfa7, 0);
    local.speed3.y = lbl_27_rodata_76AC;
    fn_27_331AF0(object + 0xb8, &local.speed3);

    local.speed4.x = lbl_27_rodata_76AC;
    local.speed4.y = lbl_27_rodata_76AC;
    fn_27_89D08(
        0, a, 6, &local.speed4,
        fn_27_331BEC(&local.rotation2, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));
}
}
