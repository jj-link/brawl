#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, unsigned long);
};

struct Mid {
    char pad[0x64];
    Inner* inner;
};

struct Acc {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_17496C(void);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);

extern "C" void fn_27_1780EC(void* a, Acc* b) {
    fn_27_17496C();
    int v = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(b, 0x5a0c, 0);
    b->mid->inner->v5(v, 0x10000012);
}
