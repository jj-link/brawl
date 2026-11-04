#pragma force_active on
#include <types.h>

static inline u8 findEntry(char* self, int id) {
    for (u8 i = 0; i < *(u8*)(self + 0x158); ++i) {
        if (id == *(int*)(self + i * 0x54 + 8)) {
            return i;
        }
    }
    return 0xFF;
}

extern "C" int fn_27_12006C(char* self, int kind, int id, unsigned int field) {
    switch (kind) {
    case 8: {
        char* entry = self + findEntry(self, id) * 0x54 + 8;
        if (field == 0xC) return *(int*)(entry + 0x48);
        if (field == 0xD) return *(int*)(entry + 0x44);
        if (field & 0x80) return *(int*)(entry + 0x4C);
        return *(int*)(entry + (u8)field * 4 + 0x14);
    }
    case 6:
        return *(int*)(self + findEntry(self, id) * 0x54 + 0x10);
    case 5:
        return *(int*)(self + findEntry(self, id) * 0x54 + 0x14);
    case 7:
        return *(int*)(self + findEntry(self, id) * 0x54 + 0x18);
    default:
        return 0xFFFF;
    }
}
