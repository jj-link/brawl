#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" int fn_80079D24(char* object, u32 key) {
    OSLockMutex((OSMutex*)(object + 0x340));
    char* entry;
    u32 count1 = *(u32*)(object + 0xCC8);
    u32 count2 = *(u32*)(object + 0xCCC);
    if (count2 + count1 == 0) {
        OSUnlockMutex((OSMutex*)(object + 0x340));
        return 1;
    }
    entry = object;
    for (u32 i = 0; i < count1; ++i) {
        if (key == *(u32*)(entry + 0x370)) {
            OSUnlockMutex((OSMutex*)(object + 0x340));
            return 0;
        }
        entry += 0x10;
    }
    entry = object;
    for (u32 i = 0; i < count2; ++i) {
        if (key == *(u32*)(entry + 0xCC0)) {
            OSUnlockMutex((OSMutex*)(object + 0x340));
            return 0;
        }
        entry += 0x10;
    }
    OSUnlockMutex((OSMutex*)(object + 0x340));
    return 1;
}
