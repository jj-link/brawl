#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 12;
    u32 f : 6;
    u32 lo : 14;
};

extern "C" {
void fn_48_BA94(Bits *obj, u32 val)
{
    obj->f = val;
}
}
