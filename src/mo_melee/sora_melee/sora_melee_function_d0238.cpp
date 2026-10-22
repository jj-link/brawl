#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1B9D8[];
void fn_27_25290(void);
void fn_27_CE0BC(void);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, unsigned long);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 a : 14;
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

extern "C" Obj* fn_27_D0238(Obj* self, unsigned int value) {
    Flags f;
    f.raw = self->flags.raw;
    self->vtable = lbl_27_data_1B9D8;
    self->calc = lbl_27_data_1B9D8 + 0x48;
    f.bits.a = 0;
    f.bits.value = value;
    f.bits.flag = 0;
    self->flags.raw = f.raw;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 0x25);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self + 4, value, 0x25);
    return self;
}
