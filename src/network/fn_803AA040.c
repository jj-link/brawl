#pragma force_active on
typedef unsigned short u16;
typedef int s32;

s32 fn_803AA040(u16 *arg0, u16 *arg1, s32 arg2) {
    u16 *s1 = arg0;
    u16 *s2 = arg1;
    s32 n = arg2;

    while (n != 0) {
        u16 c1 = *s1;
        if (c1 == 0 || *s2 == 0 || c1 != *s2) {
            return c1 - *s2;
        }
        s1++;
        s2++;
        n--;
    }
    return 0;
}
