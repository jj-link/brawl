#include <string.h>
#pragma force_active on

extern int lbl_805A0B38;
extern int lbl_805A0B28;

#define U16(p, o) (*(unsigned short *)((p) + (o)))
#define S16(p, o) (*(short *)((p) + (o)))
#define U32(p, o) (*(unsigned int *)((p) + (o)))
#define S32(p, o) (*(int *)((p) + (o)))

void fn_80201690(char *arg0)
{
    char *r31;
    char *r30;
    char *r3;
    unsigned int flags;

    r30 = arg0 + 0x28;
    lbl_805A0B38 = lbl_805A0B38 + 1;
    flags = U32(arg0, 0x1C);
    r31 = (char *)lbl_805A0B28 + S32(arg0, 0x18) * 0x140;
    if (flags == 0) {
        U16(r30, 0x10) = U16(r31, 0x10);
        U16(r30, 0x6A) = U16(r31, 0x6A);
        U16(r30, 0x7A) = U16(r31, 0x7A);
        U16(r30, 0x7C) = U16(r31, 0x7C);
        return;
    }
    if (flags & 0x80000000) {
        memcpy(r31, r30, 0x140);
        return;
    }
    if (flags & 1) {
        U16(r31, 0x8) = U16(r30, 0x8);
        U16(r31, 0xA) = U16(r30, 0xA);
    }
    if (flags & 2) {
        U32(r31, 0xC) = U32(r30, 0xC);
    }
    if (flags & 4) {
        U16(r31, 0x10) = U16(r30, 0x10);
    } else {
        U16(r30, 0x10) = U16(r31, 0x10);
    }
    if (flags & 8) {
        U16(r31, 0x12) = U16(r30, 0x12);
    }
    if (flags & 0x10) {
        memcpy(r31 + 0x14, r30 + 0x14, 0x30);
    }
    if (flags & 0x40) {
        U16(r31, 0x4E) = U16(r30, 0x4E);
        U16(r31, 0x50) = U16(r30, 0x50);
    } else if (flags & 0x20) {
        U16(r31, 0x44) = U16(r30, 0x44);
        U16(r31, 0x46) = U16(r30, 0x46);
        U16(r31, 0x48) = U16(r30, 0x48);
        U16(r31, 0x4A) = U16(r30, 0x4A);
        U16(r31, 0x4C) = U16(r30, 0x4C);
        U16(r31, 0x4E) = U16(r30, 0x4E);
        U16(r31, 0x50) = U16(r30, 0x50);
        r3 = *(char **)(arg0 + 0x24);
        S32(r3, 0x00) = 0;
        S32(r3, 0x04) = 0;
        S32(r3, 0x08) = 0;
        S32(r3, 0x0C) = 0;
        S32(r3, 0x10) = 0;
        S32(r3, 0x14) = 0;
        S32(r3, 0x18) = 0;
        S32(r3, 0x1C) = 0;
        S32(r3, 0x20) = 0;
        S32(r3, 0x24) = 0;
        S32(r3, 0x28) = 0;
        S32(r3, 0x2C) = 0;
        S32(r3, 0x30) = 0;
        S32(r3, 0x34) = 0;
        S32(r3, 0x38) = 0;
        S32(r3, 0x3C) = 0;
    }
    if (flags & 0x80) {
        memcpy(r31 + 0x52, r30 + 0x52, 0x18);
    }
    if (flags & 0x200) {
        U16(r30, 0x6A) = U16(r31, 0x6A);
        S16(r31, 0x6C) = S16(r30, 0x6C);
    } else if (flags & 0x100) {
        U16(r31, 0x6A) = U16(r30, 0x6A);
        S16(r31, 0x6C) = S16(r30, 0x6C);
    }
    if (flags & 0x7800) {
        if (flags & 0x800) {
            U16(r31, 0x6E) = U16(r30, 0x6E);
        }
        if (flags & 0x1000) {
            U32(r31, 0x72) = U32(r30, 0x72);
        }
        if (flags & 0x2000) {
            U32(r31, 0x76) = U32(r30, 0x76);
        }
        if (flags & 0x4000) {
            U32(r31, 0x7A) = U32(r30, 0x7A);
        } else {
            U32(r30, 0x7A) = U32(r31, 0x7A);
        }
    } else if (flags & 0x400) {
        U32(r31, 0x6E) = U32(r30, 0x6E);
        U32(r31, 0x72) = U32(r30, 0x72);
        U32(r31, 0x76) = U32(r30, 0x76);
        U32(r31, 0x7A) = U32(r30, 0x7A);
    } else {
        U16(r30, 0x7A) = U16(r31, 0x7A);
        U16(r30, 0x7C) = U16(r31, 0x7C);
    }
    if (flags & 0x8000) {
        U32(r31, 0x7E) = U32(r30, 0x7E);
        U32(r31, 0x82) = U32(r30, 0x82);
        U32(r31, 0x86) = U32(r30, 0x86);
        U32(r31, 0x8A) = U32(r30, 0x8A);
        U32(r31, 0x8E) = U32(r30, 0x8E);
        U32(r31, 0x92) = U32(r30, 0x92);
        U32(r31, 0x96) = U32(r30, 0x96);
        U32(r31, 0x9A) = U32(r30, 0x9A);
        U32(r31, 0x9E) = U32(r30, 0x9E);
        U32(r31, 0xA2) = U32(r30, 0xA2);
    }
    if (flags & 0x20000) {
        U16(r31, 0xA6) = U16(r30, 0xA6);
        U16(r31, 0xA8) = U16(r30, 0xA8);
    } else if (flags & 0x10000) {
        U16(r31, 0xA6) = U16(r30, 0xA6);
        U16(r31, 0xA8) = U16(r30, 0xA8);
        U16(r31, 0xAA) = U16(r30, 0xAA);
        U16(r31, 0xAC) = U16(r30, 0xAC);
        U16(r31, 0xAE) = U16(r30, 0xAE);
        U16(r31, 0xB0) = U16(r30, 0xB0);
        U16(r31, 0xB2) = U16(r30, 0xB2);
    }
    if (flags & 0x40000) {
        U16(r31, 0xB4) = U16(r30, 0xB4);
        U16(r31, 0xB6) = U16(r30, 0xB6);
        U16(r31, 0xB8) = U16(r30, 0xB8);
    }
    if (flags & 0x100000) {
        U16(r31, 0xBE) = U16(r30, 0xBE);
        U16(r31, 0xC0) = U16(r30, 0xC0);
    } else if (flags & 0x80000) {
        U16(r31, 0xBA) = U16(r30, 0xBA);
        U16(r31, 0xBC) = U16(r30, 0xBC);
        U16(r31, 0xBE) = U16(r30, 0xBE);
        U16(r31, 0xC0) = U16(r30, 0xC0);
    }
    if (flags & 0x400000) {
        U16(r31, 0xCC) = U16(r30, 0xCC);
        U16(r31, 0xCE) = U16(r30, 0xCE);
        U16(r31, 0xD0) = U16(r30, 0xD0);
        U16(r31, 0xD2) = U16(r30, 0xD2);
        U16(r31, 0xD4) = U16(r30, 0xD4);
    } else if (flags & 0x200000) {
        U16(r31, 0xC2) = U16(r30, 0xC2);
        U16(r31, 0xC4) = U16(r30, 0xC4);
        U16(r31, 0xC6) = U16(r30, 0xC6);
        U16(r31, 0xC8) = U16(r30, 0xC8);
        U16(r31, 0xCA) = U16(r30, 0xCA);
        U16(r31, 0xCC) = U16(r30, 0xCC);
        U16(r31, 0xCE) = U16(r30, 0xCE);
        U16(r31, 0xD0) = U16(r30, 0xD0);
        U16(r31, 0xD2) = U16(r30, 0xD2);
        U16(r31, 0xD4) = U16(r30, 0xD4);
    }
    if (flags & 0x800000) {
        U16(r31, 0xD6) = U16(r30, 0xD6);
    }
    if (flags & 0x1000000) {
        U16(r31, 0xD8) = U16(r30, 0xD8);
    }
    if (flags & 0x2000000) {
        memcpy(r31 + 0xDA, r30 + 0xDA, 0x20);
    }
    if (flags & 0x4000000) {
        memcpy(r31 + 0xFA, r30 + 0xFA, 0x10);
    }
    if (flags & 0x8000000) {
        memcpy(r31 + 0x10A, r30 + 0x10A, 0xA);
    }
    if (flags & 0x20000000) {
        U16(r31, 0x118) = U16(r30, 0x118);
        U16(r31, 0x11A) = U16(r30, 0x11A);
        return;
    }
    if (flags & 0x40000000) {
        U16(r31, 0x11E) = U16(r30, 0x11E);
        U16(r31, 0x120) = U16(r30, 0x120);
        U16(r31, 0x122) = U16(r30, 0x122);
        U16(r31, 0x124) = U16(r30, 0x124);
        U16(r31, 0x126) = U16(r30, 0x126);
        return;
    }
    if (flags & 0x10000000) {
        U16(r31, 0x114) = U16(r30, 0x114);
        U16(r31, 0x116) = U16(r30, 0x116);
        U16(r31, 0x118) = U16(r30, 0x118);
        U16(r31, 0x11A) = U16(r30, 0x11A);
        U16(r31, 0x11C) = U16(r30, 0x11C);
        U16(r31, 0x11E) = U16(r30, 0x11E);
        U16(r31, 0x120) = U16(r30, 0x120);
        U16(r31, 0x122) = U16(r30, 0x122);
        U16(r31, 0x124) = U16(r30, 0x124);
        U16(r31, 0x126) = U16(r30, 0x126);
    }
}
