#include <types.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_memory_pool.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

struct Resource { int value; };
struct Obj {
    u8 pad0[0x44];
    void* field44;
    u8 pad48[8];
    Resource field50;
    u8 pad54[8];
    nw4r::g3d::G3dObj* field5C;
};

extern "C" void fn_801AC6EC(void*);
extern "C" nw4r::g3d::G3dObj* fn_8019CA18(void*, int*, Resource*, int);
extern "C" void fn_801AC650(void*, nw4r::g3d::G3dObj*);

extern "C" void fn_8000D6DC(Obj* self, Resource* resource) {
    if (self->field50.value != 0) {
        if (self->field5C != 0) {
            fn_801AC6EC(self->field44);
            self->field5C->Destroy();
        }
        if (self->field50.value != 0) {
            self->field50.value = 0;
        }
        self->field5C = 0;
    }
    if (resource->value != 0) {
        self->field50 = *resource;
        void* allocator;
        if (g_HeapInfos[40].m_name == 0) {
            allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2A);
        } else {
            allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x28);
        }
        int size;
        Resource value = *resource;
        nw4r::g3d::G3dObj* obj = fn_8019CA18(allocator, &size, &value, 0);
        self->field5C = obj;
        fn_801AC650(self->field44, obj);
    }
}
