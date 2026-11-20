#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" void fn_8010FE58(s32* arg0, u32* arg1) {
    u8* a = (u8*)g_GameGlobal->m_modeMelee;
    u8* b = a + 0xD6;
    s32 i;
    *arg0 = -1;
    *arg1 = 0;
    for (i = 0; i < 4; i++) {
        if (a[0x99] == 0 && ((b[0] >> 7) & 1)) {
            s32 t = a[0xD5] - 1;
            if (t >= 0) {
                if (*arg0 < 0) {
                    *arg0 = t;
                }
                *arg1 |= 1 << t;
            }
        }
        a += 0x5C;
        b += 0x5C;
    }
}