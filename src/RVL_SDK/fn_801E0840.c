#pragma force_active on
typedef unsigned char u8;
typedef int s32;

s32 fn_801E0840(u8 *self) {
    s32 v;
    s32 min;
    u8 *n;
    u8 *p;

    min = *(s32 *)(self + 0x2D4);
    n = *(u8 **)(self + 0x2F4);
    while (n != 0) {
        p = *(u8 **)n;
        if (p != 0) {
            v = *(s32 *)(p + 0x2D0);
            if (v < min) {
                min = v;
            }
        }
        n = *(u8 **)(n + 0x10);
    }
    return min;
}
