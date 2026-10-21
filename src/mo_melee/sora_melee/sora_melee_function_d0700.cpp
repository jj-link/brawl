#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1B6F0[];
void fn_27_25290();
void fn_27_CE0BC();
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 14;
        u32 value : 7;
        u32 flag : 1;
        u32 rest : 10;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_D0700(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1B6F0;
    self->calc = lbl_27_data_1B6F0 + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 0x2b);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 0x2b);
    return self;
}
