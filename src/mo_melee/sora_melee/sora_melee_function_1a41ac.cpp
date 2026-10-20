#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct FnObj27 {
    u8 pad_0[8];
    u32 hi : 10;
    u32 rest : 22;
};

extern "C" void fn_27_1A41AC(FnObj27 *p, u32 v)
{
    p->hi = v;
}
