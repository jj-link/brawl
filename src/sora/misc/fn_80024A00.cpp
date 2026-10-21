#pragma force_active on
typedef unsigned long u32;
typedef int s32;
typedef unsigned long size_t;

class gfMemoryPool;

namespace Heaps {
enum HeapType {
    // placeholder
};
}

struct HeapInfo {
    const char* m_name;
    gfMemoryPool* m_memoryPool;
    u32 m_size;
    u32 m_arena;
};
extern HeapInfo g_HeapInfos[];

class gfMemoryPool {
public:
    static void* alloc(void* heapAddr, size_t size, s32 align);
};

class gfHeapManager {
public:
    static void* alloc(Heaps::HeapType heapType, size_t size, long align);
};

void* gfHeapManager::alloc(Heaps::HeapType heapType, size_t size, long align) {
    return gfMemoryPool::alloc(g_HeapInfos[heapType].m_memoryPool, size, align);
}
