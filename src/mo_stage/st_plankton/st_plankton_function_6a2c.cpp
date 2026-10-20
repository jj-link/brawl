#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 hi : 2;
    u32 f : 2;
    u32 lo : 28;
} Bits;

extern "C" {
void fn_74_6A2C(Bits *p, u32 v)
{
    p[2].f = v;
}
}
