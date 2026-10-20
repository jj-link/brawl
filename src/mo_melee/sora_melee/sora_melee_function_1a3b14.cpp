#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 20;
    u32 f : 10;
    u32 b : 2;
};

extern "C" void fn_27_1A3B14(void* self, u32 val)
{
    Bits* p = (Bits*)((char*)self + 8);
    p->f = val;
}
