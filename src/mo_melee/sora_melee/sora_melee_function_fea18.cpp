#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 3;
    u32 rest : 29;
};

extern "C" {
void fn_27_FEA18(u32* self, u32 v)
{
    ((Bits*)&self[2])->hi = v;
}
}
