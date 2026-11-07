#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
extern char lbl_80461668[];
void __dl__FPv(void*);
void* fn_80152F34(void* self, int flag) {
    if (self) {
        void* ptr = *(void**)((char*)self + 0xC);
        *(void**)((char*)self + 0x8) = lbl_80461668;
        if (ptr) {
            gfHeapManager::free(ptr);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
