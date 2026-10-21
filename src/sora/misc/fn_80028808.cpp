#include <gf/gf_heap_manager.h>
#pragma force_active on

extern "C" void* fn_80028808(size_t size) {
    return gfHeapManager::alloc((Heaps::HeapType)7, size, 32);
}