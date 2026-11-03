#pragma force_active on
typedef int s32;

s32 fn_802123A8(void *p, s32 flag);

s32 fn_803A279C(s32 unused, void *p, s32 *out, s32 flag) {
    s32 r;

    if (out == 0) {
        return -3;
    }
    r = fn_802123A8(p, flag);
    *out = r;
    if (r < 0) {
        if (r == -6) {
            return -0x1D;
        }
        if (r == -8) {
            return -0x1A;
        }
        return -0x2A;
    }
    return 0;
}
