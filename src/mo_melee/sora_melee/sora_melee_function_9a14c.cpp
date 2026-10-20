#include <ec/ec_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_9A14C(u32 a, u32 b, bool c)
{
    g_ecMgr->setVisible(b, c);
}
