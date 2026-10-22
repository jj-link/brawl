#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_20010[];
void fn_27_C9960(void*);
void fn_27_7D898(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
void fn_27_68888(void*, void*, void*, void*);
}

struct Flags {
    u32 a : 4;
    u32 b : 2;
    u32 c : 1;
    u32 d : 25;
};

extern "C" void* fn_27_314F34(void* self, void* arg1, void* arg2) {
    char* p = (char*)self;
    Flags* f = (Flags*)(p + 8);
    *(void**)(p + 4) = lbl_27_data_20010 + 0x48;
    *(void**)p = lbl_27_data_20010;
    f->a = 0;
    f->b = 1;
    f->c = 0;
    __construct_array(p + 0xc, (void (*)(void*))fn_27_C9960,
                      (void (*)(void*))fn_27_7D898, 0x1c, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        p + 4, 1, 1);
    fn_27_68888(p + 0x28, arg1, self, arg2);
    return self;
}
