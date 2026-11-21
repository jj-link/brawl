#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <string.h>

#pragma force_active on

extern "C" int fn_8001F084(const char*);
extern "C" void fn_8001429C(void*);
extern "C" void fn_80014028(void*);
extern u8 lbl_8059FF98;

#define FIELD(p, t, o) (*(t*)((u8*)(p) + (o)))

struct StateWord {
    u32 state : 8;
    u32 rest : 24;
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

extern "C" int fn_80015530(u8* self, const char* name, void* pool, int cached) {
    u32 i;
    u8* flags3;
    u8* cursor3;
    u8* flags2;
    u8* cursor2;
    u8* flags1;
    u8* cursor1;
    u8* node;
    u8* flags0;
    u8* cursor0;
    u8* child1;
    u8* child2;
    u8* child3;
    u8* result = NULL;
    int retval = 0;
    bool readResult;

    if (!fn_8001F084(name)) {
        FIELD(self, int, 0x70) = 0x11;
    } else {
        ((ArchiveFlags*)(self + 9))->complete = 0;
        ((StateWord*)(self + 8))->state = 1;
        strncpy((char*)self + 0x28, name, 0x40);

        if (lbl_8059FF98) {
            readResult = ((gfFileIOHandle*)(self + 0x6c))->read(name, pool, 0);
        } else {
            if (FIELD(self, void*, 0x20)) {
                if ((self[9] >> 3) & 1)
                    fn_8001429C(self);
                if ((self[9] >> 6) & 1)
                    gfHeapManager::free(FIELD(self, void*, 0x20));
                FIELD(self, void*, 0x20) = NULL;
            }

            if (FIELD(self, void*, 0x1c)) {
                gfHeapManager::free(FIELD(self, void*, 0x1c));
                FIELD(self, void*, 0x1c) = NULL;
            } else {
                node = FIELD(self, u8*, 0x68);
                if (node) {
                    cursor0 = node;
                    flags0 = node + 13;
                    for (i = 0; i < FIELD(node, u16, 2);
                         flags0 += 16, cursor0 += 16, i++) {
                        if ((*flags0 >> 7) & 1) {
                            gfHeapManager::free(FIELD(cursor0, void*, 16));
                            FIELD(cursor0, void*, 16) = NULL;
                            ((EntryFlags*)flags0)->owned = 0;
                        }
                    }

                    child1 = FIELD(node, u8*, 4);
                    if (child1) {
                        cursor1 = child1;
                        flags1 = child1 + 13;
                        for (i = 0; i < FIELD(child1, u16, 2);
                             flags1 += 16, cursor1 += 16, i++) {
                            if ((*flags1 >> 7) & 1) {
                                gfHeapManager::free(FIELD(cursor1, void*, 16));
                                FIELD(cursor1, void*, 16) = NULL;
                                ((EntryFlags*)flags1)->owned = 0;
                            }
                        }

                        child2 = FIELD(child1, u8*, 4);
                        if (child2) {
                            cursor2 = child2;
                            flags2 = child2 + 13;
                            for (i = 0; i < FIELD(child2, u16, 2);
                                 flags2 += 16, cursor2 += 16, i++) {
                                if ((*flags2 >> 7) & 1) {
                                    gfHeapManager::free(FIELD(cursor2, void*, 16));
                                    FIELD(cursor2, void*, 16) = NULL;
                                    ((EntryFlags*)flags2)->owned = 0;
                                }
                            }

                            result = FIELD(child2, u8*, 4);
                            child3 = result;
                            if (child3) {
                                cursor3 = child3;
                                flags3 = child3 + 13;
                                for (i = 0; i < FIELD(child3, u16, 2);
                                     flags3 += 16, cursor3 += 16, i++) {
                                    if ((*flags3 >> 7) & 1) {
                                        gfHeapManager::free(FIELD(cursor3, void*, 16));
                                        FIELD(cursor3, void*, 16) = NULL;
                                        ((EntryFlags*)flags3)->owned = 0;
                                    }
                                }

                                if (FIELD(child3, u8*, 4))
                                    fn_80014028(FIELD(child3, u8*, 4));
                                gfHeapManager::free(child3);
                            }
                            gfHeapManager::free(child2);
                        }
                        gfHeapManager::free(child1);
                    }
                    gfHeapManager::free(node);
                }
            }

            FIELD(self, void*, 0x68) = NULL;
            ((ArchiveFlags*)(self + 9))->special = 0;
            ((ArchiveFlags*)(self + 9))->complete = 0;
            ((gfFileIOHandle*)(self + 0x6c))->setNotify(self + 0x74);

            if (cached)
                readResult = ((gfFileIOHandle*)(self + 0x6c))
                                 ->readRequestCached(name, pool, 0, 0);
            else
                readResult = ((gfFileIOHandle*)(self + 0x6c))
                                 ->readRequest(name, pool, 0, 0);
        }
        retval = (int)readResult;
    }

    return retval;
}
