#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 3;
    u32 b : 29;
} Bits;

extern "C" {
void fn_27_295F10(u32 *p, u32 v)
{
    Bits *s = (Bits *)&p[2];
    s->a = v;
}
}
