#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_3D328[];
void __ct__25soCollisionAttackAbsoluteFv(void*);
void __dt__25soCollisionAttackAbsoluteFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
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

extern "C" Obj* fn_27_1A121C(Obj* self, u32 value) {
    self->vtable = lbl_27_data_3D328;
    self->calc = lbl_27_data_3D328 + 0x48;
    self->flags.raw &= 0x03FFFFFF;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array((char*)self + 0xC, __ct__25soCollisionAttackAbsoluteFv,
                      __dt__25soCollisionAttackAbsoluteFv, 0x68, 2);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 2);
    return self;
}
