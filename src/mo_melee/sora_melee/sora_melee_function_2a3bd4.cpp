#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
}

extern "C" int fn_27_2A3BD4(u8* p) {
    int result = 0;
    if (p[0x14B4]) {
        u32 v = *(u32*)getInstance__15gfTaskSchedulerFv();
        if (((s32)((v << 8) & 0xFF800000) >> 24) >= 3) {
            result = 1;
        }
    }
    return result;
}
