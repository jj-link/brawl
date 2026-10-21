#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_1B120[];
void fn_27_CE0BC(void);
void fn_27_25290(void);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, long);
}

struct Fn27Obj {
    void* vt0;
    void* vt4;
    u32 top : 16;
    u32 mid : 8;
    u32 flag : 1;
    u32 low : 7;
};

extern "C" void* fn_27_D1090(void* self, int arg) {
    Fn27Obj* p = (Fn27Obj*)self;
    p->top = 0;
    p->vt0 = lbl_27_data_1B120;
    p->vt4 = lbl_27_data_1B120 + 0x48;
    p->mid = arg;
    p->flag = 0;
    __construct_array((char*)self + 0xC,
                      (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290,
                      0x30, 0x41);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, arg, 0x41);
    return self;
}
