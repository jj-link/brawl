#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" u32* fn_8004E580(void*);
extern "C" u8* fn_8004E5D8(void*, int);
extern "C" u32* fn_8004E5F8(void*);
extern "C" u32 fn_80056FDC();

extern "C" void fn_1_27574(u8 a, u32 b, u32 c, int d) {
    if (!(fn_8004E5F8(g_GameGlobal)[5] & 0x100000) &&
        ((u32)((*((u8*)g_GameGlobal->m_selCharData + 0x2e) >> 2) & 7) == 1) && c >= 4) {
        fn_8004E5F8(g_GameGlobal)[5] |= 0x100000;
    }
    if (fn_80056FDC() != 1) {
        if (!(fn_8004E580(g_GameGlobal)[0] & 0x80000000)) {
            int count = 0;
            for (int i = 0; i < 0x23; i++) {
                if ((*(u16*)(fn_8004E5D8(g_GameGlobal, i) + 0x9c) >> 8) & 7)
                    count++;
            }
            if (count >= 10) {
                fn_8004E580(g_GameGlobal)[0] |= 0x40000000;
                return;
            }
        }
        if (!(fn_8004E580(g_GameGlobal)[0] & 0x02000000) &&
            (a == 2 || (u8)(a + 0xf2) <= 1) && c >= 2) {
            fn_8004E580(g_GameGlobal)[0] |= 0x01000000;
            return;
        }
        if (!(fn_8004E580(g_GameGlobal)[0] & 0x2000) && c >= 1 && b <= 0xa8c0) {
            fn_8004E580(g_GameGlobal)[0] |= 0x1000;
            return;
        }
        if (!(fn_8004E580(g_GameGlobal)[0] & 0x80) && d == 0) {
            fn_8004E580(g_GameGlobal)[0] |= 0x40;
            return;
        }
        if (!(fn_8004E580(g_GameGlobal)[1] & 0x20) &&
            ((fn_8004E5F8(g_GameGlobal)[4] >> 26) & 1) == 1) {
            fn_8004E580(g_GameGlobal)[1] |= 0x10;
            return;
        }
        if (!(fn_8004E580(g_GameGlobal)[0] & 0x10))
            fn_8004E580(g_GameGlobal)[0] |= 8;
    }
}