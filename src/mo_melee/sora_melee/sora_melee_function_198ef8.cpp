#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
};

extern "C" void fn_27_198EF8(char *obj, u32 val)
{
    Bits *p = (Bits *)(obj + 8);
    p->f = val;
}
