#include <types.h>
#include <gm/gm_global.h>

#pragma force_active on

extern "C" u32* fn_8004E580(void* self);
extern "C" u8* fn_8004E5D8(void* self, int index);

extern "C" int fn_80056FDC() {
    int i;
    int off;
    u32 count;
    int j;
    u32 found;
    int n;
    int off8;
    int off4;
    int k;

    if (!(fn_8004E580(g_GameGlobal)[0] & 0x10000000)) {
        i = 0;
        off = 0;
        for (; i < 5; i++) {
            count = 0;
            for (j = 0; j < 0x23; j++) {
                if (((*(u32*)(fn_8004E5D8(g_GameGlobal, j) + off + 0xCC) >> 30) & 1) == 1) {
                    count++;
                    if (count >= 0x1E) {
                        break;
                    }
                }
            }
            if (count >= 0x1E) {
                fn_8004E580(g_GameGlobal)[0] |= 0x08000000;
                return 1;
            }
            off += 4;
        }
    }

    if (!(fn_8004E580(g_GameGlobal)[0] & 0x10000)) {
        n = 0;
        off4 = 0;
        off8 = 0;
        found = 0;
        while (n < 5) {
            found = 0;
            for (k = 0; k < 0x23; k++) {
                if (((*(u32*)(fn_8004E5D8(g_GameGlobal, k) + off4 + 0xCC) >> 30) & 1) == 1) {
                    found = 1;
                    break;
                }
            }
            if (((*(u32*)((u8*)g_GameGlobal->m_record + off8 + 0x34FC) >> 30) & 1) == 1) {
                found = 1;
            }
            if (found == 0) {
                break;
            }
            off4 += 4;
            n++;
            off8 += 8;
        }
        if (found == 1) {
            fn_8004E580(g_GameGlobal)[0] |= 0x8000;
            return 1;
        }
    }
    return 0;
}
