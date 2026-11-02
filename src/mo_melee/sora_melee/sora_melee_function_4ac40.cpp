#pragma force_active on
#include <types.h>

extern "C" {
extern char lbl_27_data_3AD8[];
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

class Holder {
public:
    virtual void v0();
    virtual u32* v1(int);
};

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
    void* unk0;
    char pad4[0x18];
    void* vt;
    void* calc;
    Flags flags;
    char targets[0x30];
};

extern "C" void* fn_27_4AC40(Obj* self, int arg1) {
    self->unk0 = 0;
    self->calc = lbl_27_data_3AD8 + 0x48;
    self->vt = lbl_27_data_3AD8;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = 6;
    self->flags.bits.flag = 0;
    __construct_array(self->targets, (void (*)(void*))__ct__8clTargetFv,
                      (void (*)(void*))__dt__8clTargetFv, 8, 6);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, 6, 6);
    u32* p = ((Holder*)&self->vt)->v1(0);
    *p = 0x40;
    u32* q = ((Holder*)&self->vt)->v1(1);
    *q = 1 << arg1;
    return self;
}
