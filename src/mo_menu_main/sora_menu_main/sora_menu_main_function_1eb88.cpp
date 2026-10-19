#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_8004E6AC(void* arg);
void fn_8004F258(void* buf, u32 val, int unk);

void* fn_2_1EB88() {
    void* buf = *(void**)fn_8004E6AC(g_GameGlobal);
    u32 rec = *(u32*)((char*)g_GameGlobal->m_record + 0x7F8);
    fn_8004F258(&buf, rec / 60, -1);
    return buf;
}
}
