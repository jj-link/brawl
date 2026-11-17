#include <types.h>
#pragma force_active on
extern s32 lbl_27_rodata_4B48[];
extern "C" s32 fn_27_2A1064(void* self, s32 idx, s32 arg) {
    if (idx == -3) return idx;
    if (idx < 0 || idx >= 0xB2) return idx;
    s32 next = lbl_27_rodata_4B48[idx];
    if (next == -1) return idx;
    return fn_27_2A1064(self, next, 0);
}
