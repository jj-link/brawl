#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
extern char lbl_80423830[];
void __dl__FPv(void*);
void* fn_8003CE74(void* self, int flag) {
    if (self) {
        void* ptr = *(void**)((char*)self + 0x5C);
        *(void**)((char*)self + 0x50) = lbl_80423830;
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