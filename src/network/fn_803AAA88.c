#include <types.h>
#pragma force_active on
typedef struct {
    u8 pad0[8];
    u16 a;
    u8 b, c;
    u16 d, e;
    u8 pad10[0x40];
    u32 type;
    u8 shift1, shift2;
    u16 result;
    u8 pad58[8];
    u32 start, count, total, factor;
} Obj;
void fn_803AAA88(Obj *p) {
    u16 x = p->a;
    u16 y;
    s32 z;
    u32 start, count;
    p->shift1 = 0;
    while ((x = x >> 1) != 0) {
        p->shift1++;
    }
    y = p->b;
    p->shift2 = 0;
    while ((y = y >> 1) != 0) {
        p->shift2++;
    }
    z = (p->a + (p->e << 5) - 1) >> p->shift1;
    p->result = z;
    start = p->c * p->factor + ((u16)z + p->d);
    p->start = start;
    count = (p->total - start) >> p->shift2;
    p->count = count;
    if (count < 0xff5) {
        p->type = 0;
    } else if (count < 0xfff5) {
        p->type = 1;
    } else {
        p->type = 2;
    }
}