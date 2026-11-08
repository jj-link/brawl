#include <mu/mu_object.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
struct Entry { const char* name; unsigned char begin, end, offset, pad; };
extern Entry lbl_80408C48[];
extern float lbl_805A25C0;
extern "C" void fn_800F1DD4(char* self, nw4r::g3d::ResFile* file, int base, void*, HeapType heap) {
    char* owner = self;
    nw4r::g3d::ResFile* resource = file;
    int animationBase = base;
    HeapType heapType = heap;
    int begin, offset, count, j;
    unsigned char end;
    {
    int i;
    Entry* entry;
    entry = lbl_80408C48;
    i = 0;
    do {
        end = entry->end;
        count = 1;
        if (entry->begin < end) count = end - entry->begin;
        offset = entry->offset;
        begin = entry->begin;
        for (j = 0; count > j; ++j) {
            MuObject* object = MuObject::create(resource, entry->name, offset + animationBase, 0, heapType);
            const char* name = entry->name;
            ((MuObject**)(owner + 0x44))[begin + j] = object;
            object->changeAnimN(name);
            ((MuObject**)(owner + 0x44))[begin + j]->m_modelAnim->setUpdateRate(lbl_805A25C0);
        }
        i++; entry++;
    } while (i < 5);
    }
    void* allocator = gfHeapManager::getMEMAllocator(heapType);
    *(void**)(owner + 0x5c) = nw4r::g3d::ScnMdl::Construct(allocator, 0, 2, *(void**)((char*)*(void**)(owner + 0x48) + 0x10));
}