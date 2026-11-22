#include <types.h>

#pragma force_active on

extern "C" {
extern u32 lbl_8042B858[];
extern void* g_GameGlobal;
u32* fn_8004E588(void*);
u32* fn_8004E594(void*);
}

static inline s32 findIndex(u32 value, u32* list) {
    for (s32 i = 0; i < 102; i++) {
        if (value == list[i]) {
            return i;
        }
    }
    return 102;
}

extern "C" s32 fn_8004F978(u32 value) {
    u8* base = (u8*)lbl_8042B858;
    s32 i = findIndex(value, (u32*)(base + 0x568));

    if (i != 102) {
        u32* bits = fn_8004E588(g_GameGlobal);
        return (bits[(i * 2) / 32] & (1 << ((i * 2) % 32))) != 0;
    }

    u32* pairs = (u32*)(base + 0x740);
    for (s32 k = 0; k < 31; k++, pairs += 2) {
        if (value == pairs[0]) {
            u32 result = 1;
            s32* entries = (s32*)(base + 0x848);
            s32 key = pairs[1];

            for (s32 j = 0; j < 12; entries++, j++) {
                if (key == *entries) {
                    u32* bits = fn_8004E594(g_GameGlobal);
                    result = (bits[j / 32] & (1 << (j % 32))) != 0;
                    break;
                }
            }

            if (!result) {
                return 0;
            }
        }
    }

    return 1;
}
