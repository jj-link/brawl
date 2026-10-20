#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" {
void fn_27_1CF85C(void* p, u32 v)
{
    Bits* s = (Bits*)((char*)p + 8);
    s->b = v;
}
}
