#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1F410[];
void fn_27_A6948(void*);
void fn_27_A6978(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, unsigned long);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 hi : 10;
        u32 value : 5;
        u32 flag : 1;
        u32 low : 16;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_CAFB8(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1F410;
    self->calc = lbl_27_data_1F410 + 0x48;
    self->flags.raw &= 0x003fffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 9);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 9);
    return self;
}
