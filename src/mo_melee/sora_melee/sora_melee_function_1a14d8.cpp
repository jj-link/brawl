#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_1A14D8(u32 *self, u32 val)
{
    ((Bits *)&self[2])->b = val;
}
}
