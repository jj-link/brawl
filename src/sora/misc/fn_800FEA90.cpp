#include <types.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" {
void fn_800FEB64(void* self, void* table, int count, void* arg, int flag);
}

extern u8 lbl_80409128[];

struct Entry {
    u16 begin;
    u16 end;
    u16 first;
    u8 argument;
    u8 pad;
};

extern Entry lbl_80409180[];

extern "C" void fn_800FEA90(void* p_self, void* arg) {
    char* self = (char*)p_self;
    int begin;
    int first;
    void* allocator;
    Entry* entry;
    int count;
    int j;
    int i;

    fn_800FEB64(self, lbl_80409128, 0xB, arg, 0);
    entry = lbl_80409180;
    allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x28);
    for (i = 0; i < 5; i++, entry++) {
        count = ((u16*)entry)[1] - ((u16*)entry)[0];
        if (count <= 0) {
            count = 1;
        }
        first = entry->first;
        j = 0;
        begin = entry->begin;
        for (; j < count; j++) {
            *(void**)(self + (begin + j) * 4 + 0xF0) =
                nw4r::g3d::ScnMdl::Construct(
                    allocator, 0, entry->argument,
                    *(void**)(*(char**)(self + (first + j) * 4 + 0x4) + 0x10));
        }
    }
}
