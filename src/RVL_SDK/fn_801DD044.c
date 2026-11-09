#include <types.h>
#pragma force_active on

extern int __cntlzw(unsigned int);

s32 fn_801DD044(s32 arg0, s32 arg1) {
    s32 var_r5;

    switch (__cntlzw((unsigned int)arg0)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        var_r5 = 0;
        if (!(arg1 & 0x80000000)) {
            var_r5 |= 1;
        }
        if (!(arg1 & 0x40000000)) {
            var_r5 |= 2;
        }
        if (!(arg1 & 0x20000000)) {
            var_r5 |= 4;
        }
        if (!(arg1 & 0x10000000)) {
            var_r5 |= 8;
        }
        if (!(arg1 & 0x08000000)) {
            var_r5 |= 0x10;
        }
        *(u16 *)0xCC00401C = var_r5;
        return arg0 & 0x07FFFFFF;
    case 5:
    case 6:
    case 7:
        var_r5 = *(u16 *)0xCC00500A;
        var_r5 &= ~0x1F8;
        if (!(arg1 & 0x04000000)) {
            var_r5 |= 0x10;
        }
        if (!(arg1 & 0x02000000)) {
            var_r5 |= 0x40;
        }
        if (!(arg1 & 0x01000000)) {
            var_r5 |= 0x100;
        }
        *(u16 *)0xCC00500A = var_r5;
        return arg0 & 0xF8FFFFFF;
    case 8:
        var_r5 = *(s32 *)0xCD006C00;
        var_r5 &= ~0x2C;
        if (!(arg1 & 0x00800000)) {
            var_r5 |= 4;
        }
        *(s32 *)0xCD006C00 = var_r5;
        return arg0 & 0xFF7FFFFF;
    case 9:
    case 10:
    case 11:
        var_r5 = *(s32 *)0xCD006800 & ~0x2C0F;
        if (!(arg1 & 0x00400000)) {
            var_r5 |= 1;
        }
        if (!(arg1 & 0x00200000)) {
            var_r5 |= 4;
        }
        if (!(arg1 & 0x00100000)) {
            var_r5 |= 0x400;
        }
        *(s32 *)0xCD006800 = var_r5;
        return arg0 & 0xFF8FFFFF;
    case 12:
    case 13:
    case 14:
        var_r5 = *(s32 *)0xCD006814 & ~0xC0F;
        if (!(arg1 & 0x00080000)) {
            var_r5 |= 1;
        }
        if (!(arg1 & 0x00040000)) {
            var_r5 |= 4;
        }
        if (!(arg1 & 0x00020000)) {
            var_r5 |= 0x400;
        }
        *(s32 *)0xCD006814 = var_r5;
        return arg0 & 0xFFF1FFFF;
    case 15:
    case 16:
        var_r5 = *(s32 *)0xCD006828;
        var_r5 &= ~0xF;
        if (!(arg1 & 0x00010000)) {
            var_r5 |= 1;
        }
        if (!(arg1 & 0x00008000)) {
            var_r5 |= 4;
        }
        *(s32 *)0xCD006828 = var_r5;
        return arg0 & 0xFFFE7FFF;
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        var_r5 = 0xF0;
        if (!(arg1 & 0x4000)) {
            var_r5 |= 0x800;
        }
        if (!(arg1 & 0x800)) {
            var_r5 |= 8;
        }
        if (!(arg1 & 0x400)) {
            var_r5 |= 4;
        }
        if (!(arg1 & 0x200)) {
            var_r5 |= 2;
        }
        if (!(arg1 & 0x100)) {
            var_r5 |= 1;
        }
        if (!(arg1 & 0x80)) {
            var_r5 |= 0x100;
        }
        if (!(arg1 & 0x40)) {
            var_r5 |= 0x1000;
        }
        if (!(arg1 & 0x2000)) {
            var_r5 |= 0x200;
        }
        if (!(arg1 & 0x1000)) {
            var_r5 |= 0x400;
        }
        if (!(arg1 & 0x20)) {
            var_r5 |= 0x2000;
        }
        if (!(arg1 & 0x10)) {
            var_r5 |= 0x4000;
        }
        *(s32 *)0xCC003004 = var_r5;
        return arg0 & 0xFFFF800F;
    default:
        return arg0;
    }
}
