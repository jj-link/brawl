#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad0;
    u32 pad1;
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1D00DC(Flags* p, u32 v)
{
    p->hi = v;
}
