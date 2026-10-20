#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
} Bits;

extern "C" {
void fn_79_5ADC(void *p, u32 v)
{
    Bits *w = (Bits *)((u32 *)p + 2);
    w->f = v;
}
}
