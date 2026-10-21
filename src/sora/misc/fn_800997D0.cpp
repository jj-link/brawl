#include <types.h>
#pragma force_active on

extern "C" int fn_800997D0(void* obj, s32 id) {
    u8* p = (u8*)obj;
    if (id == *(s16*)(p + 0x14) || id == *(s16*)(p + 0x16) || id == *(s16*)(p + 0x18) || id == *(s16*)(p + 0x1a)) {
        return 1;
    }
    return 0;
}
