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

static inline u32 getBits(u8* self, u32 key, int bit) {
    u32 mask;
    u32 value;

    if (bit < 0x20) {
        mask = 1U << bit;
        value = *(u32*)(findEntry(self, key) + 0x1C);
    } else {
        bit -= 0x20;
        mask = 1U << bit;
        value = *(u32*)(findEntry(self, key) + 0x20);
    }
    return value & mask;
}

extern "C" int fn_800AEF54(u8* self, u32 key, u32 n) {
    u32 found = 0;
    int i;

    for (i = 0; (u32)i < 0x3E; i++) {
        int bit = i;
        if (i == 4) {
            bit = 3;
        }
        if (getBits(self, key, bit)) {
            if (found == n) {
                return i;
            }
            found++;
        }
    }
    return 0x3E;
}
