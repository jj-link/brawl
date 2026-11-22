#pragma force_active on

extern "C" {
extern const unsigned char lbl_110_data_5F8[];
extern const unsigned char lbl_110_data_62B8[];
extern const unsigned char lbl_110_data_212C[];
extern const float lbl_110_rodata_70;
extern const float lbl_110_rodata_74;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_110_8C60(void*);
void* fn_110_1EF78(void*);
}

struct FighterPrefix {
    unsigned char pad0[0x3c];
};

struct FighterView : FighterPrefix {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual int kind();
};

struct WorkModule {
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3();
    virtual int getValue(unsigned int);
};

struct FloatModule {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
    virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34();
    virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
    virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44();
    virtual void f45(); virtual void f46(); virtual void f47();
    virtual void setFloat(float);
};

struct ModuleTable {
    unsigned char pad0[0x1c];
    FloatModule* floatModule;
    unsigned char pad20[0x44];
    WorkModule* workModule;
};

struct AccessView {
    unsigned char pad0[8];
    FighterView* fighter;
    unsigned char pad0c[0xcc];
    ModuleTable* modules;
};

struct Params {
    int a;
    int b;
    int c;
    float d;
    float e;
};

struct Holder {
    unsigned char pad0[0xc];
    Params* params;
};

extern "C" void fn_110_EB54(void*, AccessView* accesser) {
    int b;
    int c;
    FloatModule* floatModule = accesser->modules->floatModule;
    Params* params;
    WorkModule* workModule = accesser->modules->workModule;
    FighterView* fighter = accesser->fighter;

    if (fighter->kind() == 0x15) {
        void* casted = __dynamic_cast(fighter, 0x3c, lbl_110_data_5F8, lbl_110_data_212C, 1);
        params = reinterpret_cast<Holder*>(fn_110_8C60(casted))->params;
    } else {
        void* casted = __dynamic_cast(fighter, 0x3c, lbl_110_data_62B8, lbl_110_data_212C, 1);
        params = reinterpret_cast<Holder*>(fn_110_1EF78(casted))->params;
    }

    int frame = workModule->getValue(0x10000041);
    int mode = workModule->getValue(0x10000042);

    if (mode == 2) {
        int a = params->a;
        if (frame > a * 0x3c) {
            frame = a * 0x3c;
        }
        c = params->c;
        frame -= c * 0x3c;
        float span = (float)(a - c);
        float ratio = (float)frame / (lbl_110_rodata_70 * span);
        float delta = params->e - lbl_110_rodata_74;
        ratio = lbl_110_rodata_74 + delta * ratio;
        floatModule->setFloat(ratio);
    } else if (mode == 1) {
        int c = params->c;
        if (frame > c * 0x3c) {
            frame = c * 0x3c;
        }
        b = params->b;
        frame -= b * 0x3c;
        float span = (float)(c - b);
        float ratio = (float)frame / (lbl_110_rodata_70 * span);
        float delta = params->d - lbl_110_rodata_74;
        ratio = lbl_110_rodata_74 + delta * ratio;
        floatModule->setFloat(ratio);
    } else {
        floatModule->setFloat(lbl_110_rodata_74);
    }
}