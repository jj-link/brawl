#include <types.h>
#pragma force_active on

extern "C" {
    extern char lbl_27_data_1C578[];
    void fn_27_CE0BC(void);
    void fn_27_25290(void);
    void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
    void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, long);
}

struct Bits {
    void* vt0;
    void* vt1;
    u32 top : 12;
    u32 mid : 6;
    u32 one : 1;
    u32 low : 13;
};

extern "C" void* fn_27_CEF18(void* self, int arg) {
    Bits* b = (Bits*)self;
    b->top = 0;
    b->vt0 = lbl_27_data_1C578;
    b->vt1 = lbl_27_data_1C578 + 0x48;
    b->mid = arg;
    b->one = 0;
    __construct_array((char*)self + 0xC,
                      (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 24);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, arg, 24);
    return self;
}
