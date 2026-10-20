#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_20390[];

void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 6;
        u32 value : 3;
        u32 rest : 23;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_C94F0(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_20390;
    self->calc = lbl_27_data_20390 + 0x48;
    self->flags.raw &= 0x03ffffff;
    self->flags.bits.value = value;
    self->flags.raw &= 0xffbfffff;

    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 3);

    return self;
}
