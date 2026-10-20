#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B6E08(void* a, float* b);
void fn_10_17B8C(void* a, s32 b);
extern float lbl_10_rodata_870;
extern float lbl_10_rodata_890;
}

extern "C" void fn_10_1C3E8(u8* a, s32 b) {
    s32 flag;
    float f;
    float v[3];
    if (b != 0) {
        flag = 1;
        f = lbl_10_rodata_870;
    } else {
        flag = 0;
        f = lbl_10_rodata_890;
    }
    v[0] = f;
    v[1] = f;
    v[2] = f;
    fn_800B6E08(*(void**)(a + 4), v);
    *(s32*)(a + 0x10) = b;
    fn_10_17B8C(*(void**)(a + 0x14), flag);
}
