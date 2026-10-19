#include <types.h>
#pragma force_active on

namespace Heaps {
enum HeapType { HEAP_6 = 6 };
}

class gfHeapManager {
public:
    static void* getHeap(Heaps::HeapType heap);
};

class gfHomeMenu {
public:
    void setBan(u32 a, u32 b);
};

extern "C" void fn_800C753C();
extern "C" void fn_80025A1C(void*);
extern "C" void fn_800377D4(gfHomeMenu*);

extern void* g_muWifiInterfaceTask;
extern gfHomeMenu* g_gfHomeMenu;

extern "C" {
void fn_1_3D450() {
    if (g_muWifiInterfaceTask != nullptr) {
        fn_800C753C();
        fn_80025A1C(gfHeapManager::getHeap(Heaps::HEAP_6));
    }
    if (g_gfHomeMenu != nullptr) {
        g_gfHomeMenu->setBan(0, 2);
        fn_800377D4(g_gfHomeMenu);
    }
}
}
