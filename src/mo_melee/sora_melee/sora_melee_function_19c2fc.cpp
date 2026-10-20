#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19C2FC(void* p) {
    u32 v = *(u32*)((char*)p + 8);
    return (s32)((v << 4) & 0xE0000000) >> 30;
}
