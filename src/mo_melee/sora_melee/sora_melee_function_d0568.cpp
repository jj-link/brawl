#include <types.h>
#pragma force_active on

struct Fn27Obj {
    char* vt0;
    char* vt4;
    u32 hi : 14;
    u32 m : 7;
    u32 b : 1;
    u32 lo : 10;
};

extern "C" char lbl_27_data_1B7E8[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, long);

extern "C" Fn27Obj* fn_27_D0568(Fn27Obj* self, int arg) {
    char* p = lbl_27_data_1B7E8;
    self->vt0 = p;
    p += 0x48;
    self->vt4 = p;
    self->hi = 0;
    self->m = arg;
    self->b = 0;
    __construct_array((char*)self + 0xC,
                      (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290,
                      0x30, 0x27);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, arg, 0x27);
    return self;
}
