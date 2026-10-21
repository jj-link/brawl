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

struct CommonData {
    char pad[0xb8];
    float* data;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const char lbl_107_rodata_78[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
float fn_27_1949F0(Accesser*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);
void fn_27_165458(
    Accesser*, float, float, float, float, float, unsigned long, float);
void fn_27_164E48(
    Accesser*, const char*, unsigned long, float, unsigned long);
void fn_107_14328(void*, Accesser*);
}

extern "C" void fn_107_12BDC(void* self, Accesser* accesser) {
    float* data = static_cast<CommonData*>(
        getData__20ftCommonDataAccesserCF6ftKind(
            g_ftCommonDataAccesser, 0x12))->data;
    float b, a;
    a = fn_27_1949F0(accesser);
    Work* work = accesser->modules->work;
    b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, 0xc2e, 0);
    float f = work->getFloat(0x21000004);
    fn_27_165458(
        accesser, f, data[2], data[0], data[1], b, 0x21000004, a);
    fn_27_164E48(
        accesser, lbl_107_rodata_78, 0x21000004, a, 0x21000005);
    fn_107_14328(self, accesser);
}
