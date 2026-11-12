#include <types.h>
#include <gf/gf_heap_manager.h>

#pragma force_active on

struct EntryFlags {
    u8 owned : 1;
    u8 other : 7;
};

struct ArchiveFlags {
    u8 complete : 1;
    u8 padding : 2;
    u8 special : 1;
    u8 low : 4;
};

extern "C" void fn_8001429C(void*);
extern "C" void fn_80014028(void*);
extern "C" void fn_80014AF8(void*, void*, int, void*);

#define F(p, t, o) (*(t*)((u8*)(p) + (o)))

#define CLEAR(node, cursor, flags, index)                             \
    cursor = node;                                                    \
    flags = node + 13;                                                \
    for (index = 0; index < F(node, u16, 2);                          \
         flags += 16, cursor += 16, index++) {                        \
        if ((*flags >> 7) & 1) {                                     \
            gfHeapManager::free(F(cursor, void*, 16));                \
            F(cursor, void*, 16) = 0;                                \
            ((EntryFlags*)flags)->owned = 0;                           \
        }                                                             \
    }

extern "C" void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(u8* self, void* data,
                                                              int size,
                                                              Heaps::HeapType heapType) {
    u32 index;
    u32 index1;
    u32 index3;
    u8* flags3;
    u8* cursor3;
    u8* flags2;
    u8* cursor2;
    u32 index2;
    u8* flags1;
    u8* cursor1;
    u8* node;
    u8* flags;
    u8* cursor;
    u8* child1;
    u8* child2;
    void* heap;
    u8* child3;

    heap = gfHeapManager::getHeap(heapType);

    if (F(self, void*, 0x20) != 0) {
        if ((self[9] >> 3) & 1)
            fn_8001429C(self);
        if ((self[9] >> 6) & 1)
            gfHeapManager::free(F(self, void*, 0x20));
        F(self, void*, 0x20) = 0;
    }

    if (F(self, void*, 0x1c) != 0) {
        gfHeapManager::free(F(self, void*, 0x1c));
        F(self, void*, 0x1c) = 0;
    } else {
        node = F(self, u8*, 0x68);
        if (node != 0) {
            CLEAR(node, cursor, flags, index)
            child1 = F(node, u8*, 4);
            if (child1 != 0) {
                CLEAR(child1, cursor1, flags1, index1)
                child2 = F(child1, u8*, 4);
                if (child2 != 0) {
                    CLEAR(child2, cursor2, flags2, index2)
                    child3 = F(child2, u8*, 4);
                    if (child3 != 0) {
                        CLEAR(child3, cursor3, flags3, index3)
                        if (F(child3, u8*, 4) != 0)
                            fn_80014028(F(child3, u8*, 4));
                        gfHeapManager::free(child3);
                    }
                    gfHeapManager::free(child2);
                }
                gfHeapManager::free(child1);
            }
            gfHeapManager::free(node);
        }
    }

    F(self, void*, 0x68) = 0;
    ((ArchiveFlags*)(self + 9))->special = 0;
    ((ArchiveFlags*)(self + 9))->complete = 0;
    fn_80014AF8(self, data, size, heap);
}
