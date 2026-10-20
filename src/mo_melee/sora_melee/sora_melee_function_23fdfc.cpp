#include <ec/ec_mgr.h>
#include <gf/gf_3d_scene.h>
#include <st/st_common_gimmick.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_80060B1C(void*, u32, u32, void*);

struct Foo {
    char _0[0xC4];
    stCommonGimmick* m_gimmick;
};

extern "C" void fn_27_23FDFC(Foo* self) {
    stCommonGimmick* p = self->m_gimmick;
    if (p) {
        p->setPause(true);
        gfSceneRoot* root = g_gfSceneRoot;
        ((u8*)root)[0x464] |= 2;
        fn_80060B1C(g_ecMgr, 0x2000000, 0xff000000, root);
    }
}
