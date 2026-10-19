#include <types.h>
#pragma force_active on

struct Sub {
    u8 pad[0x71];
    u8 flags;
};

struct Ret {
    u8 pad[0x4];
    Sub* sub;
};

struct Base {
    virtual Ret* vfn0();
    virtual Ret* vfn1();
    virtual Ret* vfn2();
    virtual Ret* vfn3();
};

struct Holder {
    u8 pad[0x28];
    Base* base;
};

extern "C" u32 fn_27_27430(const Holder* self) {
    Ret* ret = self->base->vfn1();
    return (ret->sub->flags >> 4) & 1;
}
