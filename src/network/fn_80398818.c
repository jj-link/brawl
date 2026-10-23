#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef long long s64;

extern void OSSleepTicks(s64);
extern s32 fn_8020AC38(void *, s32, s32);
extern s32 fn_803C3894(s32, s32, s32);
extern s32 fn_803C3F48(const char *);
extern char lbl_8059FCC8[4];

s32 fn_80398818(void *arg0, u32 arg1, u32 arg2) {
    s32 r;
    s32 ret;
    u32 i;
    u32 r5;
    u32 r6;
    u32 v;
    u32 rot;
    u32 diff;
    char *base;

    base = (char *)arg0;
    if ((u32)((s32 *)base)[1] == 0xA || (u32)((s32 *)base)[1] == 0x10A) {
        r5 = arg1 << 27;
        r6 = arg1 >> 31;
        r5 = r5 - r6;
        rot = (r5 << 5) | (r5 >> 27);
        v = rot + r6;
        ((s32 *)base)[2] = v;
        diff = arg1 - v;
        if (((s32 *)base)[1] & 0x100) {
            r = fn_803C3894(((s32 *)base)[38], diff, arg2);
            if (r != 0) {
                if (r == 5) {
                    switch (fn_803C3F48(lbl_8059FCC8)) {
                    case -5:
                    case -15:
                        return -0x2E;
                    case -4:
                        return -0x26;
                    default:
                        return -0x15;
                    }
                }
                return -0x15;
            }
            return 0;
        } else {
            r = fn_8020AC38(base + 0xc, diff, arg2);
            ret = 0;
            if (r < 0) {
                ret = -0x15;
            }
            return ret;
        }
    } else if (((s32 *)base)[1] & 0x100) {
        r = fn_803C3894(((s32 *)base)[38], arg1, arg2);
        if (r != 0) {
            if (r == 5) {
                switch (fn_803C3F48(lbl_8059FCC8)) {
                case -5:
                case -15:
                    return -0x2E;
                case -4:
                    return -0x26;
                default:
                    return -0x15;
                }
            }
            return -0x15;
        }
        return 0;
    } else {
        i = 0;
        do {
            r = fn_8020AC38(base + 0xc, arg1, arg2);
            if ((u32)(r + 3) > 1) {
                break;
            }
            OSSleepTicks(1000 * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
            i++;
        } while (i < 3);
        if (r < 0) {
            return -0x15;
        }
        return 0;
    }
}
