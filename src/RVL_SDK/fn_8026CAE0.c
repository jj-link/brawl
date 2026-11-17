#pragma force_active on
#pragma use_lmw_stmw on

#include <types.h>

extern f64 lbl_805A3AD8;
extern s32 fn_8026C7D4(void *self, s32 unused, void *arg);
extern s32 fn_8026C930(void *work, s32 count, s32 data, s32 interval);

typedef struct Work {
    u8 pad0[0x10];
    u32 unk10;
    u32 unk14;
    u32 unk18;
} Work;

s32 fn_8026CAE0(Work *self, s32 arg1, Work *work) {
    u32 r31;
    s32 r;
    u32 a, b, t, val;

    r31 = (u32)(0.9 * (f64)(u32)work->unk18);
    work->unk14 = 100;
    r = fn_8026C7D4(self, arg1, work);
    if (r >= 0) {
        r = fn_8026C930(self, r, arg1, 5);
        if (r < 0) return -2;
        a = self->unk10 * 5;
    } else {
        return -2;
    }

    if (a > r31) {
        work->unk14 = 50;
        r = fn_8026C7D4(self, arg1, work);
        if (r >= 0) {
            r = fn_8026C930(self, r, arg1, 5);
            if (r < 0) return -2;
            b = self->unk10 * 5;
        } else {
            return -2;
        }
        if (b > r31) {
            work->unk14 = 1;
            r = fn_8026C7D4(self, arg1, work);
            if (r >= 0) {
                r = fn_8026C930(self, r, arg1, 5);
                if (r < 0) return -2;
                t = self->unk10 * 5;
            } else {
                return -2;
            }
            if (t >= r31) {
                work->unk14 = 1;
            } else {
                val = (r31 - t) / ((b - t + 49) / 50);
                work->unk14 = val;
                if (val > 0x31) work->unk14 = 0x31;
            }
        } else {
            if (b == r31) {
                work->unk14 = 0x32;
            } else {
                val = (r31 - b) / ((a - b + 49) / 50);
                work->unk14 = val + 0x32;
                if (val + 0x32 > 0x63) work->unk14 = 0x63;
            }
        }
    } else {
        work->unk14 = 0xc8;
        r = fn_8026C7D4(self, arg1, work);
        if (r >= 0) {
            r = fn_8026C930(self, r, arg1, 5);
            if (r < 0) return -2;
            b = self->unk10 * 5;
        } else {
            return -2;
        }
        if (a == r31) {
            work->unk14 = 0x64;
        } else if (b > r31) {
            val = (r31 - a) / ((b - a + 99) / 100);
            work->unk14 = val + 0x64;
            if (val + 0x64 > 0xc7) work->unk14 = 0xc7;
        } else {
            work->unk14 = 0x1f4;
            r = fn_8026C7D4(self, arg1, work);
            if (r >= 0) {
                r = fn_8026C930(self, r, arg1, 5);
                if (r < 0) return -2;
                t = self->unk10 * 5;
            } else {
                return -2;
            }
            if (b == r31) {
                work->unk14 = 0xc8;
            } else if (t > r31) {
                val = (r31 - b) / ((t - b + 299) / 300);
                work->unk14 = val + 0xc8;
                if (val + 0xc8 > 0x1f3) work->unk14 = 0x1f3;
            } else {
                work->unk14 = 0x1f4;
            }
        }
    }

    t = work->unk14;
    if (t < 1) {
        work->unk14 = 1;
    } else if (t > 0x1f4) {
        work->unk14 = 0x1f4;
    }
    return work->unk14;
}
