#include <types.h>
#pragma force_active on

typedef struct Self {
    char pad0[0x4c];
    u32 f4c;
    char pad50[0x14];
    s32 f64;
    char pad68[0x10];
    u32 arr[8];
    char pad98[0x31];
    u8 count;
} Self;

extern s32 fn_8039C05C(s32, s32);

static inline u32 elemSize(u32 x) {
    return (x * 4 + 2) / 3 + (x / 57) * 2 + 4;
}

s32 fn_8039EA6C(Self *self, s32 arg1) {
    u32 total = 0;
    s32 i;
    u32 val;
    s32 r;

    for (i = 0; i < self->count; i++) {
        total = total + (self->arr[i] * 4 + 2) / 3 + (self->arr[i] / 57) * 2 + 4;
    }

    switch (self->f64) {
    case 0:
    case 1:
        val = self->f4c;
        break;
    case 2:
        val = elemSize(self->f4c);
        break;
    case 3:
        val = (self->f4c * 4) / 3;
        break;
    default:
        val = 0;
        break;
    }

    total += val;
    if (total >= 0x31C00) {
        return -8;
    }
    r = fn_8039C05C(arg1, total + 0x400);
    {
        s32 ret = 0;
        if (r != 0) {
            ret = r;
        }
        return ret;
    }
}
