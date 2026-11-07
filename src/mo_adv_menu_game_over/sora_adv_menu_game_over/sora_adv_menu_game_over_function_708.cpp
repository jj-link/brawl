#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_task.h>
#include <gf/gf_archive.h>
#pragma force_active on
typedef unsigned char u8;
class MenuObject {
    char pad[0x5c];
public:
    virtual ~MenuObject();
};
extern "C" {
extern u8 lbl_33_data_164[];
extern void* g_efScreen;
void fn_800AD87C(void*, int);
void fn_1_406C(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
void fn_8005D5C8(void*);
void fn_33_5E8(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_800FB7B8(void*, int);
void fn_800FAEB8(void*, int);
void* fn_33_708(u8* object, int deleting) {
    void* h = 0;
    if (object) {
        nw4r::g3d::G3dObj* first = *(nw4r::g3d::G3dObj**)(object + 0x284);
        *(void**)(object + 0x3c) = lbl_33_data_164;
        if (first) first->Destroy();
        u8* cursor = object;
        for (int i = 0; i < *(int*)(object + 0x1c4); cursor += 4, ++i) {
            nw4r::g3d::G3dObj* p = *(nw4r::g3d::G3dObj**)(cursor + 0x288);
            if (p) p->Destroy();
        }
        cursor = object;
        for (int i = 0; i < *(int*)(object + 0x1f0); cursor += 4, ++i) {
            nw4r::g3d::G3dObj* p = *(nw4r::g3d::G3dObj**)(cursor + 0x294);
            if (p) p->Destroy();
        }
        cursor = object;
        for (int i = 0; i < 31; cursor += 4, ++i) {
            MenuObject* p = *(MenuObject**)(cursor + 0x35c);
            if (p) delete p;
        }
        cursor = object;
        for (int i = 0; i < 3; cursor += 4, ++i) {
            MenuObject* p = *(MenuObject**)(cursor + 0x264);
            if (p) delete p;
            p = *(MenuObject**)(cursor + 0x270);
            if (p) delete p;
        }
        if (*(void**)(object + 0x280)) fn_800AD87C(*(void**)(object + 0x280), 1);
        gfArchive* archive = *(gfArchive**)(object + 0x3f0);
        if (archive) {
            delete archive;
            *(gfArchive**)(object + 0x3f0) = 0;
        }
        h = *(void**)(object + 0x3f4);
        if (h) {
            if (h) {
                fn_1_406C(h);
                __dt__14gfFileIOHandleFv(h, -1);
                __dl__FPv(h);
            }
            *(void**)(object + 0x3f4) = 0;
        }
        fn_8005D5C8(g_efScreen);
        __destroy_arr(object + 0x2c0, fn_33_5E8, 0x34, 3);
        if (object + 0x2bc) {
            gfTask* p = *(gfTask**)(object + 0x2bc);
            if (p) p->exit();
            *(gfTask**)(object + 0x2bc) = 0;
        }
        if (object + 0x260) {
            gfTask* p = *(gfTask**)(object + 0x260);
            if (p) p->exit();
            *(gfTask**)(object + 0x260) = 0;
        }
        if (object + 0x25c) delete *(MenuObject**)(object + 0x25c);
        fn_800FB7B8(object + 0x244, -1);
        if (object) fn_800FAEB8(object, 0);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}