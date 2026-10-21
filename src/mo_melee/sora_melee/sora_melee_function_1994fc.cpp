#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3CF50[];

void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, unsigned long);
void* fn_27_37D3C(void*, int);
void __ct__16soCollisionGroupFv(void*);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
}

struct Flags {
    u32 low : 6;
    u32 value : 3;
    u32 flag : 1;
    u32 rest : 22;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
    char groups[3][0x78];
};

extern "C" Obj* fn_27_1994FC(Obj* self, int value) {
    self->vtable = lbl_27_data_3CF50;
    self->calc = lbl_27_data_3CF50 + 0x48;
    self->flags.low = 0;
    self->flags.value = value;
    self->flags.flag = 0;

    __construct_array(self->groups, __ct__16soCollisionGroupFv,
                      (void (*)(void*))fn_27_37D3C, 0x78, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 3);

    return self;
}
