#pragma force_active on
typedef signed int s32;

extern void *lbl_80533730[32];

s32 fn_8033ACA8(void) {
    s32 r3 = 0;
    void **p = lbl_80533730;
    while (r3 < 32) {
        if (*p == 0)
            return r3;
        p++;
        r3++;
    }
    return -1;
}