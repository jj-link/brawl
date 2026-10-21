#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1F0B8[];
void fn_27_B15E8(void*);
void fn_27_B164C(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 4;
        u32 value : 2;
        u32 flag : 1;
        u32 rest : 25;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
    char array[0x44];
};

extern "C" Obj* fn_27_CB410(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1F0B8;
    self->calc = lbl_27_data_1F0B8 + 0x48;
    self->flags.raw &= 0x0fffffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array(self->array, fn_27_B15E8, fn_27_B164C, 0x44, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 1);
    return self;
}
