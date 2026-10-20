#include <ec/ec_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_9A128(ecMgr* mgr, u32 handleId, Vec3f* rot) {
    g_ecMgr->setRot(handleId, rot);
}
