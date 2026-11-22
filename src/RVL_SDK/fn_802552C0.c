#include <types.h>
#pragma force_active on
extern void *fn_8022EFF8(u32);
extern void fn_80254D68(void *, int, void *);
void fn_802552C0(void *a, u8 b, int c, u8 *d, u32 e)
{
    u8 *p;
    u8 *q;
    p = fn_8022EFF8(2);
    if (p != 0) {
        *(u16 *)(p + 4) = 12;
        q = p + 0x14;
        *q++ = ((-c | c) >> 31 & 2) | 0x91;
        if (d == 0) {
            *q++ = 3;
            *q++ = (b << 2) | 3;
            *(u16 *)(p + 2) = 3;
        } else {
            *q++ = 0x11;
            *q++ = (b << 2) | 3;
            *q++ = d[0];
            *q++ = d[1] | (d[2] << 2) | (d[3] << 3) | (d[4] << 4);
            *q++ = d[5];
            *q++ = d[7];
            *q++ = d[8];
            *q++ = e;
            *q++ = e >> 8;
            *(u16 *)(p + 2) = 10;
        }
        fn_80254D68(a, 0, p);
    }
}