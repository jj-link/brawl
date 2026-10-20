#include <types.h>
#pragma force_active on

extern "C" bool fn_27_20B6AC(u8* self, u32 mask, s32 id) {
    if (id == -1 || id == *(s32*)(self + 0xac)) {
        if (*(u32*)(self + 0x58) & mask) {
            return true;
        }
    }
    return false;
}
