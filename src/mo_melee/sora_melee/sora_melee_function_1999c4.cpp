#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3CB88[];
extern void fn_27_59FD4(void* p);
extern void fn_27_5A09C(void* ptr, int count);
extern void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union SoFlags {
    u32 raw;
    struct {
        u32 pad : 10;
        u32 value : 5;
        u32 flag : 1;
        u32 rest : 16;
    } bits;
};

struct SoObj {
    void* vtable;
    void* calc;
    SoFlags flags;
    char arr[0x8c * 10];
};

extern "C" SoObj* fn_27_1999C4(SoObj* self, int value) {
    self->vtable = lbl_27_data_3CB88;
    self->calc = lbl_27_data_3CB88 + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_59FD4, (void (*)(void*))fn_27_5A09C, 0x8c, 10);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 10);
    return self;
}
