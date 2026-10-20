#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19FDA4(void* p) {
    u32 w = *(u32*)((char*)p + 8);
    return ((s32)((w << 6) & 0xF0000000)) >> 29;
}
