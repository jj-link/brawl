#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1A8E8[];
void __ct__25soCollisionAttackAbsoluteFv(void*);
void __dt__25soCollisionAttackAbsoluteFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 4;
        u32 value : 2;
        u32 flag : 1;
        u32 rest : 25;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_D24E8(Obj* self, u32 value) {
    self->vtable = lbl_27_data_1A8E8;
    self->calc = lbl_27_data_1A8E8 + 0x48;
    self->flags.raw &= 0x0FFFFFFF;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, __ct__25soCollisionAttackAbsoluteFv,
                      __dt__25soCollisionAttackAbsoluteFv, 0x68, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, value, 1);
    return self;
}
