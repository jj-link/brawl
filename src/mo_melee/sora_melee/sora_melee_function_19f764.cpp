#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_37DE8[];
void* fn_27_CDCC4(void*);
void fn_27_CDA70(void*, int);
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

extern "C" Obj* fn_27_19F764(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_37DE8;
    self->calc = lbl_27_data_37DE8 + 0x48;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_CDCC4,
                      (void (*)(void*))fn_27_CDA70, 0x10, 7);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 7);
    return self;
}
