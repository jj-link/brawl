#include <types.h>
#pragma force_active on

extern u8* const __GXData;

#define GX_WORD(base, off) (*(u32*)((base) + (off)))

void fn_801EFF28(s32 arg0, s32 arg1, s32* arg2, s32* arg3, s8* arg4) {
    u8* base = __GXData + arg0 * 4;
    s32 t;
    s8 v;

    switch (arg1) {
    case 9:
        *arg2 = GX_WORD(base, 0x1C) & 1;
        *arg3 = (GX_WORD(base, 0x1C) >> 1) & 7;
        *arg4 = (GX_WORD(base, 0x1C) >> 4) & 0x1F;
        return;
    case 10:
    case 25:
        t = (GX_WORD(base, 0x1C) >> 9) & 1;
        *arg2 = t;
        if (t == 1 && (GX_WORD(base, 0x1C) >> 31) != 0) {
            *arg2 = 2;
        }
        t = (GX_WORD(base, 0x1C) >> 10) & 7;
        *arg3 = t;
        switch (t) {
        case 1:
            v = 6;
            break;
        case 3:
            v = 0xE;
            break;
        default:
            v = 0;
            break;
        }
        *arg4 = v;
        return;
    case 11:
        *arg2 = (GX_WORD(base, 0x1C) >> 13) & 1;
        *arg3 = (GX_WORD(base, 0x1C) >> 14) & 7;
        *arg4 = 0;
        return;
    case 12:
        *arg2 = (GX_WORD(base, 0x1C) >> 17) & 1;
        *arg3 = (GX_WORD(base, 0x1C) >> 18) & 7;
        *arg4 = 0;
        return;
    case 13:
        *arg2 = (GX_WORD(base, 0x1C) >> 21) & 1;
        *arg3 = (GX_WORD(base, 0x1C) >> 22) & 7;
        *arg4 = (GX_WORD(base, 0x1C) >> 25) & 0x1F;
        return;
    case 14:
        *arg2 = GX_WORD(base, 0x3C) & 1;
        *arg3 = (GX_WORD(base, 0x3C) >> 1) & 7;
        *arg4 = (GX_WORD(base, 0x3C) >> 4) & 0x1F;
        return;
    case 15:
        *arg2 = (GX_WORD(base, 0x3C) >> 9) & 1;
        *arg3 = (GX_WORD(base, 0x3C) >> 10) & 7;
        *arg4 = (GX_WORD(base, 0x3C) >> 13) & 0x1F;
        return;
    case 16:
        *arg2 = (GX_WORD(base, 0x3C) >> 18) & 1;
        *arg3 = (GX_WORD(base, 0x3C) >> 19) & 7;
        *arg4 = (GX_WORD(base, 0x3C) >> 22) & 0x1F;
        return;
    case 17:
        *arg2 = (GX_WORD(base, 0x3C) >> 27) & 1;
        *arg3 = (GX_WORD(base, 0x3C) >> 28) & 7;
        *arg4 = GX_WORD(base, 0x5C) & 0x1F;
        return;
    case 18:
        *arg2 = (GX_WORD(base, 0x5C) >> 5) & 1;
        *arg3 = (GX_WORD(base, 0x5C) >> 6) & 7;
        *arg4 = (GX_WORD(base, 0x5C) >> 9) & 0x1F;
        return;
    case 19:
        *arg2 = (GX_WORD(base, 0x5C) >> 14) & 1;
        *arg3 = (GX_WORD(base, 0x5C) >> 15) & 7;
        *arg4 = (GX_WORD(base, 0x5C) >> 18) & 0x1F;
        return;
    case 20:
        *arg2 = (GX_WORD(base, 0x5C) >> 23) & 1;
        *arg3 = (GX_WORD(base, 0x5C) >> 24) & 7;
        *arg4 = GX_WORD(base, 0x5C) >> 27;
        return;
    default:
        *arg2 = 1;
        *arg3 = 0;
        *arg4 = 0;
        return;
    }
}
