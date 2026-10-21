#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_380D0[];
void fn_27_CDA70(void*, int);
void* fn_27_CDCC4(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 12;
        u32 value : 6;
        u32 flag : 1;
        u32 rest : 13;
    } bits;
};

struct fn27Obj {
    void* vtable;
    void* calc;
    Flags flags;
    unsigned char arr[0x190];
};

extern "C" fn27Obj* fn_27_19F104(fn27Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_380D0;
    self->calc = lbl_27_data_380D0 + 0x48;
    self->flags.raw &= 0x000fffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array(self->arr, (void (*)(void*))fn_27_CDCC4,
                      (void (*)(void*))fn_27_CDA70, 0x10, 0x19);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 0x19);
    return self;
}
