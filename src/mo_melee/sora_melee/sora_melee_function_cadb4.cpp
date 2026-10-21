#pragma force_active on
typedef unsigned long u32;

extern "C" {
extern char lbl_27_data_1F500[];
void fn_27_A6948(void*);
void fn_27_A6978(void*);
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

struct Object {
    void* vt0;
    void* vt1;
    Flags flags;
    char elems[8][0x24];
};

extern "C" Object* fn_27_CADB4(Object* self, int n) {
    self->vt0 = lbl_27_data_1F500;
    self->vt1 = lbl_27_data_1F500 + 0x48;
    self->flags.raw &= 0x003fffff;
    self->flags.bits.value = n;
    self->flags.bits.flag = 0;
    __construct_array(self->elems, fn_27_A6948, fn_27_A6978, 0x24, 8);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->vt1, n, 8);
    return self;
}
