#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on
struct Part { char padding[0x5C]; virtual void method(int); };
extern "C" {
extern char lbl_11_data_5C8[];
void fn_800B8A0C(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void* fn_11_368(void* self, int flag) {
    if (self != 0) {
        char* base = (char*)self;
        gfTask* task = *(gfTask**)(base + 0x6078);
        *(char**)(base + 0x3C) = lbl_11_data_5C8;
        if (task != 0) { task->exit(); *(gfTask**)(base + 0x6078) = 0; }
        task = *(gfTask**)(base + 0x606C);
        if (task != 0) { task->exit(); *(gfTask**)(base + 0x606C) = 0; }
        task = *(gfTask**)(base + 0x48);
        if (task != 0) { task->exit(); *(gfTask**)(base + 0x48) = 0; }
        int i;
        char* cursor = base;
        for (i = 0; i < 4; i++, cursor += 4) {
            nw4r::g3d::G3dObj* obj = *(nw4r::g3d::G3dObj**)(cursor + 0x214);
            if (obj != 0) obj->Destroy();
        }
        cursor = base;
        for (i = 0; i < 0x70; i++, cursor += 4) {
            Part* p = *(Part**)(cursor + 0x54);
            if (p != 0) { if (p != 0) p->method(1); }
        }
        nw4r::g3d::G3dObj* obj = *(nw4r::g3d::G3dObj**)(base + 0x50);
        if (obj != 0) obj->Destroy();
        void* ptr = *(void**)(base + 0x6064);
        if (ptr != 0) fn_800B8A0C(ptr, 1);
        cursor = base;
        for (i = 0; i < 3; i++, cursor += 8) {
            void* p = *(void**)(cursor + 0x22C);
            if (p != 0) { gfHeapManager::free(p); *(void**)(cursor + 0x22C) = 0; }
            *(char*)(cursor + 0x230) = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
}