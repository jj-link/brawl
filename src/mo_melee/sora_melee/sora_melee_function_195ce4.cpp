#pragma force_active on

struct Vec3 {
    float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};

struct Constants {
    float zero;
    float pad[8];
    float radians;
    float gap[2];
    float degrees;
};

struct Effect {
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
    virtual unsigned int reqFollow(
        int, int, Vec3*, Vec3*, float, bool, unsigned int, unsigned int, int);
};

struct Modules {
    char pad[0x88];
    Effect* effect;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
extern const unsigned char lbl_27_rodata_26B0[];

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);

void fn_27_195CE4(Access* accesser) {
    const Constants* c = (const Constants*)lbl_27_rodata_26B0;
    Vec3 pos;
    float angle = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xC26, 0);
    Vec3 rot = {c->zero, c->zero, c->zero};
    float z = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xC25, 0);
    pos.set(c->zero,
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xC24, 0),
        z);
    Effect* effect = accesser->modules->effect;
    int id = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0x59E6, 0);
    effect->reqFollow(0x3C, id, &pos, &rot,
        c->radians * (angle / c->degrees), false, 0, 0, -1);
}
}
