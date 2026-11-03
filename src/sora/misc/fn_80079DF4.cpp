#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" s32 fn_80079DF4(void* self) {
    u8* base = reinterpret_cast<u8*>(self);
    u8* p;
    u32 countA;
    u32 countB;
    u32 i;

    OSLockMutex(reinterpret_cast<OSMutex*>(base + 0x340));
    countA = *reinterpret_cast<u32*>(base + 0xcc8);
    countB = *reinterpret_cast<u32*>(base + 0xccc);
    if (countB + countA == 0) {
        OSUnlockMutex(reinterpret_cast<OSMutex*>(base + 0x340));
        return 1;
    }
    p = base;
    for (i = 0; i < countA; i++) {
        if (*reinterpret_cast<u32*>(p + 0x368) == 2) {
            OSUnlockMutex(reinterpret_cast<OSMutex*>(base + 0x340));
            return 0;
        }
        p += 0x10;
    }
    p = base;
    for (i = 0; i < countB; i++) {
        if (*reinterpret_cast<u32*>(p + 0xcb8) == 2) {
            OSUnlockMutex(reinterpret_cast<OSMutex*>(base + 0x340));
            return 0;
        }
        p += 0x10;
    }
    OSUnlockMutex(reinterpret_cast<OSMutex*>(base + 0x340));
    return 1;
}
