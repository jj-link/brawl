#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1B5F8[];
extern void fn_27_25290();
extern void fn_27_CE0BC();
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 hi : 14;
        u32 value : 7;
        u32 b10 : 1;
        u32 lo : 10;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
    char arr[0x30 * 0x2c];
};

extern "C" Obj* fn_27_D0898(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1B5F8;
    self->calc = lbl_27_data_1B5F8 + 0x48;
    self->flags.bits.hi = 0;
    self->flags.bits.value = value;
    self->flags.bits.b10 = 0;
    __construct_array(&self->arr, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x2c);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 0x2c);
    return self;
}
