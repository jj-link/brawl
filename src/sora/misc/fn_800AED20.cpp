#include <types.h>
#pragma force_active on

static inline u8* findEntry(u8* self, u32 key) {
    u32 i;
    u32 count;

    if (self[0x3EA8] == 0 && self[0x3EB0] == 0) {
        return 0;
    }
    count = *(u32*)(self + 0x2EF4);
    for (i = 0; i < count; i++) {
        if (*(u32*)(*(u8**)self + i * 0x64) == key) {
            return *(u8**)self + i * 0x64;
        }
    }
    return 0;
}

extern "C" int fn_800AED20(u8* self, int idx, u32 key) {
    u32 mask;
    u8* entry;
    u32 value;

    if (idx == 4) {
        idx = 3;
    }
    if (idx < 0x20) {
        mask = 1U << idx;
        entry = findEntry(self, key);
        value = *(u32*)(entry + 0x1C);
    } else {
        idx -= 0x20;
        mask = 1U << idx;
        entry = findEntry(self, key);
        value = *(u32*)(entry + 0x20);
    }
    return (value & mask) != 0;
}
