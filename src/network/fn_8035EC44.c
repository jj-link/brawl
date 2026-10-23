#pragma force_active on
typedef unsigned int u32;
typedef int s32;

u32 fn_8035EC44(s32 *arg0, s32 *arg1, u32 *arg2)
{
    s32 *p0;
    s32 *p1;
    s32 n0;
    s32 n1;
    u32 size;

    n0 = *arg0;
    n1 = *arg1;
    p0 = arg0 + n0;
    while (n0 > 0 && *p0 == 0) {
        p0--;
        n0--;
    }

    p1 = arg1 + n1;
    while (n1 > 0 && *p1 == 0) {
        p1--;
        n1--;
    }

    if (n0 > n1) {
        n1 = n0;
    }

    *arg2 = (u32)n1;
    size = 1;
    while (size < (u32)n1) {
        size <<= 1;
    }

    *arg2 = size;
    return size <= 64u;
}
