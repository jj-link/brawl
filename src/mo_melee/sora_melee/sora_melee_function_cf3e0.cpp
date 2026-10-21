#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1C290[];
void fn_27_CE0BC();
void fn_27_25290();
void __construct_array(void*, void*, void*, u32, u32);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 12;
        u32 value : 6;
        u32 flag : 1;
        u32 rest : 13;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_CF3E0(Obj* self, unsigned int value) {
    self->vtable = (void*)lbl_27_data_1C290;
    self->calc = (void*)(lbl_27_data_1C290 + 0x48);
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xc, (void*)fn_27_CE0BC, (void*)fn_27_25290, 0x30, 0x1b);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 0x1b);
    return self;
}
