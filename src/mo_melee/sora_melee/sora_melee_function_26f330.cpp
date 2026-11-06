#include <types.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern u32 lbl_27_data_57180;

extern "C" s32 fn_27_26F330(void* unused, s32 id, const Vec3f* p1, const Vec3f* p2, u32 flags, s32 idx, f32 scale) {
    Vec3f pos;

    g_ecMgr->pushsetCurrentGroup(lbl_27_data_57180 | flags);
    if (idx >= 0) {
        g_ecMgr->preSetAnmIdx(0, 0, 0, 0, idx, 0);
    }
    pos.m_x = scale;
    pos.m_y = scale;
    pos.m_z = scale;
    s32 handle = g_ecMgr->setEffect((EfID)id, p1, p2, &pos);
    g_ecMgr->popCurrentGroup();
    g_ecMgr->preSetAnmIdx(0, 0, 0, 0, 0, 0);
    return handle;
}
