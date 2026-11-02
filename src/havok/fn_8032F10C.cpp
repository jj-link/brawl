#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern "C" s32 fn_80281AEC(s32, s32);

typedef s32 (*CmpFn)(s32, s32);

struct Self {
    u8 pad0[0xc];
    s32** data;
    s32 count;
};

extern "C" s16 fn_8032F10C(const Self* self, s32 arg1, CmpFn arg2) {
    s32 count = self->count;
    if (arg2 == 0) {
        arg2 = fn_80281AEC;
    }
    for (s16 i = 0; i < count; ++i) {
        if (arg2(arg1, *self->data[i]) == 0) {
            return i;
        }
    }
    return -1;
}
