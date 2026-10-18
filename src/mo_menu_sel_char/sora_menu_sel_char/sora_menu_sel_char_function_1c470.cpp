#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B6E08(void* a, float* b);
void fn_10_17B8C(void* a, s32 b);
void fn_10_1C470(u8* self, s32 arg1, s32 arg2);
extern float lbl_10_rodata_870;
extern float lbl_10_rodata_890;
}

extern "C" void fn_10_1C470(u8* self, s32 arg1, s32 arg2) {
    if ((u32)(arg1 - 1) <= 1) {
        s32 flag;
        float f;
        float v[3];
        if (arg2 != 0) {
            flag = 1;
            f = lbl_10_rodata_870;
        } else {
            flag = 0;
            f = lbl_10_rodata_890;
        }
        v[0] = f;
        v[1] = f;
        v[2] = f;
        fn_800B6E08(*(void**)(self + 0x4), v);
        *(s32*)(self + 0x10) = arg2;
        fn_10_17B8C(*(void**)(self + 0x14), flag);
    }
    *(s32*)(self + 0x18) = arg1;
}
