#include <types.h>
#pragma force_active on

struct Pair { u32 x, y; };
struct Vec {
    Pair xy;
    u32 z;
};
struct Object {
    u32 a, b, c, d, e, f, g, h;
    Vec v;
    f32 value;
    u32 i, j, k, l, m, n, o;
    u8 bit0 : 1;
    u8 bit1 : 1;
    u8 bit2 : 1;
    u8 bit3 : 1;
    u8 bit4 : 1;
    u8 bit5 : 1;
    u8 bit6 : 1;
    u8 bit7 : 1;
    u8 flags : 2;
    u8 remaining : 6;
};

extern "C" void fn_119_12DE4(Object* self, u32 a, u32 b, u32 c, Vec* v, u32 d, u32 e, u32 f, f32 g, u32 h, u32 i, u32 j, u32 k, u32 l, u32 m, u8 n, u32 o)
{
    self->a = a;
    self->b = b;
    if (l == 0xffff) l = b;
    self->c = l;
    if (k == 0xffff) k = b;
    self->d = k;
    self->e = j;
    self->f = j;
    self->g = f;
    self->h = h;
    self->v = *v;
    self->value = g;
    self->i = d;
    self->j = e;
    self->k = i;
    self->l = o;
    self->m = 0;
    self->n = 0x35f;
    self->o = m;
    self->bit0 = 1;
    self->bit1 = c;
    self->bit2 = 0;
    self->bit3 = 0;
    self->bit4 = n;
    self->bit5 = 0;
    self->bit6 = 0;
    self->bit7 = 0;
    self->flags = 0;
}
