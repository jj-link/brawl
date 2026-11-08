#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
extern "C" void fn_28_1694(u8* self, u8* data, s32 count) {
    s32 limit = count;
    u8* base = self;
    self = (u8*)gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2a);
    for (count = 0; count < limit; count++, data += 4) {
        s32 n = 1;
        if ((u32)data[0] < (u32)data[1]) {
            n = (s32)((u32)data[1] - (u32)data[0] + 1);
        }
        for (s32 j = 0; j < n; j++) {
            void* entry = *(void**)(base + (((u32)data[2] + (u32)j) << 2) + 0x130);
            void* r = nw4r::g3d::ScnMdl::Construct(self, 0, (s32)data[3], *(void**)((u8*)entry + 0x10));
            *(void**)(base + (((u32)data[0] + (u32)j) << 2) + 0x154) = r;
        }
    }
}