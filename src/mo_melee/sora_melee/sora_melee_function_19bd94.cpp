#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
} Bits;

extern "C" {
void fn_27_19BD94(void *p, u32 v)
{
    Bits *w = (Bits *)((char *)p + 8);
    w->b = v;
}
}
