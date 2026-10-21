#pragma force_active on
typedef unsigned long u32;

extern void fn_803C8150(void);
extern void fn_803C82C0(void);
extern void fn_803C84E0(void);
extern void fn_803C8720(void);
extern u32 lbl_80563798[];

void fn_803C8AFC(u32 arg0) {
    if (arg0 < 0x1A) {
        lbl_80563798[arg0 * 4] = (u32)fn_803C8150;
        lbl_80563798[arg0 * 4 + 1] = (u32)fn_803C84E0;
        lbl_80563798[arg0 * 4 + 2] = (u32)fn_803C8720;
        lbl_80563798[arg0 * 4 + 3] = (u32)fn_803C82C0;
    }
}
