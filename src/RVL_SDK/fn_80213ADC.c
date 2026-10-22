#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern u32 lbl_804F66E0[];
extern s32 lbl_804F6660[];
extern s32 lbl_805A0C00;

void fn_80213ADC(u32 arg0, s32 arg1) {
    s32 i;

    lbl_805A0C00 -= 1;
    for (i = 0; i < 0x20; i++) {
        if (arg0 == lbl_804F66E0[i] && arg1 == lbl_804F6660[i]) {
            lbl_804F66E0[i] = 0;
            lbl_804F6660[i] = -1;
            return;
        }
    }
}
