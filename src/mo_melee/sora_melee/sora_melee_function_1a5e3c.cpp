#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 10;
    u32 f : 10;
    u32 b : 12;
};

extern "C" void fn_27_1A5E3C(void* p, u32 v)
{
    ((Flags*)((char*)p + 8))->f = v;
}
