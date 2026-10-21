#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_1E0A0[];
void __dt__19soCollisionHitGroupFv(void*, int);
void __ct__19soCollisionHitGroupFv(void*);
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
    char group[0x38];
};

extern "C" Obj* fn_27_CC8F4(Obj* self, unsigned int value) {
    self->vtable = lbl_27_data_1E0A0;
    self->calc = lbl_27_data_1E0A0 + 0x48;
    self->flags.raw &= 0x0fffffff;
    self->flags.bits.value = value;
    self->flags.bits.flag = 0;
    __construct_array(self->group, __ct__19soCollisionHitGroupFv,
                      __dt__19soCollisionHitGroupFv, 0x38, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, value, 1);
    return self;
}
