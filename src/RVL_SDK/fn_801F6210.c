#pragma force_active on
typedef unsigned int u32;
typedef int s32;
extern u32 lbl_805A08E0;
extern char *lbl_805A08E8;
extern u32 lbl_805A093C;
s32 fn_801F6210(s32 arg0, u32 *arg1) {
    if (arg0 < 0 || (u32)arg0 >= lbl_805A08E0 ||
        (*(u32 *)(lbl_805A08E8 + (arg0 *= 12)) & 0xFF000000) != 0) {
        return 0;
    }
    arg1[12] = *(u32 *)(lbl_805A08E8 + arg0 + 4) >> lbl_805A093C;
    arg1[13] = *(u32 *)(lbl_805A08E8 + arg0 + 8);
    arg1[14] = 0;
    arg1[3] = 0;
    return 1;
}