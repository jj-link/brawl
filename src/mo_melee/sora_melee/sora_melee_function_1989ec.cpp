#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3A518[];
void fn_27_1374C(void*, int);
void* fn_27_13700(void*);
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

extern "C" Obj* fn_27_1989EC(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_3A518;
    self->calc = lbl_27_data_3A518 + 0x48;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_13700,
                      (void (*)(void*))fn_27_1374C, 0x48, 4);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 4);
    return self;
}
