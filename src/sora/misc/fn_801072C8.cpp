#include "gf/gf_3d_scene.h"
#pragma force_active on

extern "C" s32 fn_80109C88(s32);
extern "C" void fn_801073AC(void*);
extern "C" void fn_800DE360(void*);
extern "C" void fn_8000DB40(void*, int);

extern "C" s32 main__9IfAdvMngrFv(void* self) {
    char* p = (char*)self;
    s32 result = 0;

    if (*(u8*)(p + 0x111) != 0) {
        result = 0;
        s32 temp = fn_80109C88(*(s32*)(p + 0x74));
        switch (temp) {
            case 1: result = 1; break;
            case 3: result = 2; break;
            case 2: result = 3; break;
            case 4: result = 4; break;
        }
    } else {
        fn_801073AC(self);
        fn_800DE360(*(void**)(p + 0x108));
    }

    g_gfSceneRoot->remove(*(nw4r::g3d::ScnMdl**)(p + 0x8));

    if (*(u8*)(p + 0x118) != 0) {
        g_gfSceneRoot->add((gfSceneRoot::LayerType)8, *(nw4r::g3d::ScnMdl**)(p + 0x8));
    }
    if (*(u8*)(p + 0x118) == 1) {
        fn_8000DB40(g_gfSceneRoot, 8);
    }

    return result;
}
