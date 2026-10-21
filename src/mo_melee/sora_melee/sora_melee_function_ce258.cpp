#include <types.h>
#pragma force_active on

extern "C" {
    extern char lbl_27_data_1CD38[];
    void fn_27_CE0BC(void);
    void fn_27_25290(void);
    void __construct_array(void* p, void (*ctor)(void*), void (*dtor)(void*), unsigned long size, int count);
    void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, int calc, long n);
}

struct Bits {
    void* vt0;
    void* vt1;
    u32 top : 10;
    u32 mid : 5;
    u32 one : 1;
    u32 low : 16;
};

extern "C" void* fn_27_CE258(void* self, int arg) {
    Bits* b = (Bits*)self;
    b->top = 0;
    b->vt0 = lbl_27_data_1CD38;
    b->vt1 = lbl_27_data_1CD38 + 0x48;
    b->mid = arg;
    b->one = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 12);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((void*)((u32)self + 4), arg, 12);
    return self;
}
