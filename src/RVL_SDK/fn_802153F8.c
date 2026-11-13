#include <types.h>
#pragma force_active on

extern unsigned char lbl_804F6760[];
extern u32 lbl_8059ECEC;
extern u32 lbl_8059ECE8;
extern u32 fn_801E7204(s32 arg0);

void fn_802153F8(s32 arg0)
{
    u32 bit;
    unsigned char *p;
    u32 mask;

    bit = 0x80000000U >> arg0;
    p = lbl_804F6760 + arg0 * 12;
    mask = lbl_8059ECEC & 0x700;

    switch (mask) {
    case 0x500:
    case 0x600:
    case 0x700:
    case 0x0:
        p[6] &= 0xF0;
        p[7] &= 0xF0;
        p[8] &= 0xF0;
        p[9] &= 0xF0;
        break;
    case 0x100:
        ((s8*)p)[4] &= ~0xF;
        ((s8*)p)[5] &= ~0xF;
        p[8] &= 0xF0;
        p[9] &= 0xF0;
        break;
    case 0x200:
        ((s8*)p)[4] &= ~0xF;
        ((s8*)p)[5] &= ~0xF;
        p[6] &= 0xF0;
        p[7] &= 0xF0;
        break;
    case 0x300:
    case 0x400:
    default:
        break;
    }

    p[2] -= 0x80;
    p[3] -= 0x80;
    p[4] -= 0x80;
    p[5] -= 0x80;
    if ((lbl_8059ECE8 & bit) != 0) {
        if ((s8)p[2] > 0x40) {
            if ((fn_801E7204(arg0) & 0xFFFF0000U) == 0x09000000U) {
                p[2] = 0;
            }
        }
    }
}
