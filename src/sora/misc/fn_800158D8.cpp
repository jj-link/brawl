#include <gf/gf_archive.h>
#include <gf/gf_memory_pool.h>
#include <gf/gf_heap_manager.h>
#include <revolution/CX/CXCompression.h>
#include <revolution/OS/OSCache.h>
#include <revolution/OS/OSError.h>
#include <string.h>
#pragma force_active on

extern char lbl_804208F0[];
extern "C" void fn_80014028(void*);
extern "C" void fn_8001429C(void*);
extern "C" void fn_80014AF8(void*, void*, int, void*);

#define FIELD(p,t,o) (*(t*)((u8*)(p)+(o)))

static inline void clearImage(u8* self) {
    if (FIELD(self,void*,0x20) != NULL) {
        if ((self[9] >> 3) & 1) fn_8001429C(self);
        if ((self[9] >> 6) & 1) gfHeapManager::free(FIELD(self,void*,0x20));
        FIELD(self,void*,0x20) = NULL;
    }
}

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

#define CLEAR_NODE(node) \
    u8* cursor = node; \
    u8* flags = node + 13; \
    for (u32 i = 0; i < FIELD(node,u16,2); i++, flags += 16, cursor += 16) { \
        if ((*flags >> 7) & 1) { \
            gfHeapManager::free(FIELD(cursor,void*,16)); \
            FIELD(cursor,void*,16) = NULL; \
            ((EntryFlags*)flags)->owned = 0; \
        } \
    }

static inline void clearNodes1(u8* node) {
    CLEAR_NODE(node)
    u8* next = FIELD(node,u8*,4);
    if (next != NULL) fn_80014028(next);
    gfHeapManager::free(node);
}

static inline void clearNodes2(u8* node) {
    CLEAR_NODE(node)
    u8* next = FIELD(node,u8*,4);
    if (next != NULL) clearNodes1(next);
    gfHeapManager::free(node);
}

static inline void clearNodes3(u8* node) {
    CLEAR_NODE(node)
    u8* next = FIELD(node,u8*,4);
    if (next != NULL) clearNodes2(next);
    gfHeapManager::free(node);
}

static inline void clearNodes4(u8* node) {
    CLEAR_NODE(node)
    u8* next = FIELD(node,u8*,4);
    if (next != NULL) clearNodes3(next);
    gfHeapManager::free(node);
}

extern "C" int update__9gfArchiveFv(u8* self) {
    u32 lastIndex;
    void* clonePool;
    void* cloneData;
    int cloneSize;
    u8* flag3;
    u8* cursor3;
    u32 index2;
    u8* flag2;
    u8* cursor2;
    u32 index1;
    u8* flag1;
    u8* cursor1;
    u8* parent;
    u8* node;
    u32 index;
    u8* flag0;
    u8* cursor0;
    u8* child1;
    u8* child2;
    u8* child3;
    int result = (self[9] >> 7) & 1;
    if (result == 0) {
        if ((u32)((self[9] >> 5) & 1) == 1 && (parent = FIELD(self,u8*,0x10)) != NULL) {
            if ((u32)((parent[9] >> 7) & 1) == 1) {
                cloneSize = FIELD(parent,int,0x24);
                cloneData = gfMemoryPool::alloc(FIELD(self,void*,0x14), cloneSize, 32);
                memcpy(cloneData, FIELD(parent,void*,0x20), cloneSize);
                OSReport(lbl_804208F0, parent + 0x28, cloneSize, parent);
                clonePool = FIELD(self,void*,0x14);
                clearImage(self);
                if (FIELD(self,void*,0x1c) != NULL) {
                    gfHeapManager::free(FIELD(self,void*,0x1c));
                    FIELD(self,void*,0x1c) = NULL;
                } else {
                    node = FIELD(self,u8*,0x68);
                    if (node != NULL) {
cursor0 = node;
flag0 = node + 13;
for (index = 0; index < FIELD(node,u16,2); flag0 += 16, cursor0 += 16, index++) {
if ((*flag0 >> 7) & 1) {
gfHeapManager::free(FIELD(cursor0,void*,16));
FIELD(cursor0,void*,16) = NULL;
((EntryFlags*)flag0)->owned = 0;
}
}
child1 = FIELD(node,u8*,4);
if (child1 != NULL) {
cursor1 = child1;
flag1 = child1 + 13;
for (index1 = 0; index1 < FIELD(child1,u16,2); flag1 += 16, cursor1 += 16, index1++) {
if ((*flag1 >> 7) & 1) {
gfHeapManager::free(FIELD(cursor1,void*,16));
FIELD(cursor1,void*,16) = NULL;
((EntryFlags*)flag1)->owned = 0;
}
}
child2 = FIELD(child1,u8*,4);
if (child2 != NULL) {
cursor2 = child2;
flag2 = child2 + 13;
for (index2 = 0; index2 < FIELD(child2,u16,2); flag2 += 16, cursor2 += 16, index2++) {
if ((*flag2 >> 7) & 1) {
gfHeapManager::free(FIELD(cursor2,void*,16));
FIELD(cursor2,void*,16) = NULL;
((EntryFlags*)flag2)->owned = 0;
}
}
child3 = FIELD(child2,u8*,4);
if (child3 != NULL) {
cursor3 = child3;
flag3 = child3 + 13;
for (lastIndex = 0; lastIndex < FIELD(child3,u16,2); flag3 += 16, cursor3 += 16, lastIndex++) {
if ((*flag3 >> 7) & 1) {
gfHeapManager::free(FIELD(cursor3,void*,16));
FIELD(cursor3,void*,16) = NULL;
((EntryFlags*)flag3)->owned = 0;
}
}
if (FIELD(child3,u8*,4) != NULL) fn_80014028(FIELD(child3,u8*,4));
gfHeapManager::free(child3);
}
gfHeapManager::free(child2);
}
gfHeapManager::free(child1);
}
gfHeapManager::free(node);

}
                }
                FIELD(self,void*,0x68) = NULL;
                ((ArchiveFlags*)(self + 9))->special = 0;
                ((ArchiveFlags*)(self + 9))->complete = 0;
                fn_80014AF8(self, cloneData, cloneSize, clonePool);
                strncpy((char*)self + 0x28, (char*)parent + 0x28, 64);
                FIELD(self,void*,0x10) = NULL;
                self[9] |= 0x40;
            }
        } else if ((FIELD(self,s32,8) >> 24) == 1 &&
                   FIELD(self,void*,0x6c) != NULL &&
                   ((gfFileIOHandle*)(self+0x6c))->isReady()) {
            int status = ((gfFileIOHandle*)(self+0x6c))->getReturnStatus();
            FIELD(self,int,0x70) = status;
            if (status == 0 && !((gfFileIOHandle*)(self+0x6c))->isCanceled() && !((gfFileIOHandle*)(self+0x6c))->isCancelRequested()) {
                void* header = ((gfFileIOHandle*)(self+0x6c))->getBuffer();
                u32 valid;
                if (FIELD(header,u32,0) == 0x41524300 &&
                    (u16)(FIELD(header,u16,4) + 0xff00) <= 1U) valid = 1;
                else valid = 0;
                if (valid == 1 || (u32)((self[9] >> 1) & 1) == 1) {
                    void* pool = FIELD(self,void*,0x14);
                    if (pool == NULL) pool = (void*)((gfFileIOHandle*)(self+0x6c))->getPool();
                    int size;
                    u32 unpackedSize;
                    void* compressed;
                    void* data = ((gfFileIOHandle*)(self+0x6c))->getBuffer();
                    size = ((gfFileIOHandle*)(self+0x6c))->getSize();
                    if ((u32)((self[9] >> 1) & 1) == 1) {
                        unpackedSize = CXGetUncompressedSize(data);
                        compressed = gfMemoryPool::alloc(FIELD(self,void*,0x18), size, 32);
                        memcpy(compressed, data, size);
                        gfHeapManager::free(data);
                        data = gfMemoryPool::alloc(pool, unpackedSize, 32);
                        CXUncompressLZ(compressed, data);
                        DCFlushRange(data, unpackedSize);
                        gfHeapManager::free(compressed);
                        size = unpackedSize;
                        FIELD(self,void*,0x1c) = gfMemoryPool::alloc(FIELD(self,void*,0x14), 0x800, 32);
                    }
                    clearImage(self);
                    fn_80014AF8(self, data, size, pool);
                }
                ((gfFileIOHandle*)(self+0x6c))->release();
            }
            self[9] |= 0x80;
        } else {
            result = 0;
        }
    }
    return result;
}
