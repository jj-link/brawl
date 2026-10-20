#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
};

extern "C" {
void fn_48_3F48(Bits *obj, u32 val)
{
    obj->f = val;
}
}
