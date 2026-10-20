#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 7;
    u32 f : 7;
    u32 b : 18;
};

extern "C" {
void fn_27_14F330(void* p, u32 v)
{
    Bits* w = (Bits*)((char*)p + 8);
    w->f = v;
}
}
