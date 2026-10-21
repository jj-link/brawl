#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3A608[];
void fn_27_1374C(void*, int);
void* fn_27_13700(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 6;
        u32 value : 3;
        u32 flag : 1;
        u32 rest : 22;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_198854(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_3A608;
    self->calc = lbl_27_data_3A608 + 0x48;
    self->flags.raw &= 0x03ffffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_13700, (void (*)(void*))fn_27_1374C, 0x48, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 3);
    return self;
}
