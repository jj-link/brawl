#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern u32 fn_80211AE0(void);
extern u32 fn_80211AE8(void);
extern void fn_80211AF0(u32);
extern s32 fn_80213468(void *base, u32 size);
extern s32 lbl_8059ECCC;

s32 fn_80211FDC(void) {
    u32 end;
    s32 var_r30 = 0;
    u32 base = fn_80211AE8();
    end = base + 0x800;
    if (end > fn_80211AE0()) {
        var_r30 = -0x16;
    } else {
        lbl_8059ECCC = fn_80213468((void *)base, 0x800);
        fn_80211AF0(end);
    }
    return var_r30;
}
