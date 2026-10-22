#pragma force_active on
#include <types.h>

extern s32 fn_8020E18C(void);
extern s32 fn_8020FDA8(void);
extern s64 OSGetTime(void);
extern s64 fn_803F1470(s64, s64);
extern s32 fn_803A25C0(s32, s32);

s32 fn_803A2708(s32 arg0) {
    unsigned int time;
    s32 result;
    unsigned int val;
    s64 os_time;
    u32 tick;

    while (1) {
        val = fn_8020E18C();
        if (val == 2) {
            result = -1;
            break;
        }
        if (val != 0) continue;
        time = (u32)fn_8020FDA8();
        os_time = OSGetTime();
        tick = *(u32*)0x800000F8;
        time = (s32)(fn_803F1470(os_time, (s64)(tick >> 2)) - (u64)time);
        result = 0;
        break;
    }
    if (result != 0) return result;
    return fn_803A25C0((s32)time, arg0 != 0);
}