#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_37B00[];
void fn_27_46A74(void*);
void* fn_27_46B20(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 8;
        u32 value : 4;
        u32 flag : 1;
        u32 rest : 19;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_19FDC4(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_37B00;
    self->calc = lbl_27_data_37B00 + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_46A74,
                      (void (*)(void*))fn_27_46B20, 0xB8, 4);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 4);
    return self;
}
