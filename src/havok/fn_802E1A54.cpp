#include <types.h>
#pragma force_active on

extern "C" void fn_802FAC88(void*, void*);

struct Flag {
    s8 value;

    Flag(bool b) : value(b) {}

    operator s8() const {
        return value;
    }
};

struct Obj {
    u8 pad0[8];
    void* f8;
    u8 pad1[0x4C];
    u8* f58;
    u8 pad2[0x4C];
    u8 fA8;

    s32 state() const {
        if (f58 == 0)
            return 0;
        return (f58[0x27] >> 6) & 3;
    }

    Flag is7() const {
        return fA8 == 7;
    }
};

extern "C" void fn_802E1A54(Obj* self) {
    s8 st = (u8)self->state();
    int r5 = 0, r6 = 0;

    if (st == 0) {
        s8 is = self->is7();
        if (is == 0)
            r6 = 1;
    }

    if (r6 && self->f8 != 0)
        r5 = 1;

    if (r5 == 0)
        return;

    fn_802FAC88(self->f8, self->f58);
}
