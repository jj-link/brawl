#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" void fn_8010A714(void*, const void*, int, void*);
extern "C" void* fn_801AB6CC(MEMAllocator*, void*, int);
extern const int lbl_805A2868;
extern const int lbl_80409378[10];
extern "C" void fn_8010A800(void* self, void* arg1, void* arg2) {
    fn_8010A714(self, &lbl_805A2868, 1, arg1);
    fn_8010A714(self, lbl_80409378, 5, arg2);
    *(void**)((char*)self + 0x110) = fn_801AB6CC(gfHeapManager::getMEMAllocator((Heaps::HeapType)0x28), 0, 7);
}
