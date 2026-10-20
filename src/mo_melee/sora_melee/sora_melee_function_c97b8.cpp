#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 f : 2;
    u32 b : 26;
};

extern "C" {
void fn_27_C97B8(void* p, u32 v)
{
    Bits* w = (Bits*)((char*)p + 8);
    w->f = v;
}
}
