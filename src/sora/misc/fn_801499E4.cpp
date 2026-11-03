#pragma force_active on
#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSMutex.h>

extern "C" OSMutex lbl_8049EC78;

extern "C" void* fn_801499E4(void* unused, size_t size) {
    if (size != 0) {
        OSLockMutex(&lbl_8049EC78);
        void* ptr = gfHeapManager::alloc((Heaps::HeapType)6, size);
        OSUnlockMutex(&lbl_8049EC78);
        return ptr;
    }
    return 0;
}
