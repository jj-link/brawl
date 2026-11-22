#include <types.h>
#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on
struct Entry { nw4r::g3d::G3dObj* parent; nw4r::g3d::G3dObj* child; };
struct Task { char pad[0x3c]; unsigned int* vtable; Entry* entries; };
extern unsigned int lbl_2_data_E60[];
extern "C" void fn_801AC6EC(void*);
extern "C" void* __dt__6gfTaskFv(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" Task* fn_2_8148(Task* self, int flag) {
    if (self) {
        self->vtable = lbl_2_data_E60;
        if (self->entries) {
            int offset;
            int i = 0;
            offset = 0;
            for (; i < 2; i++, offset += 8) {
                Entry* entry = (Entry*)((char*)self->entries + offset);
                if (entry->child) {
                    fn_801AC6EC(entry->parent);
                    entry->child->Destroy();
                    entry->child = 0;
                }
                entry = (Entry*)((char*)self->entries + offset);
                if (entry->parent) {
                    entry->parent->Destroy();
                    entry->parent = 0;
                }
            }
            gfHeapManager::free(self->entries);
            self->entries = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
