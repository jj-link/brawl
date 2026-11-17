#include <types.h>
#pragma force_active on

extern "C" f32 lbl_805A3150;
extern "C" f32 lbl_805A3154;
extern "C" f32 lbl_805A3158;
extern "C" f32 lbl_805A315C;
extern "C" f32 lbl_805A3160;
extern "C" f32 lbl_805A3164;

struct Entry {
    f32 val;
    f32 a;
    f32 b;
};

extern "C" f32 fn_8018B1F8(Entry* base, u32 count, f32 val) {
    if (count == 1 || val <= base[0].val) {
        return base[0].a;
    }
    if (val >= base[count - 1].val) {
        return base[count - 1].a;
    }
    s32 lo = 0;
    s32 hi = (s32)count - 1;
    while (lo != hi - 1 && lo != hi) {
        s32 mid = (lo + hi) / 2;
        if (val <= base[mid].val) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    Entry* ehi = base + hi;
    f32 diff = val - ehi->val;
    Entry* elo = base + lo;
    u32 found = 0;
    if (lbl_805A3150 < diff && diff < lbl_805A3154) {
        found = 1;
    }
    if (found) {
        if ((u32)hi < count - 1) {
            u32 next = hi + 1;
            if (ehi->val == base[next].val) {
                return base[next].a;
            }
        }
        return ehi->a;
    }
    f32 t1 = val - elo->val;
    f32 t2 = lbl_805A3158 / (ehi->val - elo->val);
    f32 v0 = elo->a;
    f32 v1 = ehi->a;
    f32 s0 = elo->b;
    f32 s1 = ehi->b;
    f32 t1t1t2 = t1 * t1 * t2;
    f32 t1t1t2t2 = t1t1t2 * t2;
    f32 t1t1t1t2t2 = t1 * t1t1t2t2;
    f32 t1t1t1t2t2t2 = t1t1t1t2t2 * t2;
    return s1 * (t1t1t1t2t2 - t1t1t2) +
           (s0 * (t1 + (t1t1t1t2t2 - lbl_805A315C * t1t1t2)) +
            (v0 * (lbl_805A3158 + (lbl_805A315C * t1t1t1t2t2t2 - lbl_805A3160 * t1t1t2t2)) +
             v1 * (lbl_805A3164 * t1t1t1t2t2t2 + lbl_805A3160 * t1t1t2t2)));
}
