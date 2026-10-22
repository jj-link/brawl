#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_5FDE8[];
void __ct__19soCollisionHitGroupFv(void*);
void __dt__19soCollisionHitGroupFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
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
    void* vt;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_291AC0(Obj* self, unsigned int value) {
    self->vt = lbl_27_data_5FDE8;
    self->calc = lbl_27_data_5FDE8 + 0x48;
    Flags f;
    f.raw = self->flags.raw;
    f.bits.pad = 0;
    f.bits.value = value;
    f.bits.flag = 0;
    self->flags = f;
    __construct_array((char*)self + 0xc, __ct__19soCollisionHitGroupFv, (void (*)(void*))__dt__19soCollisionHitGroupFv, 0x38, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell((char*)self + 4, value, 3);
    return self;
}
