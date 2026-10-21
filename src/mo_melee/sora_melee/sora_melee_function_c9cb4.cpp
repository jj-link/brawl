#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1FDD0[];
void fn_27_13700(void*);
void fn_27_1374C(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

struct Obj {
    void* vtable;
    void* calc;
    union {
        u32 raw;
        struct {
            u32 pad : 4;
            u32 value : 2;
            u32 flag : 1;
            u32 rest : 25;
        } bits;
    } flags;
};

extern "C" Obj* fn_27_C9CB4(Obj* self, unsigned int value) {
    self->vtable = (void*)lbl_27_data_1FDD0;
    self->calc = (void*)(lbl_27_data_1FDD0 + 0x48);
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_13700, (void (*)(void*))fn_27_1374C, 0x48, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self + 0x4, value, 1);
    return self;
}
