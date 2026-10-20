#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" void fn_27_1D588(void *obj, u32 val)
{
    Bits *p = (Bits *)((char *)obj + 8);
    p->b = val;
}
