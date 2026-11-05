#include <types.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" {
extern char lbl_10_rodata_248[];
extern char lbl_10_rodata_2B8[];
void fn_10_C154(void* self, void* entries, int count, void* resourceFile, void* otherResource, int flag);
}

struct RodataEntry {
    unsigned char first;
    unsigned char begin;
    unsigned char end;
    unsigned char argument;
};

extern "C" void fn_10_C060(char* self, void* resourceFile) {
    int begin;
    int first;
    RodataEntry* entry;
    void* allocator;
    int count;
    int j;
    int i;

    fn_10_C154(self, lbl_10_rodata_248, 0xE, resourceFile, NULL, 0);
    allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2A);
    entry = (RodataEntry*)lbl_10_rodata_2B8;
    for (i = 0; i < 3; i++, entry++) {
        count = entry->end - entry->begin;
        if (count <= 0) {
            count = 1;
        }
        first = entry->first;
        j = 0;
        begin = *((unsigned char*)entry + 1);
        for (; j < count; j++) {
            void* model = nw4r::g3d::ScnMdl::Construct(
                allocator, NULL, entry->argument,
                *(void**)(*(char**)(self + (first + j) * 4 + 0x13C) + 0x10));
            *(void**)(self + (begin + j) * 4 + 0x42C) = model;
        }
    }
}
