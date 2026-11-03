#pragma force_active on
#include <types.h>
#include <gf/gf_heap_manager.h>

extern "C" void __dl__FPv(void*);

struct Fn80153498Obj {
    void* unk0;
    u8 unk4;
};

extern "C" void* fn_80153498(Fn80153498Obj* p, int flag) {
    if (p != NULL) {
        if (p->unk4 != 0) {
            void* ptr = p->unk0;
            if (ptr != NULL) {
                gfHeapManager::free(ptr);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
