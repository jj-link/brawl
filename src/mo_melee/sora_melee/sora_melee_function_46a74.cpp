#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_4E0;
extern const float lbl_27_rodata_4E4;

void fn_27_46A74(u8* p) {
    u32 value = *(u32*)(p + 0x74);
    *(s32*)(p + 0x0) = -1;
    value &= ~0x1F;
    *(u16*)(p + 0x4) = 0;
    *(u16*)(p + 0x6) = 0;
    *(float*)(p + 0x60) = lbl_27_rodata_4E0;
    *(float*)(p + 0x64) = lbl_27_rodata_4E0;
    *(float*)(p + 0x68) = lbl_27_rodata_4E0;
    *(u32*)(p + 0x74) = value;
    *(float*)(p + 0x9C) = lbl_27_rodata_4E4;
    *(float*)(p + 0xA0) = lbl_27_rodata_4E0;
    *(float*)(p + 0xA4) = lbl_27_rodata_4E0;
    *(float*)(p + 0xAC) = lbl_27_rodata_4E4;
    *(u8*)(p + 0xB0) = 0;
    *(u8*)(p + 0xB1) = 0;
    *(u8*)(p + 0xB2) = 0;
    *(u8*)(p + 0xB3) = 0;
    *(u8*)(p + 0xB4) = 0;
    *(float*)(p + 0xC) = lbl_27_rodata_4E4;
    *(float*)(p + 0x8) = lbl_27_rodata_4E4;
}
}
