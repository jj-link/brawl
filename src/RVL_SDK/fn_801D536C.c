#include <revolution/OS/OSHardware.h>
#pragma force_active on

extern void *lbl_805A0668;
int fn_801DE374(void);

int fn_801D536C(void) {
    int mode;
    int t;

    if (lbl_805A0668 == 0 || *(int *)((unsigned char *)lbl_805A0668 + 0x2C) == 0) {
        return 0x10000002;
    }
    mode = OS_HOLLYWOOD_REV;
    if (OS_DVD_DEVICE_CODE & 0x8000) {
        switch (OS_DVD_DEVICE_CODE & 0xFFFF7FFF) {
        case 0x203:
        case 2:
        case 3:
            goto group1;
        case 0x201:
        case 0x202:
            goto group2;
        case 0x300:
            goto ret100;
        }
        goto default_path;
    }
    goto default_path;

group1:
    switch (mode) {
    case 0: return 0x10;
    case 1: return 0x11;
    case 2: return 0x12;
    case 16: return 0x20;
    case 17: return 0x21;
    }
    if ((unsigned int)mode <= 0x11) goto group2;
    return 0x21;

group2:
    switch (mode) {
    case 0: return 0x10000010;
    case 1: return 0x10000011;
    case 2: return 0x10000012;
    case 16: return 0x10000020;
    case 17: return 0x10000021;
    }
    if ((unsigned int)mode <= 0x11) goto ret100;
    return 0x10000021;

ret100:
    return 0x100;

default_path:
    t = fn_801DE374();
    switch (mode) {
    case 0:
        if ((unsigned int)t == 0x04000000) return 0x10;
        return 0x10000010;
    case 1:
        if ((unsigned int)t == 0x04000000) return 0x11;
        return 0x10000011;
    case 2:
        if ((unsigned int)t == 0x04000000) return 0x12;
        return 0x10000012;
    case 16:
        if ((unsigned int)t == 0x04000000) return 0x20;
        return 0x10000020;
    case 17:
        if ((unsigned int)t == 0x04000000) return 0x21;
        return 0x10000021;
    }
    if ((unsigned int)mode > 0x11) {
        if ((unsigned int)t == 0x04000000) return 0x21;
        return 0x10000021;
    }
    return *(int *)((unsigned char *)lbl_805A0668 + 0x2C);
}