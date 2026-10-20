#include <types.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" void fn_27_9A134(ecMgr*, u32 id, Vec3f* scl) {
    g_ecMgr->setScl(id, scl);
}
