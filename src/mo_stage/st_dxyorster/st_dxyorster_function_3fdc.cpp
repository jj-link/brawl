#pragma force_active on
extern "C" void fn_76_3FDC(unsigned int *obj, unsigned int val)
{
    struct Bits {
        unsigned int hi : 4;
        unsigned int rest : 28;
    };
    ((struct Bits *)(obj + 2))->hi = val;
}
