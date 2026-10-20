#pragma force_active on
struct Bits
{
    unsigned int value : 12;
    unsigned int field : 6;
    unsigned int rest : 14;
};

extern "C" void fn_48_BFAC(void* p, unsigned int v)
{
    ((Bits*)((char*)p + 8))->field = v;
}
