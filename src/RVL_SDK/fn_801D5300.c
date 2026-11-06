#include <types.h>
#pragma force_active on

typedef struct {
    u8 a, b, c, d, e, f;
    u16 year;
} Date;

void fn_801D5300(Date *out) {
    u32 y = *(u32 *)0xC0003140;
    u32 x = *(u32 *)0xC0003144;
    out->a = y >> 24;
    out->b = y >> 16;
    out->d = y;
    out->c = y >> 8;
    out->e = ((x >> 16) & 15) + ((x >> 20) & 15) * 10;
    out->f = ((x >> 8) & 15) + ((x >> 12) & 15) * 10;
    out->year = (x & 15) + ((x >> 4) & 15) * 10 + 2000;
}