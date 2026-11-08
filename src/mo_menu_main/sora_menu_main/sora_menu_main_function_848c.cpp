#include <gf/gf_heap_manager.h>
#include <gf/gf_camera.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

extern "C" {
void fn_801AC6EC(void*);
nw4r::g3d::G3dObj* fn_8019CA18(void*, int, int*, int);
void fn_801AC650(void*, nw4r::g3d::G3dObj*);
void fn_801ACB68(void*);
void* fn_801AC554(void*, int);
void fn_80019718(void*, void**);
void fn_80018778(void*);
void fn_80018EC4(void*, void**);
}
extern int lbl_2_rodata_210[];

struct Entry {
    void* object;
    nw4r::g3d::G3dObj* animation;
};
struct Owner {
    char pad[0x40];
    Entry* entries;
};

extern "C" void fn_2_848C(Owner* self, int index, int* resource) {
    Entry* entry;
    void* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2a);
    entry = &self->entries[index];
    if (entry->animation) {
        fn_801AC6EC(entry->object);
        entry->animation->Destroy();
        entry->animation = 0;
    }
    int res = *resource;
    entry->animation = fn_8019CA18(allocator, 0, &res, 0);
    void* obj = entry->object;
    fn_801AC650(obj, entry->animation);
    fn_801ACB68(obj);
    if (index == 1) {
        gfCameraManager* manager = gfCameraManager::getManager();
        gfCamera* camera = manager->getCamera(lbl_2_rodata_210[index]);
        void* value = fn_801AC554(obj, 0);
        fn_80019718(camera, &value);
        fn_80018778(camera);
        void* value2 = fn_801AC554(obj, 0);
        fn_80018EC4(camera, &value2);
    }
}