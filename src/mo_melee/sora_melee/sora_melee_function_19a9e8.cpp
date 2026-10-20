#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 3;
    u32 f : 3;
    u32 b : 26;
};

extern "C" {
void fn_27_19A9E8(Bits *obj, u32 val)
{
    obj[2].f = val;
}
}
