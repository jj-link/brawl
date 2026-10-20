#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 6;
    u32 f : 3;
    u32 b : 23;
};

extern "C" void fn_27_CB8F8(Flags* p, u32 v)
{
    Flags* x = (Flags*)((char*)p + 8);
    x->f = v;
}
