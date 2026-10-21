#include <types.h>
#pragma force_active on

extern "C" {
    extern char lbl_27_data_1B218[];
    void fn_27_CE0BC(void);
    void fn_27_25290(void);
    void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
    void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, long);
}

struct ArrayVector {
    void* vt0;
    void* vt1;
    u32 top : 16;
    u32 count : 8;
    u32 flag : 1;
    u32 low : 7;
};

extern "C" void* fn_27_D0EF8(void* self, int arg) {
    ArrayVector* p = (ArrayVector*)self;
    p->top = 0;
    p->vt0 = lbl_27_data_1B218;
    p->vt1 = lbl_27_data_1B218 + 0x48;
    p->count = arg;
    p->flag = 0;
    __construct_array((char*)self + 0xC,
                      (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290,
                      0x30, 0x40);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, arg, 0x40);
    return self;
}
