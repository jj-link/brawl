#include <types.h>
#pragma force_active on

extern "C" f32 lbl_805A3150;
extern "C" f32 lbl_805A3154;

struct Entry {
    f32 val;
    u16 idx;
};

extern "C" u16 fn_8018B110(Entry* base, u32 count, f32 val) {
    if (count == 1 || val <= base[0].val) {
        return base[0].idx;
    }
    if (val >= base[count - 1].val) {
        return base[count - 1].idx;
    }
    s32 lo = 0;
    s32 hi = (s32)count - 1;
    while (lo != hi - 1 && lo != hi) {
        s32 mid = (lo + hi) / 2;
        if (val < base[mid].val) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    f32 diff = val - base[hi].val;
    u32 found = 0;
    if (lbl_805A3150 < diff && diff < lbl_805A3154) {
        found = 1;
    }
    if (found) {
        return base[hi].idx;
    }
    return base[lo].idx;
}