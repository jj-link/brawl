#pragma force_active on
#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <ut/ut_list.h>
#include <nw4r/g3d/g3d_obj.h>
#include <nw4r/g3d/g3d_scngroup.h>

extern "C" {
void fn_80075F1C(void*, unsigned int, int);
void fn_8000D7B8(void*);
void fn_800B8A0C(void*, int);
void fn_800FABEC(void*, void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
extern void* g_sndSystem;
extern char* g_gfSceneRoot;
extern char lbl_8045B3B0[];
extern char lbl_8045B4B8[];
extern char lbl_8045C4BC[];
extern utList lbl_8049E550;
}
class gfPad5CProbe { public: char pad[0x5C]; };
class gfVCallProbe : public gfPad5CProbe {
public:
    virtual void f(int);
};

inline void clearSceneGroup() {
        nw4r::g3d::ScnGroup* group = *(nw4r::g3d::ScnGroup**)(g_gfSceneRoot + 0x450);
        while (group->sceneItemsCount != 0) {
            if (group->sceneItemsCount != 0) {
                group->Remove((u32)(group->sceneItemsCount - 1));
            }
        }
}

extern "C" void* fn_800EE260(void* self, int arg1) {
    char* s = (char*)self;
    if (self != 0) {
        unsigned int i;
        char* p;
        *(void**)(s + 0x3C) = lbl_8045B3B0;
        unsigned int sound = *(unsigned int*)(s + 0x278);
        if (sound != 0xFFFFFFFF) {
            fn_80075F1C(g_sndSystem, sound, 0);
        }
        clearSceneGroup();
        p = s;
        i = 0;
        do {
            nw4r::g3d::G3dObj* o = *(nw4r::g3d::G3dObj**)(p + 0x188);
            if (o != 0) {
                o->Destroy();
                *(void**)(p + 0x188) = 0;
            }
            i++;
            p += 4;
        } while (i < 2);
        p = s;
        i = 0;
        do {
            void* o = *(void**)(p + 0x5C);
            if (o != 0) {
                if (o != 0) {
                    ((gfVCallProbe*)o)->f(1);
                }
                *(void**)(p + 0x5C) = 0;
            }
            i++;
            p += 4;
        } while (i < 0x4B);
        fn_8000D7B8(g_gfSceneRoot);
        fn_800B8A0C(*(void**)(s + 0x198), 1);
        fn_800B8A0C(*(void**)(s + 0x194), 1);
        (*(gfTask**)(s + 0x190))->exit();
        *(void**)(s + 0x190) = 0;
        if (*(gfTask**)(s + 0x21C) != 0) {
            (*(gfTask**)(s + 0x21C))->exit();
            *(void**)(s + 0x21C) = 0;
        }
        if (*(void**)(s + 0x254) != 0) {
            gfHeapManager::free(*(void**)(s + 0x254));
        }

        if ((void*)(s + 0x204) != 0) {
            *(void**)(s + 0x210) = lbl_8045B4B8;
            fn_800FABEC(s + 0x204, lbl_8045B4B8);
            ((gfFileIOHandle*)(s + 0x214))->release();
            __dt__14gfFileIOHandleFv(s + 0x214, -1);

            if ((void*)(s + 0x204) != 0) {
                if ((void*)(s + 0x204) != 0) {
                    lbl_8049E550.removeExist((utListNode*)(s + 0x204));
                    *(void**)(s + 0x20C) = 0;
                    if ((void*)(s + 0x204) != 0) {
                        if (*(void**)(s + 0x20C) != 0) {
                            ((utList*)0)->removeExist((utListNode*)(s + 0x204));
                            *(void**)(s + 0x20C) = 0;
                        }
                    }
                }
            }

        }

        if ((void*)(s + 0x1D0) != 0) {
            *(void**)(s + 0x200) = lbl_8045C4BC;
            *(char**)(s + 0x1E0) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x1E4, lbl_8045C4BC);
            *(int*)(s + 0x1D0) = 0;
            *(signed char*)(s + 0x1FC) = 0;

        if ((void*)(s + 0x1E4) != 0) {
            *(void**)(s + 0x1F0) = lbl_8045B4B8;
            fn_800FABEC(s + 0x1E4, lbl_8045B4B8);
            ((gfFileIOHandle*)(s + 0x1F4))->release();
            __dt__14gfFileIOHandleFv(s + 0x1F4, -1);

            if ((void*)(s + 0x1E4) != 0) {
                if ((void*)(s + 0x1E4) != 0) {
                    lbl_8049E550.removeExist((utListNode*)(s + 0x1E4));
                    *(void**)(s + 0x1EC) = 0;
                    if ((void*)(s + 0x1E4) != 0) {
                        if (*(void**)(s + 0x1EC) != 0) {
                            ((utList*)0)->removeExist((utListNode*)(s + 0x1E4));
                            *(void**)(s + 0x1EC) = 0;
                        }
                    }
                }
            }

        }


            if ((void*)(s + 0x1D4) != 0) {
                if ((void*)(s + 0x1D4) != 0) {
                    lbl_8049E550.removeExist((utListNode*)(s + 0x1D4));
                    *(void**)(s + 0x1DC) = 0;
                    if ((void*)(s + 0x1D4) != 0) {
                        if (*(void**)(s + 0x1DC) != 0) {
                            ((utList*)0)->removeExist((utListNode*)(s + 0x1D4));
                            *(void**)(s + 0x1DC) = 0;
                        }
                    }
                }
            }

        }

        if ((void*)(s + 0x19C) != 0) {
            *(void**)(s + 0x1CC) = lbl_8045C4BC;
            *(char**)(s + 0x1AC) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x1B0, lbl_8045C4BC);
            *(int*)(s + 0x19C) = 0;
            *(signed char*)(s + 0x1C8) = 0;

        if ((void*)(s + 0x1B0) != 0) {
            *(void**)(s + 0x1BC) = lbl_8045B4B8;
            fn_800FABEC(s + 0x1B0, lbl_8045B4B8);
            ((gfFileIOHandle*)(s + 0x1C0))->release();
            __dt__14gfFileIOHandleFv(s + 0x1C0, -1);

            if ((void*)(s + 0x1B0) != 0) {
                if ((void*)(s + 0x1B0) != 0) {
                    lbl_8049E550.removeExist((utListNode*)(s + 0x1B0));
                    *(void**)(s + 0x1B8) = 0;
                    if ((void*)(s + 0x1B0) != 0) {
                        if (*(void**)(s + 0x1B8) != 0) {
                            ((utList*)0)->removeExist((utListNode*)(s + 0x1B0));
                            *(void**)(s + 0x1B8) = 0;
                        }
                    }
                }
            }

        }


            if ((void*)(s + 0x1A0) != 0) {
                if ((void*)(s + 0x1A0) != 0) {
                    lbl_8049E550.removeExist((utListNode*)(s + 0x1A0));
                    *(void**)(s + 0x1A8) = 0;
                    if ((void*)(s + 0x1A0) != 0) {
                        if (*(void**)(s + 0x1A8) != 0) {
                            ((utList*)0)->removeExist((utListNode*)(s + 0x1A0));
                            *(void**)(s + 0x1A8) = 0;
                        }
                    }
                }
            }

        }

        __dt__6gfTaskFv(s, 0);
        if (arg1 > 0) {
            operator delete(s);
        }
    }
    return self;
}
