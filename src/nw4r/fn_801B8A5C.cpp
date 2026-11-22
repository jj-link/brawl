#include <revolution/OS/OSInterrupt.h>
#include <types.h>
#pragma force_active on

struct FnTarget {
    u8 pad0[0x1C];
    u32 flags;
    u8 pad1[0x9A - 0x20];
    u16 hi;
    u16 lo;
};

struct FnOwner {
    FnTarget* target;
    u8 pad0[0x14 - 0x04];
    s32 mode;
};

extern "C" void fn_801B8A5C(void* arg0, u32 arg1, u32 arg2) {
    FnOwner* self = (FnOwner*)arg0;
    arg0 = (void*)OSDisableInterrupts();
    if (self->target == NULL) {
        OSRestoreInterrupts((BOOL)arg0);
        return;
    }
    s32 mode = self->mode;
    if (arg1 != 0) {
        arg1 += 0x80000000;
    }
    u32 value = 0;
    switch (mode) {
    case 0:
        value = ((arg2 / 14) << 4) + (arg2 % 14) + (arg1 * 2) + 2;
        break;
    case 25:
        value = arg1 + arg2;
        break;
    case 10:
        value = (arg1 >> 1) + arg2;
        break;
    }
    BOOL inner = OSDisableInterrupts();
    if (self->target == NULL) {
        OSRestoreInterrupts(inner);
    } else {
        self->target->hi = (u16)(value >> 16);
        self->target->lo = (u16)value;
        if ((self->target->flags & 0x400) == 0) {
            self->target->flags |= 0x1000;
        }
        OSRestoreInterrupts(inner);
    }
    OSRestoreInterrupts((BOOL)arg0);
}