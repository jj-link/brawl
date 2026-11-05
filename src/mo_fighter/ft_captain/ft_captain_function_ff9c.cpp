#include <ec/ec_mgr.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on
extern "C" void fn_8000D234(void*, int, int);
extern "C" void setVisibleGroup__5ecMgrFUlbUlUl(ecMgr*, bool, unsigned long, unsigned long);
extern "C" void fn_80060BB8(ecMgr*, unsigned int, unsigned int);
extern "C" void fn_80060B1C(ecMgr*, unsigned int, unsigned int);
extern int lbl_100_rodata_4C[];
extern "C" void fn_100_FF9C(int flag) {
    gfSceneRoot* root = g_gfSceneRoot;
    unsigned int i = 0;
    for (; i < 4; i++) {
        fn_8000D234(root, lbl_100_rodata_4C[i], flag);
    }
    i = (unsigned int)g_ecMgr;
    if (flag) {
        setVisibleGroup__5ecMgrFUlbUlUl((ecMgr*)i, true, 0x01000020, 0xFF000020);
        fn_80060BB8((ecMgr*)i, 0x01000020, 0xFF000020);
    } else {
        setVisibleGroup__5ecMgrFUlbUlUl((ecMgr*)i, false, 0x01000020, 0xFF000020);
        fn_80060B1C((ecMgr*)i, 0x01000020, 0xFF000020);
    }
}