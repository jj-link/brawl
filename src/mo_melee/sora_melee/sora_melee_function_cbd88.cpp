#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1EA88[];

void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 8;
        u32 value : 4;
        u32 rest : 20;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_CBD88(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1EA88;
    self->calc = lbl_27_data_1EA88 + 0x48;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = value;
    self->flags.raw &= 0xfff7ffff;

    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 5);
    return self;
}
