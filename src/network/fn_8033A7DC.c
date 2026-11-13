#pragma force_active on
#include <types.h>

extern u8 *lbl_805A0F88;

s32 fn_80342244(u8 **);
s32 fn_80342270(u8 **);

static inline s32 getList(u8 *p, u8 **out)
{
    const u8 *q;
    s32 n;

    if (p == 0) {
        return 0;
    }
    *out = p + 0x648;
    q = lbl_805A0F88;
    if (p[0x375] == 2 || q[0x375] == 3) {
        n = fn_80342270(out);
    } else {
        n = fn_80342244(out);
    }
    return n;
}

static inline s32 getMask(u8 *p, s32 n)
{
    s32 mask = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        mask |= 1 << p[i];
    }
    return mask;
}

s32 fn_8033A7DC(void)
{
    u8 *buf;
    s32 n;

    if (lbl_805A0F88 == 0) {
        return 0;
    }
    n = getList(lbl_805A0F88, &buf);
    return getMask(buf, n);
}
