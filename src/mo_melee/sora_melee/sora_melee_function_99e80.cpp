#include <ec/ec_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_99E80(u32 p1, u32 handleId) {
    g_ecMgr->endEffect(handleId);
}
}
