#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
extern char lbl_8046167C[];
void __dl__FPv(void*);
void* fn_80152DC8(void* self, int flag) {
    if (self) {
        void* ptr = *(void**)((char*)self + 0x0C);
        *(void**)((char*)self + 0x08) = lbl_8046167C;
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