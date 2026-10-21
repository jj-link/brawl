#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1FCE0[];
void* fn_27_1374C(void* p, int flag);
void* fn_27_13700(void* p);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union fn_27_Flags {
    u32 raw;
    struct {
        u32 hi : 6;
        u32 a : 3;
        u32 b : 1;
        u32 lo : 22;
    } bits;
};

struct fn_27_Obj {
    void* vtable;
    void* calc;
    fn_27_Flags flags;
};

extern "C" fn_27_Obj* fn_27_C9E4C(fn_27_Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1FCE0;
    self->calc = lbl_27_data_1FCE0 + 0x48;
    self->flags.bits.hi = 0;
    self->flags.bits.a = value;
    self->flags.bits.b = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_13700, (void (*)(void*))fn_27_1374C, 0x48, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 2);
    return self;
}
