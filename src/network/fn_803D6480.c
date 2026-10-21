#pragma force_active on
typedef unsigned char u8;

int fn_803D6480(const u8 *arg0, const u8 *arg1) {
    const u8 *s1 = arg0;
    const u8 *s2 = arg1;
    for (; *s1 != 0 && *s2 != 0 && *s1 == *s2; s1++, s2++) {
    }
    return *s1 - *s2;
}
