#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1CB48[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);

struct Flags {
    u32 hi : 18;
    u32 mid : 9;
    u32 b4 : 1;
    u32 lo : 4;
};

extern "C" void* fn_27_CE588(char* self, void* arg) {
    Flags* f = (Flags*)(self + 8);
    char* p = lbl_27_data_1CB48;
    *(char**)self = p;
    p += 0x48;
    f->hi = 0;
    f->mid = (u32)arg;
    *(char**)(self + 4) = p;
    f->b4 = 0;
    __construct_array(self + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x92);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(self + 4, arg, 0x92);
    return self;
}
