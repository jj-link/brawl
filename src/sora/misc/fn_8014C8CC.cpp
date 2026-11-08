#include <gf/gf_heap_manager.h>
#include <nt/nt_offline.h>
#pragma force_active on
extern "C" {
extern void* lbl_805A044C;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
}
inline void adjust(unsigned int* field, unsigned int remainder) {
    if (remainder) *(long*)field += 32 - remainder;
}
ntFriendInfo* ntFriendInfo::getInstance() {
    int alignment = 4;
    if (lbl_805A044C == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0xC, 0x2D);
        if (p != 0) {
            unsigned int* sizeField = (unsigned int*)((char*)p + 4);
            *sizeField = 0x2804;
            adjust(sizeField, *sizeField & 31);
            *(void**)p = gfHeapManager::alloc((Heaps::HeapType)0x2D, *sizeField);
            memset(*(void**)p, 0, *sizeField);
            *(char*)((char*)p + 8) = 0;
            *(char*)((char*)p + 9) = 0;
        }
        lbl_805A044C = p;
    }
    return (ntFriendInfo*)lbl_805A044C;
}