#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_27_CF898(void *obj, u32 val)
{
    struct Bits {
        u32 a : 12;
        u32 b : 6;
        u32 c : 14;
    };
    Bits *p = (Bits *)((char *)obj + 8);
    p->b = val;
}
}
