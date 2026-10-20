#pragma force_active on
extern "C" void fn_62_A518(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int hi : 2;
        unsigned int rest : 30;
    };
    ((Bits *)(p + 2))->hi = v;
}
