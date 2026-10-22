#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1C0A0[];
void fn_27_25290();
void fn_27_CE0BC();
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
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

extern "C" Obj* fn_27_CF710(Obj* self, u32 kind) {
    Flags f;
    f.raw = self->flags.raw;
    self->vtable = lbl_27_data_1C0A0;
    self->calc = lbl_27_data_1C0A0 + 0x48;
    f.bits.pad = 0;
    f.bits.value = kind;
    f.bits.flag = 0;
    self->flags = f;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 29);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, (long)kind, 29);
    return self;
}
