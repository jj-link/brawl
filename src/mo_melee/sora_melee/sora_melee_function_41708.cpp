#include <types.h>
#pragma force_active on

struct Inner {
    u32 unk0;
    u32 flag;
};

struct Sub {
    virtual void v0();
    virtual Inner* get(u32 index);
};

struct Outer {
    u8 pad[0x28];
    Sub sub;
};

extern "C" void fn_27_41708(Outer* self, u32 mode) {
    if (mode == 1) {
        Inner* p = self->sub.get(0);
        p->flag |= 0x40;
    } else {
        Inner* p = self->sub.get(0);
        p->flag &= ~0x40;
    }
}
