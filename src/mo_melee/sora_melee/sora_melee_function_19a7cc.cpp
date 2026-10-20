#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 6;
    u32 f : 3;
    u32 b : 23;
} Bits;

extern "C" {
void fn_27_19A7CC(char *p, u32 v)
{
    Bits *x = (Bits *)(p + 8);
    x->f = v;
}
}
