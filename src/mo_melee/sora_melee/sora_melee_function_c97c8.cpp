#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_20158[];
void* fn_27_137B4(void* self);
void* fn_27_137EC(void* p, int flag);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void* self, long a, long b);

struct FnObj {
    char* vt0;
    char* vt1;
    struct {
        u32 a : 6;
        u32 b : 3;
        u32 c : 1;
        u32 d : 22;
    } bits;
};

void* fn_27_C97C8(void* self, int flag) {
    FnObj* o = (FnObj*)self;
    o->vt0 = lbl_27_data_20158;
    o->vt1 = lbl_27_data_20158 + 0x48;
    o->bits.a = 0;
    o->bits.b = flag;
    o->bits.c = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_137B4, (void (*)(void*))fn_27_137EC, 0x2C, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&o->vt1, flag, 3);
    return self;
}
}
