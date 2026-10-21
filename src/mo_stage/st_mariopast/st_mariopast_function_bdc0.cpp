#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 6;
    u32 b : 6;
    u32 lo : 20;
};

extern "C" {
void fn_48_BDC0(Bits *obj, u32 val)
{
    obj->b = val;
}
}
