#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3C078[];
void fn_27_CDA70(void*, int);
extern char fn_27_CDCC4[];
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, unsigned long);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

struct Flags {
    u32 a : 8;
    u32 value : 4;
    u32 flag : 1;
    u32 rest : 19;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
    char entries[0x50];
};

extern "C" Obj* fn_27_19F434(Obj* self, int value) {
    self->vtable = lbl_27_data_3C078;
    self->calc = lbl_27_data_3C078 + 0x48;
    self->flags.a = 0;
    self->flags.value = value;
    self->flags.flag = 0;
    __construct_array(self->entries, (void (*)(void*))fn_27_CDCC4, (void (*)(void*))fn_27_CDA70, 0x10, 5);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 5);
    return self;
}
