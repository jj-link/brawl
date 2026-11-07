#include <revolution/types.h>
#pragma force_active on

extern s32 fn_803C374C(s32, u8 *, s32);
extern s32 fn_803C3F44(void);
extern s32 fn_803C3F48(const char *);
extern u8 lbl_8059FCC0;
extern u8 lbl_8059FCC4;
extern char lbl_8059FCC8[4];
extern s32 lbl_805A115C;

s32 fn_80398558(void *arg0, s32 arg1, s32 arg2) {
    s32 r;
    s32 r2;
    u8 *name;

    switch (arg2) {
    case 0x109:
    case 0x101:
        name = &lbl_8059FCC0;
        break;
    case 0x10A:
    case 0x102:
        name = &lbl_8059FCC4;
        break;
    default:
        return -3;
    }

    r = fn_803C374C(arg1, name, 0);
    *(s32 *)((u8 *)arg0 + 0x98) = r;
    if (r == 0) {
        r2 = fn_803C3F44();
        if ((u32)arg2 == 0x109U) {
            lbl_805A115C = 0;
        }

        if ((s32)*name == 0x72 && r2 == 2) {
            return -0x14;
        }

        if (r2 == 5) {
            switch (fn_803C3F48(lbl_8059FCC8)) {
            case -5:
            case -15:
                return -0x2E;
            case -4:
                return -0x26;
            default:
                return -0x10;
            }
        }
        return -0x10;
    }
    return 0;
}
