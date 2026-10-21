#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_1FF20[];
void fn_27_C9960(void* p);
void fn_27_7D898(void* p, int n);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);
}

union Flags {
    u32 raw;
    struct {
        u32 hi : 6;
        u32 f : 3;
        u32 g : 1;
        u32 rest : 22;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" void* fn_27_C9B1C(void* self, void* arg) {
    Obj* o = (Obj*)self;
    void (*dtor)(void*) = (void (*)(void*))fn_27_7D898;
    o->flags.raw = o->flags.raw;
    o->vtable = lbl_27_data_1FF20;
    o->calc = lbl_27_data_1FF20 + 0x48;
    o->flags.bits.hi = 0;
    o->flags.bits.f = (u32)arg;
    o->flags.bits.g = 0;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_C9960, dtor, 0x1c, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self + 4, arg, 2);
    return self;
}
