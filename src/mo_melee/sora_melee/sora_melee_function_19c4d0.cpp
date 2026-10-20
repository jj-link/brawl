#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_19C4D0(void* self, u32 val)
{
    Bits* p = (Bits*)((char*)self + 8);
    p->hi = val;
}
