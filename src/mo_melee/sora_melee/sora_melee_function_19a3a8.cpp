#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad[2];
    u32 a : 2;
    u32 b : 2;
    u32 rest : 28;
};

extern "C" void fn_27_19A3A8(Flags *f, u32 v)
{
    f->b = v;
}
