#include <gf/gf_memory_pool.h>
#include <string.h>
#include <types.h>
#pragma force_active on

extern "C" void* fn_80025EDC(gfMemoryPool* pool, u32 size, u32 align) {
    void* ptr = gfMemoryPool::alloc(pool, size, (int)align);
    if (ptr) {
        memset(ptr, 0, size);
    }
    return ptr;
}
