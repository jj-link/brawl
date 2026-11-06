#include <so/collision/so_collision.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_3AD8[];
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, long, long);
}

class Holder {
public:
    virtual void slot0();
    virtual clTarget* slot1(int);
};

union Flags {
    u32 raw;
    struct { u32 pad : 8; u32 value : 4; u32 flag : 1; u32 rest : 19; } bits;
};

struct Obj {
    char pad[0x20];
    void* vt;
    void* calc;
    Flags flags;
    char targets[0x30];
};

extern "C" void* fn_27_46588(Obj* self, int a1, int a2) {
    self->calc = lbl_27_data_3AD8 + 0x48;
    self->vt = lbl_27_data_3AD8;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = 6;
    self->flags.bits.flag = 0;
    __construct_array(self->targets, (void (*)(void*))__ct__8clTargetFv,
                      (void (*)(void*))__dt__8clTargetFv, 8, 6);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, 6, 6);
    clTarget* p = ((Holder*)&self->vt)->slot1(0);
    p->m_0 = 1 << a2;
    p = ((Holder*)&self->vt)->slot1(1);
    p->m_0 = 1 << a1;
    p = ((Holder*)&self->vt)->slot1(0);
    if (p->m_0 & 8) {
        p = ((Holder*)&self->vt)->slot1(5);
        p->m_4 = 2;
    } else {
        p = ((Holder*)&self->vt)->slot1(0);
        if (p->m_0 & 0x10) {
            p = ((Holder*)&self->vt)->slot1(5);
            p->m_4 = 4;
        }
    }
    return self;
}
