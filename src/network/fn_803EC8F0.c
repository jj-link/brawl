#include <types.h>
#pragma force_active on

int fn_803EC8F0(u8 *p, u32 *out, u8 b)
{
    u32 a;
    u16 n;
    u32 x, v, w, result;
    int z;

    a = 0;
    x = 0x200;
    while ((x = (x >> 1) & 0x7fff) != 0)
        a++;

    b = 0;
    x = 1;
    while ((x = (x >> 1) & 0x7fff) != 0)
        b++;

    if ((u32)(p + 0x11) & 1) {
        z = p[0x11] | (p[0x12] << 8);
    } else {
        u16 t = *(u16 *)(p + 0x12);
        z = (((u32)t >> 8) | ((t << 8) & 0xff00)) << 5;
    }

    n = (u16)((z + 0x1ff) >> (u8)a);

    if ((u32)(p + 0x16) & 1) {
        v = p[0x16] | (p[0x17] << 8);
    } else {
        u16 t = *(u16 *)(p + 0x16);
        v = ((u32)t >> 8) | ((t << 8) & 0xff00);
    }

    if ((v = (u16)v) == 0) {
        a = *(u32 *)(p + 0x24);
        v = ((a << 24) | ((a << 8) & 0xff0000)) |
            ((a >> 24) | ((a >> 8) & 0xff00));
    }

    w = n + v * 2 + 1;

    if ((u32)(p + 0x13) & 1) {
        z = p[0x13] | (p[0x14] << 8);
    } else {
        u16 t = *(u16 *)(p + 0x14);
        z = ((u32)t >> 8) | ((t << 8) & 0xff00);
    }

    if (z == 0) {
        u32 t = *(u32 *)(p + 0x20);
        z = ((t << 24) | ((t << 8) & 0xff0000)) |
            ((t >> 24) | ((t >> 8) & 0xff00));
    }

    result = z - w;
    x = result >> b;
    *out = result;

    if (x < 0xff5)
        return 0;
    z = 2;
    if (x < 0xfff5)
        z = 1;
    return z;
}
