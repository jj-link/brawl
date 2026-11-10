#include <types.h>
#pragma force_active on

extern u32 lbl_80407728[][2];
extern u32 lbl_80407858[];

extern "C" s32 fn_80077E94(u32 arg0, u32 arg1) {
    u32 index = arg0 - 1;
    if (arg0 >= 1 && arg0 <= 0x26) {
        if (arg1 >= lbl_80407728[index][0] &&
            arg1 <= lbl_80407728[index][1]) return 1;
        switch (arg0) {
        case 7:
            if (arg1 >= 0x796 && arg1 <= 0x7C1) return 1;
            break;
        case 15:
            if (arg1 >= 0x1A3A && arg1 <= 0x1A60) return 1;
            break;
        case 17:
            if (arg1 >= 0x618 && arg1 <= 0x63F) return 1;
            break;
        case 18:
            if (arg1 >= 0x66B && arg1 <= 0x695) return 1;
            break;
        case 28:
            if (arg1 == 0x876) goto yes28;
            if (arg1 == 0x14D2) goto yes28;
            if (arg1 != 0x14D3) goto no28;
        yes28:
            return 1;
        no28:
            break;
        case 29:
            if (arg1 == 0x877) goto yes29;
            if (arg1 == 0x14D4) goto yes29;
            if (arg1 != 0x14D5) goto no29;
        yes29:
            return 1;
        no29:
            break;
        case 30:
            if (arg1 == 0x878) goto yes30;
            if (arg1 == 0x14D6) goto yes30;
            if (arg1 != 0x14D7) goto no30;
        yes30:
            return 1;
        no30:
            break;
        }
        return 0;
    }
    if (arg0 == 0x28) return 0;
    if (arg0 == 0x29 || (arg0 >= 0x2A && arg0 <= 0x4B)) {
        if (arg1 < 0x1AA9 || arg1 > 0x1B45) return 0;
        u32 *p = lbl_80407858;
        for (int i = 0; i < 33; p++, i++) {
            if (arg1 == *p) return 1;
        }
    }
    return 0;
}
