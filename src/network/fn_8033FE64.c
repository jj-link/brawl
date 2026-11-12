#include <types.h>
#pragma force_active on

extern u64 fn_803F1470(u64, u64);
extern void fn_80335638(int, const char *, ...);
extern char lbl_8048AA60[];
extern int lbl_805A0FA8;
extern int lbl_805A0F94;
extern int lbl_8059F0B0;
extern int lbl_8059F0B8;
extern int lbl_8059F0BC;
extern int lbl_8059F0C0;

s32 fn_8033FE64(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *base = lbl_8048AA60;
    s32 result = 0;
    u32 ticks;
    u32 divisor;
    s32 level;
    s32 ok;

    fn_80335638(0x200000, base + 0x5e8);
    ticks = *(u32 *)0x800000F8;
    divisor = (ticks >> 2) / 1000;
    level = (s32)(u32)fn_803F1470(
        *(u64 *)(lbl_805A0FA8 + 0x4c0),
        (u64)divisor
    );
    if (lbl_8059F0B0 != -1) {
        level = lbl_8059F0B0;
    } else {
        level = (level + 4999) / 5000;
        if (level > 10)
            level = 10;
    }

    if (lbl_805A0F94 == 0) {
        ok = 1;
    } else if (level == 0 || arg1 == 0) {
        ok = 0;
    } else {
        ok = __abs(level - arg1) <= 1;
    }

    if (!ok) {
        fn_80335638(0x200000, base + 0x5fc);
    } else if (arg0 <= lbl_8059F0B8) {
        fn_80335638(0x200000, base + 0x610);
        result = 1;
    } else if (lbl_8059F0BC <= arg0) {
        fn_80335638(0x200000, base + 0x624);
    } else if (arg2 == 1) {
        fn_80335638(0x200000, base + 0x638);
        result = 1;
    } else if (arg2 > 1 && arg0 <= arg3 + lbl_8059F0C0) {
        fn_80335638(0x200000, base + 0x64c);
        result = 1;
    } else {
        fn_80335638(0x200000, base + 0x660);
    }
    return result;
}