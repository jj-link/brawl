#include <types.h>
#pragma force_active on

extern u8 lbl_8052CDC0[];

void *fn_8024F968(void *arg0) {
    u8 *temp_r8;
    s32 temp_r0;

    temp_r8 = *(u8 **)(lbl_8052CDC0 + 0x7B0);
    if (temp_r8 == NULL) {
        return NULL;
    }
    temp_r0 = (s32)(temp_r8 - (lbl_8052CDC0 + 0x178));
    *(u8 **)(lbl_8052CDC0 + 0x7B0) = *(u8 **)(temp_r8 + 0x8);
    temp_r8[0x0] = 1;
    *(u16 *)(temp_r8 + 0x14) = (u16)(temp_r0 / 124) + 0x40;
    *(void **)(temp_r8 + 0x10) = arg0;
    if (*(u8 **)((u8 *)arg0 + 0x8) == NULL) {
        *(u8 **)((u8 *)arg0 + 0xC) = temp_r8;
        *(u8 **)((u8 *)arg0 + 0x8) = temp_r8;
        *(u32 *)(temp_r8 + 0x8) = 0;
        *(u32 *)(temp_r8 + 0xC) = 0;
    } else {
        *(u32 *)(temp_r8 + 0x8) = 0;
        *(u8 **)(temp_r8 + 0xC) = *(u8 **)((u8 *)arg0 + 0xC);
        *(u8 **)(*(u8 **)((u8 *)arg0 + 0xC) + 0x8) = temp_r8;
        *(u8 **)((u8 *)arg0 + 0xC) = temp_r8;
    }
    *(u16 *)(temp_r8 + 0x3C) = 0xFFFF;
    *(u16 *)(temp_r8 + 0x3A) = 0x2A0;
    *(u16 *)(temp_r8 + 0x38) = 0x2A0;
    temp_r8[0x59] = 1;
    temp_r8[0x41] = 1;
    *(u32 *)(temp_r8 + 0x5C) = 0;
    *(u32 *)(temp_r8 + 0x44) = 0;
    *(u32 *)(temp_r8 + 0x60) = 0;
    *(u32 *)(temp_r8 + 0x48) = 0;
    *(u32 *)(temp_r8 + 0x64) = 0;
    *(u32 *)(temp_r8 + 0x4C) = 0;
    *(s32 *)(temp_r8 + 0x68) = -1;
    *(s32 *)(temp_r8 + 0x50) = -1;
    *(s32 *)(temp_r8 + 0x6C) = -1;
    *(s32 *)(temp_r8 + 0x54) = -1;
    temp_r8[0x34] = 0;
    *(u32 *)(temp_r8 + 0x4) = 0;
    temp_r8[0x37] = 1;
    *(u8 **)(temp_r8 + 0x28) = temp_r8;
    return temp_r8;
}
