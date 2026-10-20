#pragma force_active on
extern "C" void fn_50_64A0(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int hi : 8;
        unsigned int f : 4;
        unsigned int lo : 20;
    };
    ((struct Bits *)(p + 2))->f = v;
}
