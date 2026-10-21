#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class VA {
public:
    virtual void d0(); virtual void d1();
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual float s7();
};

class VB {
public:
    virtual void d0(); virtual void d1();
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(float* p, unsigned long v);
};

extern const float lbl_109_rodata_60;

extern "C" void fn_109_11CE8(void*, soModuleAccesser* accesser) {
    char* p = *(char**)((char*)accesser + 0xd8);
    VB* obj = *(VB**)(p + 0x60);
    VA* sub = *(VA**)(p + 0x0c);
    float scale = sub->s7();
    float arr[3];
    float c0 = soValueAccesser::getConstantFloat(accesser, 0xfa0, 0);
    arr[0] = scale * c0;
    arr[1] = soValueAccesser::getConstantFloat(accesser, 0xfa1, 0);
    arr[2] = lbl_109_rodata_60;
    obj->s15(arr, 0);
}
