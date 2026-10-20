#include <types.h>
#pragma force_active on

struct VObj {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
};

struct L2 {
    char pad[0xc];
    VObj* o;
};

struct L1 {
    char pad[0xd8];
    L2* q;
};

struct L0 {
    char pad[0x60];
    L1* p;
};

extern "C" void* fn_27_1DB33C(L0* self) {
    return self->p->q->o->v5();
}
