#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>

extern "C" {
void setBGMVol__9sndSystemFbf(void*, bool, float);
void fn_80060E20(void*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void fn_8005EB68(void*, int);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void*, void*);
void fn_8000D7B8(void*);
void fn_800B8A0C(void*, int);
void fn_800AD87C(void*, int);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_27_data_7B538[];
extern const float lbl_27_rodata_61C8;
extern void* g_ecMgr;
extern void* g_gfSceneRoot;
extern void* g_sndSystem;
}

struct ModelBase { char pad[0x5C]; };
class Model : public ModelBase {
public:
    virtual void destroy(int);
};

extern "C" void* fn_27_2C447C(void* self, int deleting) {
    char* s = (char*)self;
    if (self != 0) {
        char* p;
        unsigned int counter;
        *(void**)(s + 0x3C) = lbl_27_data_7B538;
        if (*(unsigned char*)(s + 0x44) != 1) {
            setBGMVol__9sndSystemFbf(g_sndSystem, true, lbl_27_rodata_61C8);
        }
        fn_80060E20(g_ecMgr, 0x04000000, 0xFF000000, 1, 1, 0);
        fn_8005EB68(g_ecMgr, *(int*)(s + 0x54));
        fn_8005EB68(g_ecMgr, 0x136);
        if (*(int*)(s + 0x66C) != 0) *(int*)(s + 0x66C) = 0;
        if (*(int*)(s + 0x670) != 0) *(int*)(s + 0x670) = 0;
        if (*(int*)(s + 0x674) != 0) *(int*)(s + 0x674) = 0;
        if (*(int*)(s + 0x678) != 0) *(int*)(s + 0x678) = 0;
        if (*(int*)(s + 0x67C) != 0) *(int*)(s + 0x67C) = 0;
        {
            char* q = s;
            unsigned int i = 0;
            void* root = g_gfSceneRoot;
            do {
                Model* slot = *(Model**)(q + 0x1AEE0);
                if (slot != 0) {
                    remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(root, *(void**)((char*)slot + 0xC));
                    slot = *(Model**)(q + 0x1AEE0);
                    if (slot != 0) {
                        if (slot != 0) slot->destroy(1);
                        *(void**)(q + 0x1AEE0) = 0;
                    }
                }
                i++;
                q += 4;
            } while (i < 0xB);
        }
        (*(gfTask**)(s + 0x680))->exit();
        *(void**)(s + 0x680) = 0;
        (*(nw4r::g3d::G3dObj**)(s + 0x1AEDC))->Destroy();
        *(void**)(s + 0x1AEDC) = 0;
        if (*(int*)(s + 0x668) != 0) {
            fn_8000D7B8(g_gfSceneRoot);
        }
        if (*(void**)(s + 0x684) != 0) {
            fn_800B8A0C(*(void**)(s + 0x684), 1);
            *(void**)(s + 0x684) = 0;
        }
        if (*(void**)(s + 0x688) != 0) {
            fn_800B8A0C(*(void**)(s + 0x688), 1);
            *(void**)(s + 0x688) = 0;
        }
        if (*(void**)(s + 0x68C) != 0) {
            fn_800B8A0C(*(void**)(s + 0x68C), 1);
            *(void**)(s + 0x68C) = 0;
        }
        if (*(void**)(s + 0x690) != 0) {
            fn_800B8A0C(*(void**)(s + 0x690), 1);
            *(void**)(s + 0x690) = 0;
        }
        if (*(gfTask**)(s + 0x1AF18) != 0) {
            (*(gfTask**)(s + 0x1AF18))->exit();
        }
        if (*(nw4r::g3d::G3dObj**)(s + 0x1AF24) != 0) {
            (*(nw4r::g3d::G3dObj**)(s + 0x1AF24))->Destroy();
        }
        if (*(void**)(s + 0x6A0) != 0) {
            fn_800AD87C(*(void**)(s + 0x6A0), 1);
            *(void**)(s + 0x6A0) = 0;
        }
        p = s + 0x144;
        if (p != 0) {
            counter = 0;
            do {
                if (*(void**)(p + 0x10) != 0) {
                    gfHeapManager::free(*(void**)(p + 0x10));
                    *(void**)(p + 0x10) = 0;
                }
                counter++;
                p += 0x14;
            } while (counter < 0x41);
            __dt__14gfFileIOHandleFv(s + 0x658, -1);
        }
        __dt__14gfFileIOHandleFv(s + 0x48, -1);
        __dt__6gfTaskFv(s, 0);
        if (deleting > 0) {
            __dl__FPv(s);
        }
    }
    return self;
}
