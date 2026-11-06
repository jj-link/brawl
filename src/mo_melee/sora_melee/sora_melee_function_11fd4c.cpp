#pragma force_active on
#include <types.h>

extern "C" void fn_27_10B334(void*, int, int);
extern "C" void fn_27_10B3CC(void*, int, int);
extern void* g_ftManager;

struct EntryPair {
    unsigned int value;
    int arg;
};

struct EntryBlock {
    char padding[0x310];
    EntryPair entries[4];
};

static inline u8 findEntry(char* self, int id) {
    for (u8 i = 0; i < *(u8*)(self + 0x158); ++i) {
        if (id == *(int*)(self + i * 0x54 + 8)) {
            return i;
        }
    }
    return 0xFF;
}

static inline unsigned int firstValue(EntryBlock* block) {
    for (int j = 0; j < 4; ++j) {
        if (block->entries[j].value != 0xFFFF) {
            return block->entries[j].value;
        }
    }
    return 0xFFFF;
}

static inline void removeValue(EntryBlock* block, unsigned int value, int arg) {
    for (unsigned int j = 0; j < 4; ++j) {
        if (arg == block->entries[j].arg) {
            block->entries[j].value = value;
            block->entries[j].arg = -1;
            return;
        }
    }
}

static inline void addValue(EntryBlock* block, unsigned int value, int arg) {
    for (int j = 0; j < 4; ++j) {
        if (block->entries[j].value == 0xFFFF) {
            block->entries[j].value = value;
            block->entries[j].arg = arg;
            return;
        }
    }
}

extern "C" void fn_27_11FD4C(
    char* self, int kind, int id, unsigned int field,
    unsigned int value, int arg
) {
    switch (kind) {
    case 8: {
        char* entry = self + findEntry(self, id) * 0x54 + 8;
        if (field == 0xC) {
            *(unsigned int*)(entry + 0x48) = value;
        } else if (field == 0xD) {
            *(unsigned int*)(entry + 0x44) = value;
        } else if (field & 0x80) {
            *(unsigned int*)(entry + 0x4C) = value;
        } else {
            *(unsigned int*)(entry + (u8)field * 4 + 0x14) = value;
        }
        break;
    }
    case 6:
        *(unsigned int*)(self + findEntry(self, id) * 0x54 + 0x10) = value;
        break;
    case 5:
        *(unsigned int*)(self + findEntry(self, id) * 0x54 + 0x14) = value;
        break;
    case 7:
        *(unsigned int*)(self + findEntry(self, id) * 0x54 + 0x18) = value;
        break;
    case 11: {
        char* p = self;
        int found = 0;
        for (unsigned int i = 0; i < 8; ++i, p += 0x30) {
            if (id == *(int*)(p + 0x330)) {
                if (arg == *(int*)(p + 0x338)) {
                    if (value == 0xFFFF) {
                        removeValue((EntryBlock*)p, value, arg);
                    } else {
                        addValue((EntryBlock*)p, value, arg);
                    }

                    unsigned int result = firstValue((EntryBlock*)p);
                    if (result != 0xFFFF) {
                        fn_27_10B334(g_ftManager, *(int*)(self + 0x174), id);
                        goto mark_found;
                    }
                } else {
                mark_found:
                    found = 1;
                }
            }
        }
        if (!found) {
            fn_27_10B3CC(g_ftManager, *(int*)(self + 0x174), id);
        }
        break;
    }
    }
}
