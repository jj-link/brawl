#include <revolution/os.h>
#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad0[0x1C];
    u32 flags1C;
    u8 pad1[0x9E - 0x20];
    u16 hi9E;
    u16 lo9A0;
};

struct Outer {
    Inner* inner;
    u8 pad[0x14 - 4];
    s32 kind;
};

extern "C" void fn_801B8B80(void* arg0, u32 arg1, u32 arg2) {
    Outer* self = (Outer*)arg0;
    arg0 = (void*)OSDisableInterrupts();
    if (!self->inner) {
        OSRestoreInterrupts((BOOL)arg0);
        return;
    }
    s32 kind = self->kind;
    if (arg1 != 0) {
        arg1 += 0x80000000;
    }
    u32 var_r29 = 0;
    switch (kind) {
    case 0:
        u32 x = arg2 - 1;
        u32 row = x / 14;
        var_r29 = (x % 14) + row * 16 + arg1 * 2 + 2;
        break;
    case 25:
        var_r29 = arg1 + arg2 - 1;
        break;
    case 10:
        var_r29 = arg2 + (arg1 >> 1) - 1;
        break;
    }
    BOOL enabled2 = OSDisableInterrupts();
    if (!self->inner) {
        OSRestoreInterrupts(enabled2);
    } else {
        self->inner->hi9E = (u16)(var_r29 >> 16);
        self->inner->lo9A0 = (u16)var_r29;
        if (!(self->inner->flags1C & 0x400)) {
            self->inner->flags1C |= 0x2000;
        }
        OSRestoreInterrupts(enabled2);
    }
    OSRestoreInterrupts((BOOL)arg0);
}
