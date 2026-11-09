#include <gf/gf_task.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on
typedef unsigned char u8;
class MenuObject {
    u8 padding[0x5C];
public:
    virtual ~MenuObject();
};
extern "C" {
extern u8 lbl_10_data_B4[];
void fn_10_1C704(void*);
void* fn_10_10EF8(void*, int);
void fn_10_11060();
void fn_800B8A0C(void*, int);
void fn_10_3F4(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void* fn_10_434(u8* object, int deleting) {
    if (object) {
        gfTask* prev = *reinterpret_cast<gfTask**>(object + 0x60C);
        *reinterpret_cast<void**>(object + 0x3C) = lbl_10_data_B4;
        if (prev) prev->exit();
        gfTask* task = *reinterpret_cast<gfTask**>(object + 0x614);
        if (task) task->exit();
        task = *reinterpret_cast<gfTask**>(object + 0x68);
        if (task) task->exit();
        task = *reinterpret_cast<gfTask**>(object + 0x62C);
        if (task) task->exit();
        task = *reinterpret_cast<gfTask**>(object + 0x628);
        if (task) {
            fn_10_1C704(task);
            (*reinterpret_cast<gfTask**>(object + 0x628))->exit();
        }
        u8* cursor = object;
        for (int i = 0; i < 4; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x44);
            if (entry) fn_10_10EF8(entry, 1);
        }
        fn_10_11060();
        cursor = object;
        for (int i = 0; i < 4; ++i, cursor += 4) {
            nw4r::g3d::G3dObj* entry = *reinterpret_cast<nw4r::g3d::G3dObj**>(cursor + 0x54);
            if (entry) entry->Destroy();
        }
        cursor = object;
        for (int i = 0; i < 0x38; ++i, cursor += 4) {
            nw4r::g3d::G3dObj* entry = *reinterpret_cast<nw4r::g3d::G3dObj**>(cursor + 0x42C);
            if (entry) entry->Destroy();
        }
        cursor = object;
        for (int i = 0; i < 0xBC; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor + 0x13C);
            if (entry) delete entry;
        }
        void* entry = *reinterpret_cast<void**>(object + 0x5C4);
        if (entry) fn_800B8A0C(entry, 1);
        __destroy_arr(object + 0x50C, fn_10_3F4, 0xC, 0xF);
        __dt__6gfTaskFv(object, 0);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}