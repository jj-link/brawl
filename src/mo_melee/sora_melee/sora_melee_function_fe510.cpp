#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 hi : 3;
    u32 rest : 29;
};

extern "C" void fn_27_FE510(Flags* p, u32 v)
{
    Flags* f = (Flags*)((char*)p + 8);
    f->hi = v;
}
