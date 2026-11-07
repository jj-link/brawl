#include <gf/gf_heap_manager.h>
#include <if/if_wifipr_mngr.h>
#pragma force_active on
extern "C" {
void fn_800FC3D8(void*);
void fn_800FC3E4(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* fn_801AB6CC(MEMAllocator*, void*, int);
}
struct Flags { unsigned char bit : 1; };
extern "C" void* fn_800FC300(void* self) {
    unsigned char* p = (unsigned char*)self;
    *(int*)(p + 8) = 0;
    ((Flags*)p)->bit = 0;
    *(int*)(p + 0xc) = 0;
    *(int*)(p + 0x10) = 0;
    *(int*)(p + 0x14) = 0;
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x38) = 0;
    *(int*)(p + 0x3c) = 0;
    *(int*)(p + 0x40) = 0;
    *(int*)(p + 0x44) = 0;
    *(int*)(p + 0x48) = 0;
    *(int*)(p + 0x4c) = 0;
    p[0x50] = 0;
    __construct_array(p + 0x54, fn_800FC3D8, fn_800FC3E4, 4, 5);
    *(int*)(p + 8) = 0;
    *(int*)(p + 0xc) = 0;
    *(int*)(p + 0x10) = 0;
    *(void**)(p + 0x14) = fn_801AB6CC(gfHeapManager::getMEMAllocator((Heaps::HeapType)0x28), 0, 4);
    *(int*)(p + 0x1c) = 0;
    *(int*)(p + 0x20) = 0;
    *(int*)(p + 0x24) = 0;
    *(int*)(p + 0x28) = 0;
    *(int*)(p + 0x2c) = 0;
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x34) = 0;
    g_IfWifiprMngr = (IfWifiprMngr*)self;
    return self;
}