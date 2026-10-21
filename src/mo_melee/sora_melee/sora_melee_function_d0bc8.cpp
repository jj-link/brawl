#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_1B408[];
void fn_27_CE0BC(void);
void fn_27_25290(void);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    unsigned int raw;
    struct {
        unsigned int hi : 14;
        unsigned int value : 7;
        unsigned int flag : 1;
        unsigned int lo : 10;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_D0BC8(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1B408;
    self->calc = lbl_27_data_1B408 + 0x48;
    self->flags.bits.hi = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x36);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 0x36);
    return self;
}
