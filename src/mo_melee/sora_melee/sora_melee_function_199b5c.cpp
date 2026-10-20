#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_39CA8[];

void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 10;
        u32 value : 5;
        u32 rest : 17;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_199B5C(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_39CA8;
    self->calc = lbl_27_data_39CA8 + 0x48;
    self->flags.raw &= 0x003fffff;
    self->flags.bits.value = value;
    self->flags.raw &= 0xfffeffff;

    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 12);
    return self;
}
