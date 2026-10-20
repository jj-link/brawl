#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 pad[2];
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" void fn_27_1D07F0(Fld* p, u32 v)
{
    p->b = v;
}
