#include <types.h>
#pragma force_active on

extern "C" {
u32* fn_8004E588(void*);
u32* fn_8004E594(void*);
extern void* g_GameGlobal;
extern s32 lbl_8042BF58[];
extern s32 lbl_8042C0A0[];
}

static inline u32 isEnabled(s32 value) {
    u32 enabled = 1;
    for (s32 j = 0; j < 12; j++) {
        if (value == lbl_8042C0A0[j]) {
            u32* words = fn_8004E594(g_GameGlobal);
            enabled = (words[j / 32] & (1 << (j % 32))) != 0;
            break;
        }
    }
    return enabled;
}

extern "C" s32 fn_80051A6C(void) {
    s32 bit;
    s32 i;

    for (i = 0, bit = 0; i <= 47; i++, bit += 2) {
        u32* words = fn_8004E588(g_GameGlobal);
        if (!(words[bit / 32] & (1 << (bit % 32)))) {
            return 0;
        }
    }

    for (i = 48; i <= 63; i++) {
        u32 enabled = isEnabled(lbl_8042BF58[i - 48]);
        if (enabled == 1) {
            s32 bit = i * 2;
            u32* words = fn_8004E588(g_GameGlobal);
            if (!(words[bit / 32] & (1 << (bit % 32)))) {
                return 0;
            }
        }
    }

    return 1;
}
