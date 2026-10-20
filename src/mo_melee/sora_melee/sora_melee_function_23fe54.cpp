#include <ec/ec_mgr.h>
#include <gf/gf_3d_scene.h>
#include <st/st_common_gimmick.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_80060BB8(void* mgr, u32 a, u32 b);

extern "C" void fn_27_23FE54(void* self) {
    stCommonGimmick* gimmick = *(stCommonGimmick**)((u8*)self + 0xC4);
    if (gimmick) {
        gimmick->setPause(false);
        u8* scene = (u8*)g_gfSceneRoot;
        scene[0x464] = scene[0x464] & ~0x2;
        fn_80060BB8(g_ecMgr, 0x02000000, 0xFF000000);
    }
}
