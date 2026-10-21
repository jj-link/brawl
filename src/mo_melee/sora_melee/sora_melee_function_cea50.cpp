#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1C860[];
extern void fn_27_25290();
extern void fn_27_CE0BC(void);
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

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
    char arr[0x90 - 0xC];
};

extern "C" Obj* fn_27_CEA50(Obj* self, long value) {
    char* p = lbl_27_data_1C860;
    self->vtable = p;
    self->calc = p + 0x48;
    self->flags.bits.pad = 0;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array(self->arr, (void (*)(void*))fn_27_CE0BC, (void (*)(void*))fn_27_25290, 0x30, 0x13);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 0x13);
    return self;
}
