#pragma force_active on

typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_372F0[];
void __ct__25soCollisionAttackAbsoluteFv(void*);
void __dt__25soCollisionAttackAbsoluteFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

union Flags {
    u32 raw;
    struct {
        u32 pad : 8;
        u32 value : 4;
        u32 flag : 1;
        u32 rest : 19;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_1A13B4(Obj* self, u32 value) {
    self->vtable = lbl_27_data_372F0;
    self->calc = lbl_27_data_372F0 + 0x48;
    self->flags.raw &= 0x00FFFFFF;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, __ct__25soCollisionAttackAbsoluteFv,
                      __dt__25soCollisionAttackAbsoluteFv, 0x68, 6);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 6);
    return self;
}
