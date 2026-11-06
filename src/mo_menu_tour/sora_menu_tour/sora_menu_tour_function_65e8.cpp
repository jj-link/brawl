#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_archive.h>
#include <gm/gm_global.h>

extern "C" {
void fn_800B8A0C(void*, int);
void fn_3_468(void*, int);
void __dt__9gfArchiveFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_3_data_AA0[];
}
struct ModelBase { char pad[0x5C]; };
class Model : public ModelBase {
public:
    virtual void destroy(int);
};
extern "C" void* fn_3_65E8(void* self, int deleting) {
    char* s = (char*)self;
    if (self != 0) {
        gfFileIOHandle* q;
        *(void**)(s + 0x3C) = lbl_3_data_AA0;
        {
            char* p = s;
            unsigned int i = 0;
            do {
                nw4r::g3d::G3dObj* o = *(nw4r::g3d::G3dObj**)(p + 0x91C);
                if (o != 0) {
                    o->Destroy();
                    *(void**)(p + 0x91C) = 0;
                }
                i++;
                p += 4;
            } while (i < 0x28);
        }
        {
            unsigned int i = 0;
            char* p = s;
            do {
                Model* o = *(Model**)(p + 0x610);
                if (o != 0) {
                    if (o != 0) o->destroy(1);
                    *(void**)(p + 0x610) = 0;
                }
                i++;
                p += 4;
            } while (i < 0xC3);
        }
        {
            unsigned int i = 0;
            q = (gfFileIOHandle*)(s + 0xAF8);
            do {
                gfHeapManager::free(q->getBuffer());
                q->release();
                i++;
                q++;
            } while (i < 8);
        }
        __dt__9gfArchiveFv(*(void**)(s + 0xAE4), 1);
        __dt__9gfArchiveFv(*(void**)(s + 0xAE8), 1);
        fn_800B8A0C(*(void**)(s + 0xF8), 1);
        fn_800B8A0C(*(void**)(s + 0x100), 1);
        fn_800B8A0C(*(void**)(s + 0xFC), 1);
        fn_3_468(*(void**)(s + 0x9C0), 1);
        (*(gfTask**)(s + 0x9BC))->exit();
        *(void**)(s + 0x9BC) = 0;
        (*(gfTask**)(s + 0x9F8))->exit();
        *(void**)(s + 0x9F8) = 0;
        (*(gfTask**)(s + 0x40))->exit();
        *(void**)(s + 0x40) = 0;
        *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x2C) + 0x509) = *(unsigned char*)(s + 0x604);
        *(int*)(*(char**)((char*)g_GameGlobal + 0x2C) + 0x50C) = *(int*)(s + 0x9F4);
        __destroy_arr(s + 0xAF8, __dt__14gfFileIOHandleFv, 4, 8);
        __dt__6gfTaskFv(s, 0);
        if (deleting > 0) __dl__FPv(s);
    }
    return self;
}