#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct WorkModule {
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void offFlag(unsigned int);
};

struct EffectModule {
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void invoke(unsigned int, unsigned int,
                        const Vec3f*, const Vec3f*,
                        float, int, int, int, int);
};

struct Modules {
    char pad00[0x64];
    WorkModule* work;
    char pad68[0x20];
    EffectModule* effect;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct State {
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void invoke(Accesser*);
};

extern "C" {
extern const unsigned char lbl_120_rodata_40[];
Vec3f* fn_120_8718(Vec3f*, float, float, float);

void fn_120_EEB4(State* self, Accesser* accesser) {
    const float* data =
        reinterpret_cast<const float*>(lbl_120_rodata_40);

    accesser->modules->work->offFlag(0x22000013);
    accesser->modules->work->offFlag(0x22000014);
    self->invoke(accesser);

    EffectModule* effect = accesser->modules->effect;
    Vec3f position, rotation;

    effect->invoke(
        0x240002, 0x60,
        fn_120_8718(&position, data[0], data[0], data[0]),
        fn_120_8718(&rotation, data[0], data[0], data[1]),
        data[2], 0, 1, 0, -1);
}
}
