#pragma scheduling off
#pragma optimize_for_size on
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

void fn_27_332260(void*, void*, void*, Accesser* a) {
    float x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        a, 0xfb0, 0);
    if (a->modules->posture->facing() < lbl_27_rodata_76AC)
        x = -x;

    Vec2 first;
    first.x = x;
    first.y = lbl_27_rodata_76AC;
    Vec3 rotation;
    fn_27_89D08(
        2, a, 0, &first,
        fn_27_331BEC(&rotation, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));

    float y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        a, 0xfb1, 0);
    Vec2 second;
    second.x = lbl_27_rodata_76AC;
    second.y = y;
    Vec3 rotation2;
    fn_27_89D08(
        1, a, 0, &second,
        fn_27_331BEC(&rotation2, lbl_27_rodata_76AC,
                     lbl_27_rodata_76AC, lbl_27_rodata_76AC));
}
}
