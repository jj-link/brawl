#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

extern "C" void fn_27_10EC64(void* p, u32 v)
{
    Flags* w = (Flags*)((char*)p + 8);
    w->f = v;
}
