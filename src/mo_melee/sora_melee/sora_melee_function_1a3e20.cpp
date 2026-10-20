#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 hi : 20;
    u32 f : 10;
    u32 lo : 2;
} Bits;

extern "C" {
void fn_27_1A3E20(void *p, u32 v)
{
    Bits *b = (Bits *)((char *)p + 8);
    b->f = v;
}
}
