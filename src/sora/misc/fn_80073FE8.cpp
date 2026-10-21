#include <types.h>
#pragma force_active on

struct sndSystem {
    s32 getBGMId(void);
};

s32 sndSystem::getBGMId(void) {
    if (reinterpret_cast<u8*>(this)[0x6EF] == 0) {
        return -1;
    }
    if (*reinterpret_cast<s32*>(reinterpret_cast<u8*>(this) + 0x6E0) == 0) {
        *reinterpret_cast<s32*>(reinterpret_cast<u8*>(this) + 0x6E4) = -1;
    }
    return *reinterpret_cast<s32*>(reinterpret_cast<u8*>(this) + 0x6E4);
}
