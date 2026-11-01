#pragma force_active on
#include <types.h>
#include <nt/nt_offline.h>
#include <gf/gf_heap_manager.h>
#include <string.h>

extern "C" s32 fn_8014DD34(void*, s32);
extern "C" s32 fn_8014E0DC(void*, s32);
extern "C" s32 fn_803A1AE8(s32*);
extern "C" s32 fn_803A1A7C(s32*);
extern "C" s32 fn_803A1C10(u32);
extern "C" s32 fn_803A19D8(u32*, u32);

struct FriendList {
    u32 unk0;
    u32 heapType;
    u32 unk8;
    void* entries;
    s32 count;
};

struct FriendEntry {
    u32 data[6];
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
};

extern "C" s32 fn_8014CEC4(FriendList* self) {
    s32 entryCount;
    s32 available;
    u32 info[74] __attribute__((aligned(32)));

    if (fn_8014DD34(self, 1) == 0) {
        return 0;
    }

    if (self->entries != 0) {
        gfHeapManager::free(self->entries);
        self->count = 0;
        self->entries = 0;
    }

    s32 result = fn_803A1AE8(&entryCount);
    if (result != 0 && fn_8014E0DC(self, result) == 0) {
        return 0;
    }

    if (entryCount == 0) {
        return 1;
    }

    self->entries = gfHeapManager::alloc(
        (Heaps::HeapType)self->heapType, entryCount * 0x28);
    if (self->entries == 0) {
        return 0;
    }

    result = fn_803A1A7C(&available);
    if (result != 0) {
        fn_8014E0DC(self, result);
        return 0;
    }

    NtOffline offline;
    u32 i;
    for (i = 0; i < (u32)available; ++i) {
        if (fn_803A1C10(i) == 0) {
            continue;
        }

        result = fn_803A19D8(info, i);
        if (result == 0) {
            if (info[0] == 1 && info[1] == 2 &&
                offline.getFriendIndexHaveWiiID(*(u64*)&info[16]) != 0xFF) {
                FriendEntry* dst =
                    (FriendEntry*)self->entries + self->count;
                *(u64*)&dst->value0 = *(u64*)&info[8];
                *(u64*)&dst->value2 = *(u64*)&info[16];
                memcpy(dst, &info[2], 0x18);
                ++self->count;
            }
            continue;
        }

        if (fn_8014E0DC(self, result) == 0) {
            return 0;
        }
    }

    return 1;
}
