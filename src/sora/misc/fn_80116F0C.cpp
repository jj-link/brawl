#pragma force_active on
#include <gf/gf_heap_manager.h>

extern "C" void __dl__FPv(void*);

extern "C" void* fn_80116F0C(char* self, int del) {
    if (self) {
        if (self + 0x18) {
            void* p = *(void**)(self + 0x1c);
            if (p) {
                gfHeapManager::free(p);
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
