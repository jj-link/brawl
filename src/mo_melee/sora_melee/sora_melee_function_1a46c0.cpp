#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 hi : 10;
    u32 lo : 22;
};

extern "C" void fn_27_1A46C0(void* p, u32 v)
{
    Flags* f = (Flags*)((char*)p + 8);
    f->hi = v;
}
