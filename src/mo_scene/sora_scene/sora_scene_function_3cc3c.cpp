#include <types.h>
#pragma force_active on

struct SceneState {
    s32 unk0;
    u16 unk4[50];
    s32 unk68;
    u16 unk6C;
    u32 unk70;
};

extern "C" {
extern void* g_GameGlobal;
extern SceneState lbl_1_bss_1B94;

void fn_8004FB48(u32 value);
s32 fn_8004F8B0(u32 value);
u32* fn_8004E588(void* ptr);
void fn_80052704(u16 idx, u32 arg);
void fn_80052AC0(u16 idx, u32 arg);

void fn_1_3CC3C(void) {
    s32 i;
    u32* bits;
    s32 idx;
    s32 n;

    switch (lbl_1_bss_1B94.unk0) {
    case 1:
        fn_80052704(lbl_1_bss_1B94.unk6C, 1);
        break;
    case 2:
    case 3:
    case 4:
        for (i = 0; i < lbl_1_bss_1B94.unk68; i++) {
            fn_80052AC0(lbl_1_bss_1B94.unk4[i], 1);
        }
        break;
    case 7:
        fn_8004FB48(lbl_1_bss_1B94.unk70);
        idx = fn_8004F8B0(lbl_1_bss_1B94.unk70);
        bits = fn_8004E588(g_GameGlobal);
        n = idx * 2 + 1;
        bits[n / 32] |= 1 << (n % 32);
        break;
    }
    lbl_1_bss_1B94.unk0 = 0;
}
}
