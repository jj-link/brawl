#include <types.h>
#pragma force_active on

extern "C" {
u32 OSDisableInterrupts(void);
void OSRestoreInterrupts(u32);
void* fn_801B77F8(void);
u32 fn_801B7EE0(void);
}

struct Inner {
    char pad0[0x1C];
    u32 flags;
    char pad1[0x96 - 0x20];
    s16 f96;
    s16 f98;
    s16 f9a;
    s16 f9c;
    s16 f9e;
    s16 fa0;
};

struct Obj {
    Inner* inner;
    char pad[0x14 - 4];
    s32 mode;
};

extern "C" void fn_801B8D48(void* arg0, u32 a, u32 b) {
    u32 v1;
    Obj* self = (Obj*)arg0;
    arg0 = (void*)OSDisableInterrupts();

    if (!self->inner) {
        OSRestoreInterrupts((u32)arg0);
        return;
    }

    fn_801B77F8();
    u32 x = fn_801B7EE0();
    s32 mode = self->mode;

    if (x) {
        x += 0x80000000;
    }

    v1 = 0;
    switch (mode) {
    case 0:
        v1 = x * 2 + 2;
        break;
    case 25:
        v1 = x;
        break;
    case 10:
        v1 = x >> 1;
        break;
    }

    if (a) {
        a += 0x80000000;
    }

    u32 v2 = 0;
    switch (mode) {
    case 0: {
        u32 t = b - 1;
        v2 = t % 14 + a * 2 + (t / 14) * 16 + 2;
        break;
    }
    case 25:
        v2 = a + b - 1;
        break;
    case 10:
        v2 = b + (a >> 1) - 1;
        break;
    }

    u32 s1 = OSDisableInterrupts();
    if (!self->inner) {
        OSRestoreInterrupts(s1);
    } else {
        self->inner->f9a = (s16)(v1 >> 16);
        self->inner->f9c = (s16)v1;
        if (!(self->inner->flags & 0x400)) {
            self->inner->flags |= 0x1000;
        }
        OSRestoreInterrupts(s1);
    }

    u32 s2 = OSDisableInterrupts();
    if (!self->inner) {
        OSRestoreInterrupts(s2);
    } else {
        self->inner->f9e = (s16)(v2 >> 16);
        self->inner->fa0 = (s16)v2;
        if (!(self->inner->flags & 0x400)) {
            self->inner->flags |= 0x2000;
        }
        OSRestoreInterrupts(s2);
    }

    u32 s3 = OSDisableInterrupts();
    if (!self->inner) {
        OSRestoreInterrupts(s3);
    } else {
        self->inner->f96 = 0;
        if (!(self->inner->flags & 0x400)) {
            self->inner->flags |= 0x800;
        }
        OSRestoreInterrupts(s3);
    }

    OSRestoreInterrupts((u32)arg0);
}
