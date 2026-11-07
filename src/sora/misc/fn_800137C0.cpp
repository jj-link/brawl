#include <gf/gf_archive_manager.h>
#include <gf/gf_memory_pool.h>
#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSError.h>
#include <string.h>

#pragma force_active on

extern char lbl_804208F0[];
extern char lbl_8042093C[];

extern "C" void fn_80014028(void*);
extern "C" void fn_8001429C(void*);
extern "C" void fn_80014AF8(void*, void*, int, void*);

#define F(p, t, o) (*(t*)((u8*)(p) + (o)))

struct FirstByte {
    unsigned int value : 8;
    unsigned int rest : 24;
};

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

#define CLEAR(node, cursor, flags, index)                               \
    cursor = node;                                                     \
    flags = node + 13;                                                 \
    for (index = 0; index < F(node, u16, 2);                           \
         flags += 16, cursor += 16, index++) {                          \
        if ((*flags >> 7) & 1) {                                       \
            gfHeapManager::free(F(cursor, void*, 16));                 \
            F(cursor, void*, 16) = NULL;                               \
            ((EntryFlags*)flags)->owned = 0;                           \
        }                                                              \
    }

extern "C" gfArchive* fn_800137C0(
    gfArchive* obj, Heaps::HeapType heap, gfArchive* parentObj)
{
    u32 index3;
    void* clonePool;
    void* cloneData;
    int cloneSize;
    u8* flags3;
    u8* cursor3;
    u8* flags2;
    u8* cursor2;
    u32 index2;
    u8* flags1;
    u8* cursor1;
    u32 index1;
    u8* node;
    u8* flags;
    u8* cursor;
    u32 index;
    u8* child1;
    u8* child2;
    u8* child3;
    u8* parent = (u8*)parentObj;
    u8* self = (u8*)obj;

    ((FirstByte*)(self + 8))->value = 1;
    F(self, void*, 0) = NULL;
    F(self, void*, 4) = NULL;
    self[9] = ((self[9] & ~0xc0) | 0x20) & ~0x1e;
    F(self, u16, 10) = 0;
    F(self, u16, 12) = 0;
    F(self, u16, 14) = 0;
    F(self, void*, 16) = parent;
    F(self, void*, 20) = NULL;
    F(self, void*, 24) = NULL;
    F(self, void*, 28) = NULL;
    F(self, void*, 32) = NULL;
    F(self, void*, 104) = NULL;
    F(self, void*, 108) = NULL;
    F(self, int, 112) = 21;
    F(self, int, 116) = 0x10000000;
    F(self, void*, 120) = lbl_8042093C;
    F(self, void*, 124) = self;
    F(self, void*, 20) = gfHeapManager::getHeap(heap);
    self[40] = 0;

    if ((parent[9] >> 7) & 1) {
        cloneSize = F(parent, int, 0x24);
        cloneData =
            gfMemoryPool::alloc(F(self, void*, 0x14), cloneSize, 32);
        memcpy(cloneData, F(parent, void*, 0x20), cloneSize);
        OSReport(lbl_804208F0, parent + 0x28, cloneSize, parent);

        clonePool = F(self, void*, 0x14);
        if (F(self, void*, 0x20) != NULL) {
            if ((self[9] >> 3) & 1)
                fn_8001429C(self);
            if ((self[9] >> 6) & 1)
                gfHeapManager::free(F(self, void*, 0x20));
            F(self, void*, 0x20) = NULL;
        }

        if (F(self, void*, 0x1c) != NULL) {
            gfHeapManager::free(F(self, void*, 0x1c));
            F(self, void*, 0x1c) = NULL;
        } else {
            node = F(self, u8*, 0x68);
            if (node != NULL) {
                CLEAR(node, cursor, flags, index)

                child1 = F(node, u8*, 4);
                if (child1 != NULL) {
                    CLEAR(child1, cursor1, flags1, index1)

                    child2 = F(child1, u8*, 4);
                    if (child2 != NULL) {
                        CLEAR(child2, cursor2, flags2, index2)

                        child3 = F(child2, u8*, 4);
                        if (child3 != NULL) {
                            CLEAR(child3, cursor3, flags3, index3)

                            if (F(child3, u8*, 4) != NULL)
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

        F(self, void*, 0x68) = NULL;
        ((ArchiveFlags*)(self + 9))->special = 0;
        ((ArchiveFlags*)(self + 9))->complete = 0;
        fn_80014AF8(self, cloneData, cloneSize, clonePool);
        strncpy((char*)self + 0x28, (char*)parent + 0x28, 64);
        F(self, void*, 0x10) = NULL;
        self[9] |= 0x40;
    }

    g_gfArchiveManager->pushback(obj);
    return obj;
}
