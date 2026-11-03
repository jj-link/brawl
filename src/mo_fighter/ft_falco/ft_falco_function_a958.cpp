#pragma force_active on

struct FighterVector {
    float x, y, z;
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
                        const FighterVector*, const FighterVector*,
                        float, int, int, int, int);
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual void s68(bool, bool, bool);
};

struct ModuleB {
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
    virtual void s3C(int, int, int);
};

struct Modules {
    char pad00[0x28];
    ModuleB* b28;
    char pad2C[0x88 - 0x2C];
    EffectModule* effect;
};

struct Accesser {
    char pad00[0xD8];
    Modules* modules;
};

struct Fighter {
    char pad00[0x60];
    Accesser* accesser;
    char pad64[0x1D090 - 0x64];
    unsigned char flag090;
    unsigned char flag091;
};

extern "C" {
extern const float lbl_108_rodata_4;
extern const float lbl_108_rodata_8;
FighterVector* fn_108_AA84(FighterVector*, float, float, float);
void fn_27_135DE8(void*);

int fn_108_A958(Fighter* arg0) {
    if (arg0->flag090 == 1) {
        EffectModule* effect = arg0->accesser->modules->effect;
        FighterVector b, a;
        effect->invoke(0x14000C, 0x12,
                       fn_108_AA84(&b, lbl_108_rodata_8, lbl_108_rodata_8, lbl_108_rodata_8),
                       fn_108_AA84(&a, lbl_108_rodata_8, lbl_108_rodata_8, lbl_108_rodata_8),
                       lbl_108_rodata_4, 0, 0, 0, -1);
        return 1;
    }
    if (arg0->flag091 == 1) {
        arg0->accesser->modules->effect->s68(1, 1, 1);
        arg0->accesser->modules->b28->s3C(0, 0, 2);
    }
    fn_27_135DE8(arg0);
}
}
