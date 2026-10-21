#include <ec/ec_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_99EA8(void*, u32 p1, u32 p2, u32 p3) {
    g_ecMgr->killEffect(p1, p2, p3);
}
