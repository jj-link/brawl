#pragma force_active on

struct Vec3 {
    float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; }
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

struct Other {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void call(int, int);
};

struct Modules {
    char pad[0x64];
    Other* other;
    char pad2[0x20];
    Effect* effect;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
extern const float lbl_27_rodata_26B0;
extern const float lbl_27_rodata_26E0;

float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);

void fn_27_195BB4(Access* accesser, int arg1) {
    Vec3 pos;
    float angle = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xC26, 0);
    Vec3 rot;
    rot.x = lbl_27_rodata_26B0;
    rot.y = lbl_27_rodata_26B0;
    rot.z = lbl_27_rodata_26B0;
    float z = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xC25, 0);
    pos.set(lbl_27_rodata_26B0,
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xC24, 0),
        z);
    Effect* effect = accesser->modules->effect;
    int id = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0x59E6, 0);
    unsigned int ret = effect->reqFollow(0x3E, id, &pos, &rot,
        angle / lbl_27_rodata_26E0, false, 0, 0, -1);
    Other* other = accesser->modules->other;
    other->call((int)ret, arg1);
}
}