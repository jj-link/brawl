#pragma force_active on
typedef unsigned int u32;

typedef struct Bits {
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
} Bits;

extern "C" {
void fn_50_63D8(u32 *obj, u32 v)
{
    Bits *p = (Bits *)(obj + 2);
    p->b = v;
}
}
