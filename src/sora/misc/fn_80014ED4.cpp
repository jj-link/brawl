#include <types.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_handle.h>
#include <string.h>
#pragma force_active on

extern "C" void fn_80014028(void*);
extern "C" void fn_8001429C(void*);
extern "C" void fn_80014AF8(void*, void*, int, void*);

#define FIELD(p,t,o) (*(t*)((u8*)(p)+(o)))
struct EntryFlags { u8 owned : 1; u8 other : 7; };
struct ArchiveFlags { u8 complete : 1; u8 padding : 2; u8 special : 1; u8 low : 4; };
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
extern "C" int fn_80014ED4(u8* self, const char* path, Heaps::HeapType heapType) {
    u32 lastIndex;
    int size;
    void* data;
    int result;
    u8* flag3;
    u8* cursor3;
    u32 index2;
    u8* flag2;
    u8* cursor2;
    u32 index1;
    u8* flag1;
    u8* cursor1;
    u8* node;
    u32 index;
    u8* flag0;
    u8* cursor0;
    u8* child1;
    u8* child2;
    u8* child3;
    void* heap = gfHeapManager::getHeap(heapType);
    ((ArchiveFlags*)(self + 9))->complete = 0;
    result = ((gfFileIOHandle*)(self+0x6c))->read(path, (const void*)heap, 0);
    if (result) {
        void* header = ((gfFileIOHandle*)(self+0x6c))->getBuffer();
        int valid;
        if (FIELD(header,u32,0) == 0x41524300 && (u16)(FIELD(header,u16,4) + 0xff00) <= 1U) valid = 1;
        else valid = 0;
        if (valid) {
            size = ((gfFileIOHandle*)(self+0x6c))->getSize();
            data = ((gfFileIOHandle*)(self+0x6c))->getBuffer();
            if (FIELD(self,void*,0x20) != NULL) {
                if ((self[9] >> 3) & 1) fn_8001429C(self);
                if ((self[9] >> 6) & 1) gfHeapManager::free(FIELD(self,void*,0x20));
                FIELD(self,void*,0x20) = NULL;
            }
            if (FIELD(self,void*,0x1c) != NULL) {
                gfHeapManager::free(FIELD(self,void*,0x1c));
                FIELD(self,void*,0x1c) = NULL;
            } else {
                node = FIELD(self,u8*,0x68);
                if (node != NULL) {
cursor0 = node; flag0 = node + 13;
for (index = 0; index < FIELD(node,u16,2); flag0 += 16, cursor0 += 16, index++) {
if ((*flag0 >> 7) & 1) { gfHeapManager::free(FIELD(cursor0,void*,16)); FIELD(cursor0,void*,16) = NULL; ((EntryFlags*)flag0)->owned = 0; }
}
child1 = FIELD(node,u8*,4);
if (child1 != NULL) {
cursor1 = child1; flag1 = child1 + 13;
for (index1 = 0; index1 < FIELD(child1,u16,2); flag1 += 16, cursor1 += 16, index1++) {
if ((*flag1 >> 7) & 1) { gfHeapManager::free(FIELD(cursor1,void*,16)); FIELD(cursor1,void*,16) = NULL; ((EntryFlags*)flag1)->owned = 0; }
}
child2 = FIELD(child1,u8*,4);
if (child2 != NULL) {
cursor2 = child2; flag2 = child2 + 13;
for (index2 = 0; index2 < FIELD(child2,u16,2); flag2 += 16, cursor2 += 16, index2++) {
if ((*flag2 >> 7) & 1) { gfHeapManager::free(FIELD(cursor2,void*,16)); FIELD(cursor2,void*,16) = NULL; ((EntryFlags*)flag2)->owned = 0; }
}
child3 = FIELD(child2,u8*,4);
if (child3 != NULL) {
cursor3 = child3; flag3 = child3 + 13;
for (lastIndex = 0; lastIndex < FIELD(child3,u16,2); flag3 += 16, cursor3 += 16, lastIndex++) {
if ((*flag3 >> 7) & 1) { gfHeapManager::free(FIELD(cursor3,void*,16)); FIELD(cursor3,void*,16) = NULL; ((EntryFlags*)flag3)->owned = 0; }
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
            fn_80014AF8(self, data, size, heap);
            self[9] |= 0x40;
            ((gfFileIOHandle*)(self+0x6c))->release();
            strncpy((char*)self + 0x28, path, 64);
            ((ArchiveFlags*)(self + 9))->complete = result;
        } else result = 0;
    }
    return result;
}