#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1C198[];
extern void fn_27_CE0BC(void);
extern void fn_27_25290();
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 rest : 12;
        u32 value : 6;
        u32 flag : 1;
        u32 low : 13;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_CF578(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1C198;
    self->calc = lbl_27_data_1C198 + 0x48;
    self->flags.raw &= 0x000fffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 0x1c);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 0x1c);
    return self;
}
