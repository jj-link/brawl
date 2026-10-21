#pragma force_active on
// Brawl: gfHeapManager::alloc(Heaps::HeapType, size_t)
// Original: alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl

typedef unsigned long u32;

struct HeapInfo {
    const char* m_name;
    void* m_memoryPool;
    u32 m_size;
    u32 m_arena;
};

extern HeapInfo g_HeapInfos[0x47];

extern "C" void* alloc__12gfMemoryPoolFPvUli(void*, u32, int);

extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int heapType, u32 size) {
    return alloc__12gfMemoryPoolFPvUli(g_HeapInfos[heapType].m_memoryPool, size, 0x20);
}
