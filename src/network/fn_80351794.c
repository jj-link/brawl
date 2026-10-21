#pragma force_active on
typedef unsigned int u32;
typedef long long s64;

s64 fn_80351794(u32 *p) {
    if (((p[0] >> 11) & 3) == 2) {
        return ((s64)p[2] << 32) | p[1];
    }
    return 0;
}
