#pragma force_active on
typedef unsigned int u32;

struct Top4 {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1D0BA4(void* p, u32 v)
{
    Top4* t = (Top4*)((char*)p + 8);
    t->hi = v;
}
