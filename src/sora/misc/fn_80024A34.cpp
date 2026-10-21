#pragma force_active on
namespace Heaps {
enum HeapType { HeapType_Default = 0 };
}

class gfMemoryPool {
public:
    unsigned int getMaxFreeBlockSize();
};

struct gfHeapInfo {
    int unk0;
    gfMemoryPool* pool;
    int unk8;
    int unkC;
};

extern gfHeapInfo g_HeapInfos[];

class gfHeapManager {
public:
    static unsigned int getMaxFreeSize(Heaps::HeapType type);
};

unsigned int gfHeapManager::getMaxFreeSize(Heaps::HeapType type) {
    return g_HeapInfos[(int)type].pool->getMaxFreeBlockSize();
}
