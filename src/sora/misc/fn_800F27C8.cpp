#include <gf/gf_heap_manager.h>
#include <string.h>
#pragma force_active on

struct Result { unsigned int width, height, size; };
extern "C" int fn_80260730(void*, void*, unsigned int, unsigned char, unsigned char, unsigned int, Result*);
extern "C" int fn_802608BC(void*, void*, unsigned int, void*, unsigned int, unsigned char, unsigned char, unsigned int);

extern "C" void* fn_800F27C8(void* self, void* data, unsigned int size) {
    unsigned char work[0x1c08];
    Result result;
    void* output;
    void* copy = gfHeapManager::alloc(*(Heaps::HeapType*)((char*)self + 0xd4), size, 0x20);
    memcpy(copy, data, size);
    fn_80260730(work, copy, size, 6, 4, 0, &result);
    output = gfHeapManager::alloc(*(Heaps::HeapType*)((char*)self + 0xd4), result.size, 0x20);
    fn_802608BC(work, copy, size, output, result.size, 6, 4, 0);
    gfHeapManager::free(copy);
    return output;
}