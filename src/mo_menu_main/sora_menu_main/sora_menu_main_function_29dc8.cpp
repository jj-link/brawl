#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

struct Inner {
    char pad0[0x8C];
    s32 count;
};

struct Self {
    char pad0[0x67C];
    MuObject* node;
    char pad1[0x14];
    s32 f694;
    s32 f698;
    char pad2[0x4];
    s32 mode;
    Inner* inner;
};

extern "C" void fn_2_29DC8(void* p, s32 flag) {
    Self* s = (Self*)p;
    s32 value;
    s32 mode;
    s32 flags = 0;

    if (flag != 0) {
        if (!s->mode) {
            s32 d = s->f694;
            if (d < s->inner->count - 1) flags |= 2;
            if (d > 0) flags |= 1;
        } else {
            s32 r = s->f698;
            if (r + 7 < 0x18) flags |= 2;
            if (r > 0) flags |= 1;
        }
        mode = ((Self*)p)->mode;
    } else {
        mode = 2;
    }

    if (mode != 2) {
        value = 0;
        if (flags & 1) value |= 2;
        if (flags & 2) value |= 1;
        if (mode == 1) value += 4;
    } else {
        value = 8;
    }

    s->node->setFrameVisible((f32)value);
}
