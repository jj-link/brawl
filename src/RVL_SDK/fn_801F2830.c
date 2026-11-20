#include <types.h>
#pragma force_active on

void fn_801F2830(int arg0, int arg1, int arg2, int *arg3, int *arg4, int *arg5)
{
    int var_r9;
    int var_r11;
    int var_r12;

    switch (arg0) {
    case 0x0:
    case 0x8:
    case 0xE:
    case 0x20:
    case 0x30:
        var_r11 = 3;
        var_r12 = 3;
        break;
    case 0x1:
    case 0x2:
    case 0x9:
    case 0x11:
    case 0x22:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x39:
    case 0x3A:
        var_r11 = 3;
        var_r12 = 2;
        break;
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0xA:
    case 0x13:
    case 0x16:
    case 0x23:
    case 0x2B:
    case 0x2C:
    case 0x3C:
        var_r11 = 2;
        var_r12 = 2;
        break;
    default:
        var_r12 = 0;
        var_r11 = 0;
        break;
    }
    if (arg1 == 0) {
        arg1 = 1;
    }
    if (arg2 == 0) {
        arg2 = 1;
    }
    *arg3 = (arg1 + (1 << var_r11) - 1) >> var_r11;
    *arg4 = (arg2 + (1 << var_r12) - 1) >> var_r12;
    var_r9 = (arg0 == 6 || arg0 == 0x16);
    *arg5 = ((unsigned int)(-var_r9 | var_r9) >> 31) + 1;
}
