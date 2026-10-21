typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

#pragma force_active on
s32 fn_803A98E0(u8 *s1, u8 *s2, u32 n) {
    u32 i;
    u8 c1;

    for (i = n; i != 0; i--) {
        c1 = *s1;
        if (c1 == 0 || *s2 == 0 || c1 != *s2) {
            return c1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
