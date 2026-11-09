#include <types.h>

#pragma force_active on

extern u8 lbl_8059E742;
extern u8* lbl_805A0390;
extern const f32 lbl_805A2AC8;
extern const f32 lbl_805A2ACC;
extern const f32 lbl_805A2B40;
extern const f32 lbl_805A2B44;
extern const f32 lbl_805A2B48;

struct Ent {
    s8 active;
    u8 pad[0x1b];
    u16 current;
    u16 previous;
};

struct Self {
    u8 pad[0x1f8];
    f32 value;
    f32 smoothed;
};

static inline f32 clamp(f32 v, f32 lo, f32 hi) {
    if (v < lo)
        v = lo;
    if (v > hi)
        v = hi;
    return v;
}

extern "C" f32 fn_80143974(Self* self) {
    f32 sum = lbl_805A2AC8;
    f32 count = lbl_805A2AC8;
    u16 current;
    Ent* e = (Ent*)(lbl_805A0390 + 0xb0);
    u8 i = 0;

    for (; i < 4; ++i, ++e) {
        if (i != lbl_8059E742 && e->active != 0) {
            current = e->current;
            int diff = current - e->previous;
            e->previous = current;
            f32 v = clamp((f32)diff, lbl_805A2AC8, lbl_805A2B40);
            count += lbl_805A2ACC;
            sum += v;
        }
    }

    if (count > lbl_805A2AC8)
        sum /= count;

    self->value = sum;
    if (lbl_805A2AC8 == self->smoothed)
        self->smoothed = (f32)(f64)sum;
    else
        self->smoothed = (lbl_805A2B44 * self->smoothed) / lbl_805A2B48 +
                         (f32)(f64)sum / lbl_805A2B48;
    return sum;
}
