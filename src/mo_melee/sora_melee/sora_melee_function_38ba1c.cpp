#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_39AC8[];

void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
void fn_27_6A244(void*, void*, void*);
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

extern "C" Obj* fn_27_38BA1C(Obj* self, void* owner) {
    self->vtable = lbl_27_data_39AC8;
    self->calc = lbl_27_data_39AC8 + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = 6;
    self->flags.bits.flag = 0;
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, 6, 6);
    fn_27_6A244((char*)self + 0x144, owner, self);
    return self;
}
