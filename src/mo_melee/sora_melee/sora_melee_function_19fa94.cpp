#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_37BF8[];
void fn_27_46A74(void* p);
void* fn_27_46B20(void* ptr, int size);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 6;
        u32 value : 3;
        u32 flag : 1;
        u32 rest : 22;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_19FA94(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_37BF8;
    self->calc = lbl_27_data_37BF8 + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_46A74,
                      (void (*)(void*))fn_27_46B20, 0xB8, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 2);
    return self;
}
