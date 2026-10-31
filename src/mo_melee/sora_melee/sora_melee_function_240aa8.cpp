#include <gf/gf_memory_pool.h>
#include <if/if_mngr.h>
#pragma force_active on

extern "C" void fn_800DC2E0(IfMngr* manager);

extern "C" void fn_27_240AA8(void)
{
    if (g_HeapInfos[40].m_name == 0)
        return;
    fn_800DC2E0(g_IfMngr);
}
