#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 2;
    u32 rest : 30;
};

extern "C" void fn_27_FE2E8(void* p, u32 v)
{
    Bits* b = (Bits*)((char*)p + 8);
    b->a = v;
}
