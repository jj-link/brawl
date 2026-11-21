#pragma force_active on
extern "C" void fn_27_12DCA8(void*);
extern "C" void fn_27_357E18(void*, void*, void*, void*);
extern "C" char lbl_27_bss_8094[];
extern "C" const float lbl_110_rodata_1CC;
extern "C" const float lbl_110_rodata_1D0;

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual float getFloat(int);
    virtual void v13(); virtual void v14(); virtual void v15();
    virtual void setFloat(float, int);
    virtual int isFlag(int);
    virtual void onFlag(int);
};

struct Mod88 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
    virtual void fA0(int, float);
    virtual void fA4(int);
    virtual void v40(); virtual void v41();
    virtual int fB0(int);
};

struct Acc {
    char pad[0x64];
    Work* work;
    char pad2[0x88 - 0x68];
    Mod88* m88;
};

struct Obj {
    char pad[0x60];
    struct {
        char pad[0xd8];
        Acc* acc;
    }* inner;
};

extern "C" void fn_110_1F638(char* base) {
    char* p;
    fn_27_12DCA8(base);
    fn_27_357E18(lbl_27_bss_8094, *(void**)(*(char**)(base + 0xB24C) + 0x88),
                 *(void**)(base + 0x60), base + 0xB250);
    Obj* o = (Obj*)base;
    Work* w = o->inner->acc->work;
    if (w->isFlag(0x1200003d)) {
        w->setFloat(lbl_110_rodata_1CC, 0x11000013);
        if (!w->isFlag(0x1200003e)) {
            p = *(char**)(base + 0xB24C);
            char** t11_53 = (char**)(p + 0x8c);
            if (w->getFloat(0x11000013) < *(float*)(*t11_53 + 0xc)) {
                w->onFlag(0x1200003e);
                o->inner->acc->m88->fA0(0x25, lbl_110_rodata_1D0);
            }
        }
    }
    if (o->inner->acc->m88->fB0(1)) {
        o->inner->acc->m88->fA4(1);
    }
}
