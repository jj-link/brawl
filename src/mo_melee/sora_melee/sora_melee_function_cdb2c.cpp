#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1D2B8[];
void fn_27_CDA70(void*, int);
void fn_27_CDCC4(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 10;
        u32 value : 5;
        u32 flag : 1;
        u32 rest : 16;
    } bits;
};

struct Obj {
    void* vt;
    void* calc;
    Flags flags;
    char arr[0xa0];
};

extern "C" Obj* fn_27_CDB2C(Obj* self, int value) {
    self->vt = lbl_27_data_1D2B8;
    self->calc = lbl_27_data_1D2B8 + 0x48;
    self->flags.raw &= 0x3fffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array(self->arr, (void (*)(void*))fn_27_CDCC4, (void (*)(void*))fn_27_CDA70, 0x10, 0xa);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 0xa);
    return self;
}
