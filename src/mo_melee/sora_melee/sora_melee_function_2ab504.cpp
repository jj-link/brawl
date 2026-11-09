#include <types.h>
#pragma force_active on
extern "C" {
extern s32 lbl_27_data_71BF0[];
extern float lbl_27_rodata_5D5C;
}
extern "C" float fn_27_2AB504(void* arg0, s32 arg1, float farg0) {
    u8* self = (u8*)arg0;
    s32 r0;
    float f0;
    float f1 = farg0;
    float f2;
    if (*(s32*)(self + 0x50) != 2 || *(u8*)(self + 0x1008) == 0) goto L658;
    r0 = 0;
    if (arg1 > -1 && arg1 < 0xB2) r0 = 1;
    if (r0 == 0) goto L658;
    if (arg1 == 0x46) goto L658;
    switch (arg1) {
    case 0x46: r0 = 2; break;
    case 0xB: case 0x17: case 0x33: r0 = 1; break;
    default:
        if (arg1 == -3) r0 = 1;
        else if (arg1 < 0 || arg1 >= 0xB2) r0 = -1;
        else r0 = lbl_27_data_71BF0[arg1];
        switch (r0) {
        case 5: r0 = 2; break;
        case 0: case 1: case 8: r0 = 0; break;
        default: r0 = 3; break;
        }
    }
    switch (r0) {
    case 0:
        if (*(s32*)(self + 0xFF8) + *(s32*)(self + 0x1000) > 5) return lbl_27_rodata_5D5C;
    case 1:
        if (*(s32*)(self + 0x1000) + (*(s32*)(self + 0xFF8) + *(s32*)(self + 0xFFC)) > 8) return lbl_27_rodata_5D5C;
    }
L658:
    f2 = lbl_27_rodata_5D5C;
    if (f1 > f2) {
        r0 = 0;
        if (arg1 > -1 && arg1 < 0xB2) r0 = 1;
        if (r0 != 0) f0 = *(float*)(self + arg1 * 4 + 0x11B4);
        else f0 = lbl_27_rodata_5D5C;
        f2 = f1 + f0;
    }
    if (arg1 == 0x37) f2 = f2 * *(float*)(self + 0x1484);
    return f2;
}