#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_3d_scene.h>
#include <gf/gf_3d_scene_event.h>
#include <gf/gf_task.h>
#pragma force_active on
extern "C" {
extern char lbl_804206B0[];
void fn_801AC6EC(void*);
void fn_8000E82C(void*, int);
void fn_8000CEE8(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* __dt__20gfSceneRootEventListFv(void*, short);
void* __dt__6gfTaskFv(void*, short);
void __dl__FPv(void*);
}
extern "C" void* fn_8000CF28(char* p, int flag) {
    if (p) {
        *(void**)(p + 0x3c) = lbl_804206B0;
        if (*(void**)(p + 0x54)) {
            fn_801AC6EC(*(void**)(p + 0x40));
            (*(nw4r::g3d::G3dObj**)(p + 0x54))->Destroy();
        }
        if (*(void**)(p + 0x4c)) *(void**)(p + 0x4c) = 0;
        *(void**)(p + 0x54) = 0;
        *(void**)(p + 0x58) = 0;
        if (*(void**)(p + 0x5c)) {
            fn_801AC6EC(*(void**)(p + 0x44));
            (*(nw4r::g3d::G3dObj**)(p + 0x5c))->Destroy();
        }
        if (*(void**)(p + 0x50)) *(void**)(p + 0x50) = 0;
        *(void**)(p + 0x5c) = 0;
        (*(nw4r::g3d::G3dObj**)(p + 0x40))->Destroy();
        (*(nw4r::g3d::G3dObj**)(p + 0x44))->Destroy();
        (*(nw4r::g3d::G3dObj**)(p + 0x48))->Destroy();
        (*(nw4r::g3d::G3dObj**)(p + 0x48))->Destroy();
        g_gfSceneRoot = 0;
        __dt__20gfSceneRootEventListFv(p + 0x468, -1);
        __destroy_arr(p + 0x38c, fn_8000E82C, 0x18, 9);
        __destroy_arr(p + 0xe4, fn_8000CEE8, 0x44, 10);
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}