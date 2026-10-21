#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3CA90[];
void fn_27_197C88(void);
void fn_27_85800(void);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 6;
        u32 value : 3;
        u32 flag : 1;
        u32 rest : 22;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_19BF3C(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_3CA90;
    self->calc = lbl_27_data_3CA90 + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, (void (*)(void*))fn_27_197C88,
                      (void (*)(void*))fn_27_85800, 0x14, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 4, value, 2);
    return self;
}
