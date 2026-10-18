#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

class gfHomeMenu {
public:
    void setBan(u32, u32);
};

namespace Heaps {
enum HeapType { HEAP_6 = 6 };
}

class gfHeapManager {
public:
    static void* getHeap(Heaps::HeapType);
};

extern "C" {
extern gfHomeMenu* g_gfHomeMenu;
extern void* g_muWifiInterfaceTask;
extern u32 lbl_805A0448;
extern const char lbl_2_data_4C5C[];
void fn_800377D4(gfHomeMenu*);
void fn_80025A1C(void*);
int OSReport(const char*, ...);
}

extern "C" u32 fn_2_39EB4(u8* self) {
    u32 r31 = *(u32*)(self + 0x138);
    if (self[0x1f1] != 0) {
        if (g_muWifiInterfaceTask == 0) {
            g_gfHomeMenu->setBan(0, 2);
            fn_800377D4(g_gfHomeMenu);
        }
        r31 = 0xc;
    } else {
        if (lbl_805A0448 == 0) {
            self[0x1f1] = 1;
            fn_80025A1C(gfHeapManager::getHeap(Heaps::HEAP_6));
        } else {
            OSReport(lbl_2_data_4C5C);
        }
    }
    return r31;
}
