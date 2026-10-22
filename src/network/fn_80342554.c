#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

extern u64 fn_803F1470(u64 a, u64 b);
extern s32 lbl_8059F0B0;
extern int lbl_805A0FA8;

s32 fn_80342554(void) {
    u32 ticks = *(u32 *)0x800000F8;
    u64 r = fn_803F1470(*(u64 *)(lbl_805A0FA8 + 0x4c0), (u64)((ticks >> 2) / 1000));
    s32 t = (s32)(u32)r;
    s32 v;

    if (lbl_8059F0B0 != -1) {
        return lbl_8059F0B0;
    }
    t = t + 0x1387;
    v = t / 5000;
    if (v > 10) {
        v = 10;
    }
    return v;
}
