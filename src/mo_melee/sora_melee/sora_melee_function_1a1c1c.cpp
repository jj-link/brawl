#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" {
void fn_27_1A1C1C(void* p, u32 v)
{
    Bits* bits = (Bits*)((char*)p + 8);
    bits->b = v;
}
}
