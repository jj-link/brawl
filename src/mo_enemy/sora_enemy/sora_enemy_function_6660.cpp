#pragma force_active on

extern "C" float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned int id, unsigned int index);
extern "C" const float lbl_41_rodata_18;
extern "C" const double lbl_41_rodata_40;

struct Target {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int, int);
};

struct Outer {
    char pad0[0xDC];
    char pad1[0x1B4 - 0xDC];
    void* mid;
};

extern "C" void fn_41_6660(Outer* self, float* fs, int arg2) {
    Target* target = *(Target**)((char*)*(void**)((char*)self + 0x1B4) + 0x64);
    int n = (int)fs[0];
    float val = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl((char*)self + 0xDC, 0x1100000C, 0);
    if (lbl_41_rodata_18 != fs[1]) {
        n = (int)((float)n + fs[1] * val);
    }
    target->f5(n, arg2);
}
