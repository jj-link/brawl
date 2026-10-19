#include <types.h>
#pragma force_active on

extern "C" {
void fn_80074ECC(void* snd, u32 flags, float f1, float f2);
extern void* g_sndSystem;
extern float lbl_10_rodata_0;

void fn_10_BC98(void* self) {
    s32 state = *(s32*)((u8*)self + 0x5d4);
    u32 flags = 0x202b;
    switch (state) {
        case 0:
            flags = 0x202b;
            break;
        case 1:
            flags = 0x202d;
            break;
        case 2:
            flags = 0x202c;
            break;
        default:
            break;
    }
    fn_80074ECC(g_sndSystem, flags, lbl_10_rodata_0, lbl_10_rodata_0);
}
}
