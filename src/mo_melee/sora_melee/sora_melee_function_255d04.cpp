#include <types.h>
#include <if/if_mngr.h>
#include <if/if_player.h>
#pragma force_active on

extern "C" void fn_800E5174(void* a, u32 b);

extern "C" void fn_27_255D04(void* a, u32 index) {
    IfMngr* mngr = g_IfMngr;
    u32 addr = (u32)mngr + index + 0x68;
    u8 pidx = *(u8*)addr;
    IfPlayer* p = mngr->m_ifPlayers[pidx];
    if (((u32*)p)[213] != 0) {
        fn_800E5174(p, 0);
    }
    u8* e = (u8*)a + index;
    e[0x64] = 0;
    e[0x6b] = 0;
}
