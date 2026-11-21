#include <types.h>
#include <gf/gf_archive_manager.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" void fn_80014028(void*);
extern "C" void fn_8001429C(void*);
extern "C" void __dl__FPv(void*);

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

#define F(p, t, o) (*(t*)((u8*)(p) + (o)))
#define CLEAR(node, cursor, flags, index) \
    cursor = node; \
    flags = node + 13; \
    for (index = 0; index < F(node, u16, 2); flags += 16, cursor += 16, index++) { \
        if ((*flags >> 7) & 1) { \
            gfHeapManager::free(F(cursor, void*, 16)); \
            F(cursor, void*, 16) = 0; \
            ((EntryFlags*)flags)->owned = 0; \
        } \
    }

extern "C" void* __dt__9gfArchiveFv(void* self, int flag) {
    if (self != 0) {
        u8* b = (u8*)self;
        if (!((b[9] >> 7) & 1) && ((gfFileIOHandle*)(b + 0x6c))->m_request != 0) {
            if (!((gfFileIOHandle*)(b + 0x6c))->isReady()) {
                if (!((gfFileIOHandle*)(b + 0x6c))->isCancelRequested()) {
                    ((gfFileIOHandle*)(b + 0x6c))->cancelRequest();
                }
            }
        }
        if (F(b, void*, 0x20) != 0) {
            if ((b[9] >> 3) & 1) fn_8001429C(b);
            if ((b[9] >> 6) & 1) gfHeapManager::free(F(b, void*, 0x20));
            F(b, void*, 0x20) = 0;
        }
        if (F(b, void*, 0x1c) != 0) {
            gfHeapManager::free(F(b, void*, 0x1c));
            F(b, void*, 0x1c) = 0;
        } else {
            u8* n1 = F(b, u8*, 0x68);
            if (n1 != 0) {
                u32 index4;
                u8* flags4;
                u8* cursor4;
                u8* flags3;
                u8* cursor3;
                u32 index3;
                u8* flags2;
                u8* cursor2;
                u32 index2;
                u8* flags;
                u8* cursor;
                u32 index;
                CLEAR(n1, cursor, flags, index)
                u8* n2 = F(n1, u8*, 4);
                if (n2 != 0) {
                    CLEAR(n2, cursor2, flags2, index2)
                    u8* n3 = F(n2, u8*, 4);
                    if (n3 != 0) {
                        CLEAR(n3, cursor3, flags3, index3)
                        u8* n4 = F(n3, u8*, 4);
                        if (n4 != 0) {
                            CLEAR(n4, cursor4, flags4, index4)
                            if (F(n4, u8*, 4) != 0) fn_80014028(F(n4, u8*, 4));
                            gfHeapManager::free(n4);
                        }
                        gfHeapManager::free(n3);
                    }
                    gfHeapManager::free(n2);
                }
                gfHeapManager::free(n1);
            }
        }
        F(b, void*, 0x68) = 0;
        ((ArchiveFlags*)(b + 9))->special = 0;
        ((ArchiveFlags*)(b + 9))->complete = 0;
        b[9] |= 4;
        g_gfArchiveManager->remove((gfArchive*)self);
        if (b + 0x74 != 0) {
            if (b + 0x74 != 0) F(b, int, 0x74) = 0x20000000;
        }
        ((gfFileIOHandle*)(b + 0x6c))->~gfFileIOHandle();
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}