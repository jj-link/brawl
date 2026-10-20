#include <types.h>
#pragma force_active on

extern "C" u8 fn_27_27D2AC(void* self, s32 idx) {
    u8* base = *(u8**)((u8*)self + 0xc);
    return base[idx * 0x5c + 0x9a];
}
