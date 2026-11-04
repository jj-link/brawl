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
    virtual void v0();
    virtual clTarget* v1(int);
};
union Flags {
    u32 raw;
    struct { u32 pad : 8; u32 value : 4; u32 flag : 1; u32 rest : 19; } bits;
};
struct Obj {
    char pad[0x28];
    void* vt;
    void* calc;
    Flags flags;
    char targets[0x30];
};
extern "C" void* __ct__18soCollisionHitPartFQ211soCollision8CategoryUl(Obj* self, soCollision::Category category, unsigned long arg) {
    self->calc = lbl_27_data_3AD8 + 0x48;
    self->vt = lbl_27_data_3AD8;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = 6;
    self->flags.bits.flag = 0;
    __construct_array(self->targets, (void (*)(void*))__ct__8clTargetFv,
                      (void (*)(void*))__dt__8clTargetFv, 8, 6);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc, 6, 6);
    clTarget* p = ((Holder*)&self->vt)->v1(0);
    p->m_0 = 2;
    p = ((Holder*)&self->vt)->v1(1);
    p->m_0 = 1 << category;
    p = ((Holder*)&self->vt)->v1(2);
    p->m_0 = 0;
    p = ((Holder*)&self->vt)->v1(3);
    p->m_0 = 0;
    p = ((Holder*)&self->vt)->v1(4);
    p->m_0 = 0;
    p = ((Holder*)&self->vt)->v1(1);
    p->m_4 = arg;
    return self;
}