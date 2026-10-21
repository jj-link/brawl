#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3CD68[];
void fn_27_7D898(void*, int);
void fn_27_C9960(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
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

extern "C" Obj* fn_27_198524(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_3CD68;
    self->calc = lbl_27_data_3CD68 + 0x48;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_C9960,
                      (void (*)(void*))fn_27_7D898, 0x1c, 4);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 4);
    return self;
}
