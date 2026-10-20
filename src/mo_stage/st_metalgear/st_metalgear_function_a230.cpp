#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 8;
    u32 f : 4;
    u32 b : 20;
} Bits;

extern "C" {
void fn_71_A230(void *p, u32 v)
{
    Bits *w = (Bits *)((char *)p + 8);
    w->f = v;
}
}
