#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_8E80[];

void fn_103_788C(void* out, void* arg) {
    *(void**)((u8*)out + 0x00) = lbl_27_data_8E80;
    *(void**)((u8*)out + 0x04) = arg;
    *(u32*)((u8*)out + 0x08) = 0;

    u32 zero = 0;
    *(u32*)&zero = 0;

    *(s32*)((u8*)out + 0x0C) = -1;
    *(s32*)((u8*)out + 0x10) = -1;
    *(s32*)((u8*)out + 0x14) = 0;
}
}
