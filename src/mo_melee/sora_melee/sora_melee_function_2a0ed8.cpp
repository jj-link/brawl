#include <types.h>
#pragma force_active on
extern "C" {
extern s32 lbl_27_rodata_47C8[];
extern u8 lbl_27_rodata_4A90[];
extern s32 lbl_27_rodata_4B48[];
void fn_27_2A1064(void*, s32, s32);
u8 fn_27_2A0ED8(void* self, s32 idx, s32 arg) {
    if (idx < 0 || idx >= 0xB2) return 0;
    s32 valid = 0;
    if (idx > -1 && idx < 0xB2) valid = 1;
    s32 value;
    if (valid == 0) value = 0;
    else {
        s32 v = lbl_27_rodata_47C8[idx];
        value = v < 0 ? -v : v;
    }
    if (value > 0 && (idx == 15 || idx == 7 || idx == 3 || idx == 10 || idx == 20 || idx == 143))
        return lbl_27_rodata_4A90[idx] + arg;
    if (idx != -3 && idx >= 0 && idx < 0xB2) {
        s32 a = lbl_27_rodata_4B48[idx];
        if (a != -1 && a != -3 && a >= 0 && a < 0xB2) {
            s32 b = lbl_27_rodata_4B48[a];
            if (b != -1 && b != -3 && b >= 0 && b < 0xB2) {
                s32 c = lbl_27_rodata_4B48[b];
                if (c != -1 && c != -3 && c >= 0 && c < 0xB2) {
                    s32 d = lbl_27_rodata_4B48[c];
                    if (d != -1) fn_27_2A1064(self, d, 0);
                }
            }
        }
    }
    return lbl_27_rodata_4A90[idx];
}
}