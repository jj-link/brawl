#include <types.h>
#pragma force_active on
extern "C" {
struct OriginalIds { int values[10]; };
extern const OriginalIds lbl_80406EA8;
extern void* g_GameGlobal;
void* fn_8004E5C4(void*);
u8* fn_8004E7B8(void*, int);
}
extern "C" s32 fn_80058C48(s32 arg0) {
    s32 result = 0;
    switch (arg0) {
    case 0xA:
        if (*(u8*)((char*)fn_8004E5C4(g_GameGlobal) + 0x32A) >= 15U) result = 1;
        break;
    case 0x6F:
        if (*(u8*)((char*)fn_8004E5C4(g_GameGlobal) + 0x32A) >= 5U) result = 1;
        break;
    case 0x49: {
        OriginalIds ids = lbl_80406EA8;
        int* p = ids.values;
        u32 total = 0;
        int i = 0;
        do {
            total += *fn_8004E7B8(g_GameGlobal, *p);
            if (total >= 10U) {
                result = 1;
                break;
            }
            i++;
            p++;
        } while (i < 10);
        break;
    }
    case 0x13:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0x2A) >= 3) result = 1;
        break;
    case 0x15:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0x35) >= 10) result = 1;
        break;
    case 0x37:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0x19) >= 10) result = 1;
        break;
    case 0x70:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0x16) >= 10) result = 1;
        break;
    case 0x1C:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0x23) >= 10) result = 1;
        break;
    case 0x6E:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0xE) >= 10) result = 1;
        break;
    case 0x4E:
        if ((int)*fn_8004E7B8(g_GameGlobal, 5) >= 10) result = 1;
        break;
    case 0x32:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0xB) >= 10) result = 1;
        break;
    case 0x11:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0xC) >= 10) result = 1;
        break;
    case 0x31:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0x14) >= 10) result = 1;
        break;
    case 0x71:
        if ((int)*fn_8004E7B8(g_GameGlobal, 0x22) >= 15) result = 1;
        break;
    }
    return result;
}