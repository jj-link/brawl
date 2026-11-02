#pragma force_active on

struct Mod {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float getFloat(unsigned int);
    virtual void setFloat(float, unsigned int);
    virtual void s16(); virtual void s17();
    virtual void fn48(void*, int);
    virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22();
    virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30();
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38();
    virtual void s39();
    virtual void fnA0(int, float);
    virtual void fnA4(int);
};

struct Mods {
    char pad0[0x64];
    Mod* work;
    char pad68[0x1c];
    Mod* art;
    Mod* effect;
};

struct Acc {
    char pad0[0xd8];
    Mods* mods;
};

struct CData {
    char pad[0x90];
    void* u90;
    char pad94[0xc];
    void* ua0;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
extern const float lbl_120_rodata_74;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Acc*, unsigned long, unsigned long);
CData* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);

void fn_120_101F8(void*, Acc* acc, int kind) {
    switch (kind) {
    case 0:
    case 0xE:
    case 0x1F:
    case 0x20: {
        Mod* work = acc->mods->work;
        float f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xFCF, 0);
        if (work->getFloat(0x11000014) >= f) {
            acc->mods->effect->fnA0(0x1A, lbl_120_rodata_74);
        }
        goto common;
    }
    default:
        acc->mods->effect->fnA4(0x1A);
        acc->mods->work->setFloat(lbl_120_rodata_74, 0x11000014);
    common:
        acc->mods->art->fn48(getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x23)->u90, 0);
        acc->mods->art->fn48(getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x23)->ua0, 0);
        break;
    case 0x11B:
    case 0x11C:
    case 0x11D:
        break;
    }
}
}
