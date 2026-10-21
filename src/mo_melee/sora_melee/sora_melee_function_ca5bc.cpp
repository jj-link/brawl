#pragma force_active on
extern "C" {
extern char lbl_27_data_1F9B0[];
void fn_27_A6948(void*);
void fn_27_A6978(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    unsigned int raw;
    struct {
        unsigned int pad : 10;
        unsigned int value : 5;
        unsigned int flag : 1;
        unsigned int rest : 16;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_CA5BC(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1F9B0;
    self->calc = lbl_27_data_1F9B0 + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 0xc);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 0xc);
    return self;
}
