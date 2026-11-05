#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef long long s64;

extern void OSSleepTicks(s64);
extern s32 fn_8020A784(void *, s32, s32);
extern s32 fn_8020BA48(void *, void *, s32);
extern s32 lbl_805A115C;

s32 fn_80398420(char *arg0, void *arg1, u32 arg2) {
    s32 mode;
    s32 r;
    u32 i;

    switch (arg2) {
    case 1:
    case 9:
        r = fn_8020A784(arg1, 0x3f, 0);
        if (r != 0 && r != -6) {
            return -0x15;
        }
        mode = 2;
        break;
    case 2:
    case 10:
        mode = 1;
        break;
    case 4:
        mode = 3;
        break;
    case 0:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        return -3;
    }

    i = 0;
    do {
        r = fn_8020BA48(arg1, arg0 + 0xc, mode);
        if ((u32)(r + 3) > 1) {
            break;
        }
        OSSleepTicks(1000 * (s64)((*(u32 *)0x800000F8 / 4) / 1000));
        i++;
    } while (i < 3);

    if (r != 0) {
        if (arg2 == 9) {
            lbl_805A115C = 0;
        }
        if (r == -0xc) {
            return -0x14;
        }
        return -0x10;
    }
    return 0;
}
