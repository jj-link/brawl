#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad0;
    u32 pad1;
    u32 f0 : 2;
    u32 f1 : 2;
    u32 rest : 28;
};

extern "C" void fn_27_1A4F00(Flags *p, u32 v)
{
    p->f1 = v;
}
