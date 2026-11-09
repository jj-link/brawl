#include <types.h>
#pragma force_active on

extern "C" {
extern char g_Network[];
extern int lbl_805A03E8;
extern int lbl_805A03F0;
extern s32 fn_800C9A4C(u32);
extern void fn_80146FCC(int);

s32 fn_800CC070(u8* arg0, s32* arg1) {
    *arg1 = 0;
    s32 v = *(s32*)(arg0 + 0x1048);
    if (v != 0) {
        return v;
    }
    if (g_Network == 0) {
        return 0;
    }
    s32 e = lbl_805A03E8;
    if (e == 0) {
        return 0;
    }
    if (e == 1) {
        s32 f = lbl_805A03F0;
        *arg1 = f;
        return fn_800C9A4C(f);
    }
    if (!((*(u8*)(arg0 + 0xfcb) >> 7) & 1)) {
        fn_80146FCC(10);
    }
    if (e == 7) {
        s32 f = lbl_805A03F0;
        *arg1 = f;
        return fn_800C9A4C(f);
    }
    switch (e) {
    case 2:
    case 3:
        return 13;
    case 8:
        return 9;
    case 4:
        return 10;
    case 5:
        return 10;
    case 6:
        return 13;
    case 9:
        return 11;
    case 10:
        return 12;
    case 11:
        return 11;
    case 12:
        return 11;
    case 13:
        return 11;
    case 14:
        return 13;
    }
    return 0;
}
}
