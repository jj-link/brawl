typedef unsigned int u32;
typedef int s32;

#pragma force_active on

s32 fn_803D78CC(u32 z, u32 a, u32 b, u32 c, u32 *p, u32 *q)
{
    u32 t;
    s32 r = 0;

    *p = a;
    *q = b;

    if (c > 0x200) {
        t = (c >> 9) & 0x7F;

        if (t == 2) *p >>= 1;
        else if (t == 4) *p >>= 2;
        else if (t == 8) *p >>= 3;

        if (t == 2) *q >>= 1;
        else if (t == 4) *q >>= 2;
        else if (t == 8) *q >>= 3;
    } else if (c < 0x200) {
        r = 4;
    }

    return r;
}
