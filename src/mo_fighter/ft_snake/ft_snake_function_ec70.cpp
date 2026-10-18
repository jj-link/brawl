#pragma force_active on
extern const float lbl_122_rodata_C;

struct Work {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void setFloat(float, unsigned long);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct soModuleAccesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" void fn_122_EC70(float* p, soModuleAccesser* a) {
    if (*p < lbl_122_rodata_C) {
        Work* w = a->modules->work;
        float k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0xFB0, 0);
        k = -*p * k;
        w->setFloat(k, 0x21000005);

        w = a->modules->work;
        k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0xFAD, 0);
        k = *p * k;
        w->setFloat(k, 0x21000004);
    } else if (*p > lbl_122_rodata_C) {
        Work* w = a->modules->work;
        float k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0xFAF, 0);
        k = -*p * k;
        w->setFloat(k, 0x21000005);

        w = a->modules->work;
        k = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            a, 0xFAC, 0);
        k = *p * k;
        w->setFloat(k, 0x21000004);
    } else {
        Work* w = a->modules->work;
        w->setFloat(lbl_122_rodata_C, 0x21000005);

        w = a->modules->work;
        w->setFloat(lbl_122_rodata_C, 0x21000004);
    }
}
