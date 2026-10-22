#pragma force_active on
typedef unsigned int u32;

int fn_8035ECE0(u32* a, u32 an, u32* b, u32 bn)
{
    u32* p = a + an;
    u32* q;
    while (p[-1] == 0 && an != 0) {
        p--;
        an--;
    }
    q = b + bn;
    while (q[-1] == 0 && bn != 0) {
        q--;
        bn--;
    }
    if (an < bn) return -1;
    if (an > bn) return 1;
    q = b + an;
    p = a + an;
    for (; an != 0; an--) {
        u32 y = q[-1];
        u32 x = p[-1];
        if (x < y) return -1;
        if (x > y) return 1;
        q--;
        p--;
    }
    return 0;
}
