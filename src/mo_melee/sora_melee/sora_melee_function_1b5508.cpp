#include <types.h>
#pragma force_active on

struct VBase {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
};

struct VNoArg : VBase {
    virtual void* f26();
};

struct VArg : VBase {
    virtual void* f26(void* arg);
};

extern "C" void fn_27_1B5508(void* self, void* unused, void* arg) {
    void* p = ((VNoArg*)self)->f26();
    void* q = ((VArg*)self)->f26(arg);
    *(u32*)q = *(u32*)p;
}
