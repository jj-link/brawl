#include <types.h>
#include <lib/BrawlHeaders/Brawl/Include/gf/gf_heap_manager.h>
#include <lib/BrawlHeaders/Brawl/Include/sr/sr_common.h>
#pragma force_active on

class gfModuleManager {
public:
    Heaps::HeapType m_unk0;
    void* m_unk4;
    void setTempolaryLoadHeap(Heaps::HeapType arg);
};

void gfModuleManager::setTempolaryLoadHeap(Heaps::HeapType arg) {
    m_unk4 = gfHeapManager::getHeap(arg);
    m_unk0 = arg;
}
