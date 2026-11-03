#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
extern char lbl_804237D4[];
void __dl__FPv(void*);
void* fn_8003CD94(void* self, int flag) {
    if (self) {
        void* ptr = *(void**)((char*)self + 0x80);
        *(void**)((char*)self + 0x50) = lbl_804237D4;
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