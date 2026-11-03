#include <types.h>
#pragma force_active on

s32 fn_803ADD50(s32 arg0, s32 arg1, void* arg2) {
    u16 v;
    s32 i;
    u8* dst;

    if (arg0 == 0 || arg2 == 0)
        return 1;

    dst = (u8*)arg2;
    if (arg1 == 0) {
        *(s32*)(dst + 4) = 0;
        *(s32*)(dst + 0) = 0;
    } else {
        if (*(s32*)(dst + 4) == 0)
            *(s32*)(dst + 4) = arg1;
        *(s32*)(dst + 0) = arg1;
    }

    arg0 += 0x1BE;
    for (i = 0; i < 4; i++) {
        dst[8] = ((u8*)arg0)[0];
        dst[9] = ((u8*)arg0)[4];
        dst[0xC] = ((u8*)arg0)[1];
        v = ((s32)((u8*)arg0)[3] << 8) | (s32)((u8*)arg0)[2];
        *(s16*)(dst + 0xA) = (s16)(((v & 0xC0) << 2) + (v >> 8));
        dst[0xD] = (u8)(v & 0x3F);

        v = (s32)((u8*)arg0)[5] | ((s32)((u8*)arg0)[6] << 8);
        dst[0x10] = (u8)v;
        v = ((s32)((u8*)arg0)[7] << 8) | (s32)((u8*)arg0)[6];
        *(s16*)(dst + 0xE) = (s16)(((v & 0xC0) << 2) + (v >> 8));
        dst[0x11] = (u8)(v & 0x3F);

        *(s32*)(dst + 0x14) = (s32)((u8*)arg0)[8] |
                               ((s32)((u8*)arg0)[9] << 8) |
                               ((s32)((u8*)arg0)[10] << 16) |
                               ((s32)((u8*)arg0)[11] << 24);
        *(s32*)(dst + 0x18) = (s32)((u8*)arg0)[12] |
                               ((s32)((u8*)arg0)[13] << 8) |
                               ((s32)((u8*)arg0)[14] << 16) |
                               ((s32)((u8*)arg0)[15] << 24);

        arg0 += 0x10;
        dst += 0x14;
    }

    return 0;
}