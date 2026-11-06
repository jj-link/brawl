#include <gf/gf_3d_scene.h>
#pragma force_active on

extern "C" void fn_8000E590(void*, int, unsigned);

extern "C" int* fn_800FB7B8(int* p, int flag) {
    if (p) {
        fn_8000E590(g_gfSceneRoot, *p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
