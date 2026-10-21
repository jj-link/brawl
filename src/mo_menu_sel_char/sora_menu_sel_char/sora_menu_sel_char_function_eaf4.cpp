#include <types.h>
#pragma force_active on

extern "C" void fn_800B68F0(void* self, float* out, char* a, char* b);
extern "C" char lbl_10_data_5B8[];
extern "C" char lbl_10_data_5C0[];

extern "C" int fn_10_EAF4(u8* self, float* p) {
    float r[4];
    s32 i;
    for (i = 0; i < *(s32*)(self + 0x138); i++) {
        fn_800B68F0(*(void**)(self + i * 4 + 0x16C), r, lbl_10_data_5B8, lbl_10_data_5C0);
        if (!(r[0] <= p[0])) continue;
        if (!(r[1] >= p[0])) continue;
        if (!(r[3] <= p[1])) continue;
        if (!(r[2] >= p[1])) continue;
        return *(int*)(self + i * 4 + 0x70);
    }
    return 0x28;
}
