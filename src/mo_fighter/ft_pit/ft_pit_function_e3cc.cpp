#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_112_rodata_24;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
}

struct Vec3fTmp {
    float x;
    float y;
    float z;
};

struct VObj {
    int pad[2];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24(int, Vec3fTmp*);
};

extern "C" void fn_112_E3CC(void*, soModuleAccesser* accesser) {
    Vec3fTmp v;
    v.x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfba, 0);
    v.z = lbl_112_rodata_24;
    v.y = lbl_112_rodata_24;
    char* p = *(char**)((char*)accesser + 0xd8);
    VObj* q = *(VObj**)(p + 4);
    q->f24(0x2e, &v);
}
