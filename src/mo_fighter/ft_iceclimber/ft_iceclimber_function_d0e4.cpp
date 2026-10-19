#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 position();
};

struct Effect {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void request(int, const Vec3*, const Vec3*, float, int, int);
};

struct Modules {
    char pad0[0xC];
    Posture* posture;
    char pad10[0x78];
    Effect* effect;
};

struct Accessor {
    char pad0[0xD8];
    Modules* modules;

    Posture& getPostureModule() {
        return *modules->posture;
    }
};

struct Fighter {
    char pad0[0x60];
    Accessor* accessor;
};

extern "C" const float lbl_105_rodata_10;
extern "C" const float lbl_105_rodata_8;
extern "C" Vec3* fn_105_C1C0(Vec3*, float, float, float);

extern "C" void fn_105_D0E4(Fighter* fighter) {
    const Vec3& position = fighter->accessor->getPostureModule().position();
    Effect* effect = fighter->accessor->modules->effect;
    Vec3 rotation;
    effect->request(
        0x36, &position,
        fn_105_C1C0(&rotation, lbl_105_rodata_10,
                    lbl_105_rodata_10, lbl_105_rodata_10),
        lbl_105_rodata_8, 0, -1);
}
