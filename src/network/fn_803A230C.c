#include <types.h>
#pragma force_active on
extern s64 fn_801E1B54(void);
extern u32 fn_8020E18C(void);
extern s32 fn_8020FDA8(void);
extern s64 OSGetTime(void);
extern s64 fn_803F1470(s64, s64);
extern s32 fn_803A244C(s64 *);
extern u32 lbl_805A11AC;
extern s64 lbl_805A11B0;
extern s64 lbl_805A11B8;

s32 fn_803A230C(s64 *out) {
    s32 result;
    u32 val;
    u32 time;
    s64 os_time;
    u32 tick;
    if (out == 0) {
        lbl_805A11B0 = 0;
        return -3;
    }
    if (lbl_805A11B8 == 0 || fn_801E1B54() >= lbl_805A11B8 + (*(u32 *)0x800000F8 >> 2) || lbl_805A11AC == 0) {
        result = fn_803A244C(&lbl_805A11B0);
        if (result < 0) return result;
        while (1) {
            val = fn_8020E18C();
            if (val == 2) {
                result = -1;
                break;
            }
            if (val != 0) continue;
            time = (u32)fn_8020FDA8();
            os_time = OSGetTime();
            tick = *(u32 *)0x800000F8;
            lbl_805A11AC = (u32)(fn_803F1470(os_time, (s64)(tick >> 2)) - (u64)time);
            result = 0;
            break;
        }
        if (result != 0) return result;
        lbl_805A11B8 = fn_801E1B54();
    }
    *out = lbl_805A11B0 + lbl_805A11AC;
    return 0;
}