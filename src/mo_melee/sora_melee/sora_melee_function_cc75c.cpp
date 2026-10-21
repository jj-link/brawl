#include <types.h>
#pragma force_active on

extern "C" {
    extern char lbl_27_data_1E2C0[0x90];
    void __ct__18soModelVirtualNodeFv(void*);
    void __dt__18soModelVirtualNodeFv(void*, int);
    void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
    void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
}

struct FnBits {
    u32 a : 6;
    u32 b : 3;
    u32 c : 1;
    u32 d : 22;
};

extern "C" void* fn_27_CC75C(void* self, int arg, int unused) {
    char* p = (char*)self;
    FnBits* bits = (FnBits*)(p + 0x8);

    *(char**)(p + 0x0) = lbl_27_data_1E2C0;
    *(char**)(p + 0x4) = lbl_27_data_1E2C0 + 0x48;

    bits->a = 0;
    bits->b = arg;
    bits->c = 0;

    __construct_array(p + 0xC, (void (*)(void*))__ct__18soModelVirtualNodeFv,
                      (void (*)(void*))__dt__18soModelVirtualNodeFv, 0x14, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(p + 0x4, arg, 3);
    return self;
}
