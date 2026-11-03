#include <revolution/OS/OSInterrupt.h>
#include <stl/internal/mem.h>
#pragma force_active on

struct Obj {
    s8 a;
    s8 b;
    s8 pad[2];
    void *ptr;
    s32 count;
};

struct Entry {
    s32 f[12];
};

s32 fn_8021DC5C(struct Obj *o, u32 kind, s32 n, s32 extra)
{
    struct Entry src;
    struct Entry entry;
    s32 idx;
    s32 prevA;

    src.f[0] = 0x12;
    ((s16 *)&src.f[6])[1] = 2;
    ((s8 *)&src.f[1])[0] = (s8)(n ? 0 : 4);
    src.f[11] = extra;

    switch (kind) {
    case 0:
        ((s8 *)&src.f[1])[1] = 0x30;
        break;
    case 1:
        ((s8 *)&src.f[1])[1] = 0x31;
        break;
    case 2:
        ((s8 *)&src.f[1])[1] = 0x33;
        break;
    case 3:
        ((s8 *)&src.f[1])[1] = 0x32;
        break;
    case 4:
        ((s8 *)&src.f[1])[1] = 0x35;
        break;
    case 5:
        ((s8 *)&src.f[1])[1] = 0x37;
        break;
    case 6:
        ((s8 *)&src.f[1])[1] = 0x32;
        break;
    case 7:
        ((s8 *)&src.f[1])[1] = 0x35;
        break;
    case 8:
        ((s8 *)&src.f[1])[1] = 0x37;
        break;
    case 9:
        ((s8 *)&src.f[1])[1] = 0x3e;
        break;
    }

    entry = src;
    prevA = OSDisableInterrupts();

    {
        s32 prevB = OSDisableInterrupts();

        idx = (s8)(o->b - o->a);
        if ((s8)idx < 0) {
            idx = (s8)(idx + o->count);
        }
        OSRestoreInterrupts(prevB);
    }

    if ((u32)(o->count - 1) == (u32)(s8)idx) {
        OSRestoreInterrupts(prevA);
        return 0;
    }

    memset((u8 *)o->ptr + ((s8)o->b * 0x30), 0, 0x30);
    memcpy((u8 *)o->ptr + ((s8)o->b * 0x30), &entry, 0x30);

    {
        s8 b = o->b;
        s32 t = o->count - 1;
        o->b = (u8)((b == t) ? 0 : b + 1);
    }

    OSRestoreInterrupts(prevA);
    return 1;
}
