#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" void fn_27_19DB70(void *obj, u32 val)
{
    Bits *p = (Bits *)((char *)obj + 8);
    p->b = val;
}
