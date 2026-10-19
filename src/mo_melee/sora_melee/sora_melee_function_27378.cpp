#include <types.h>
#pragma force_active on

struct SubObj {
    u8 pad[0x55];
    u8 flag;
};

struct RetObj {
    u8 pad0[4];
    SubObj* sub;
};

struct MidObj {
    virtual void f0();
    virtual RetObj* f1(u32 v);
};

struct Owner {
    u8 pad0[0x28];
    MidObj* mid;
};

extern "C" void fn_27_27378(Owner* self, u8 a, u32 b) {
    RetObj* r = self->mid->f1(b);
    r->sub->flag = a;
}
