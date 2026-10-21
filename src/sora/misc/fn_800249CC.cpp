#pragma force_active on
class Heaps {
public:
    enum HeapType { HeapType_Dummy = 0 };
};

extern "C" char g_HeapInfos[];

class gfHeapManager {
public:
    static void* getHeap(Heaps::HeapType id);
};

void* gfHeapManager::getHeap(Heaps::HeapType id) {
    return *(void**)(g_HeapInfos + ((int)id << 4) + 4);
}
