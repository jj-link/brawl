#pragma force_active on
struct HeapInfo {
    int unk0;
    int allocator;
    int unk8;
    int unkC;
};

extern HeapInfo g_HeapInfos[];

class Heaps {
public:
    enum HeapType { HEAP_TYPE_MAX = 0x20 };
};

class gfHeapManager {
public:
    static void* getMEMAllocator(Heaps::HeapType type);
};

void* gfHeapManager::getMEMAllocator(Heaps::HeapType type) {
    void* result = 0;
    int p = (&g_HeapInfos[0] + type)->allocator;
    if (p != 0) {
        result = (void*)(p + 0x40);
    }
    return result;
}
