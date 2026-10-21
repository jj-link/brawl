#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3A6F8[];
void* fn_27_137B4(void* self);
void fn_27_137EC(void*, int);
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

extern "C" Obj* fn_27_19838C(Obj* self, unsigned int value) {
    Flags f;
    f.raw = self->flags.raw;
    self->vtable = lbl_27_data_3A6F8;
    self->calc = lbl_27_data_3A6F8 + 0x48;
    f.bits.pad = 0;
    f.bits.value = value;
    f.bits.flag = 0;
    self->flags = f;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_137B4, (void (*)(void*))fn_27_137EC, 0x2C, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 2);
    return self;
}
