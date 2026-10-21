#include <types.h>
#pragma force_active on

struct Fn27Obj {
    char* vt0;
    char* vt4;
    u32 hi : 4;
    u32 m : 2;
    u32 b : 1;
    u32 lo : 25;
};

extern "C" char lbl_27_data_3F258[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);

extern "C" Fn27Obj* fn_27_19FF5C(Fn27Obj* self, int arg) {
    char* p = lbl_27_data_3F258;
    self->vt0 = p;
    p += 0x48;
    self->vt4 = p;
    self->hi = 0;
    self->m = arg;
    self->b = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, (void*)arg, 1);
    return self;
}
