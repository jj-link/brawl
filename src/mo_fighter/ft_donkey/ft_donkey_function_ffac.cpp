#pragma force_active on
struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
float fn_27_1949F0(Accesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);
void fn_27_165458(
    Accesser*, float, float, float, float, float, unsigned long, float);
extern const char lbl_92_rodata_90[];
void fn_27_164E48(
    Accesser*, const char*, unsigned long, float, unsigned long);

void fn_92_FFAC(void*, Accesser* accesser) {
    float e, d, c, b, a;
    a = fn_27_1949F0(accesser);
    Work* work = accesser->modules->work;
    b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xc2e, 0);
    c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xbba, 0);
    d = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xbb9, 0);
    e = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xbbb, 0);
    float f = work->getFloat(0x21000004);
    fn_27_165458(accesser, f, e, d, c, b, 0x21000004, a);
    fn_27_164E48(
        accesser, lbl_92_rodata_90, 0x21000004, a, 0x21000005);
}
}
