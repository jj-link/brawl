#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 5;
    u32 lo : 27;
};

extern "C" {
void fn_27_19B0A0(void* p, u32 v)
{
    Bits* w = (Bits*)((char*)p + 8);
    w->hi = v;
}
}
