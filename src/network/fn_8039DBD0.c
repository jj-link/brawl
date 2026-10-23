#pragma force_active on
typedef int s32;

extern s32 lbl_80492038[4];
extern s32 lbl_80492028[4];

s32 fn_8039DBD0(s32 arg0) {
    s32 *p = lbl_80492038;
    s32 idx;
    s32 i;
    for (i = 0, idx = 0; i < 4; i++) {
        if (arg0 == *p) {
            return lbl_80492028[idx];
        }
        p++;
        idx++;
    }
    return 0;
}
