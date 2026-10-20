#pragma force_active on
typedef unsigned int u32;

struct Fn27Bits {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" void fn_27_1A37A4(void* p, u32 v)
{
    Fn27Bits* w = (Fn27Bits*)((char*)p + 8);
    w->b = v;
}
