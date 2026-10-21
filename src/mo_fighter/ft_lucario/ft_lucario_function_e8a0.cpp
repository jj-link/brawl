#pragma force_active on
struct Inner {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual int s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
};

struct Holder {
    char pad[0x14];
    Inner* inner;
};

struct Module {
    char pad[0xd8];
    Holder* holder;
};

extern const float lbl_118_rodata_3C;
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void* module, unsigned long a, unsigned long b);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* module, unsigned long a, unsigned long b);
extern "C" void fn_118_F958(int frames, float value, void* module);

extern "C" void fn_118_E8A0(void* unused, Module* module) {
    Inner* obj = module->holder->inner;
    if (obj->s3() == 2) {
        int frames = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(module, 0x5dc3, 0);
        float f = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(module, 0xfc3, 0);
        fn_118_F958(frames, f, module);
        fn_118_F958(5, lbl_118_rodata_3C, module);
    }
}
