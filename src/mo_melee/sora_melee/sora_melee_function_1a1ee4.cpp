#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 w0;
    u32 w1;
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1A1EE4(FnBits *p, u32 v)
{
    p->hi = v;
}
