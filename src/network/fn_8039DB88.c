#pragma force_active on
typedef int s32;
extern s32 lbl_80491F90[16];
extern s32 lbl_80491FD0[16];

s32 fn_8039DB88(s32 arg0) {
    s32 *p = lbl_80491FD0;
    s32 idx;
    s32 i;
    for (i = 0, idx = 0; i < 16; i++) {
        if (arg0 == *p) {
            return lbl_80491F90[idx];
        }
        p++;
        idx++;
    }
    return 0;
}
