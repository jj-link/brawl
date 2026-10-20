#include <types.h>
#pragma force_active on

extern "C" {
int fn_27_CBEA8(void* p) {
    u32 v = (*(u32*)((char*)p + 8) >> 19) & 0x1F;
    return (s32)(v << 27) >> 28;
}
}
