#include <ec/ec_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_98110(void* a, u32 p1) {
    g_ecMgr->pushsetCurrentGroup(p1);
}
