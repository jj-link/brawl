#include <types.h>
#pragma force_active on

typedef struct {
    u16 a, b, c;
    u8 d, e;
    u32 total, factor;
    u8 pad[12];
    u32 type;
    u8 shift1, shift2;
    u8 pad2[2];
    u16 result;
    u8 pad3[6];
    u32 base, start, count;
} Obj;

void fn_803D7330(Obj *p)
{
    u16 x = p->a;
    u16 y;
    s32 z;
    u32 start, count;

    p->shift1 = 0;
    while ((x = x >> 1) != 0) {
        p->shift1++;
    }

    y = p->d;
    p->shift2 = 0;
    while ((y = y >> 1) != 0) {
        p->shift2++;
    }

    z = (p->a + (p->c << 5) - 1) >> p->shift1;
    p->result = z;
    start = p->e * p->factor + ((u16)z + p->b);
    p->start = start;
    count = (p->total - start) >> p->shift2;
    p->count = count;

    if (count < 0xff5) {
        p->type = 0;
        p->base = p->b + p->e * p->factor;
    } else if (count < 0xfff5) {
        p->type = 1;
        p->base = p->b + p->e * p->factor;
    } else {
        p->type = 2;
        p->base = 0;
    }
}
