#pragma force_active on
extern "C" void fn_79_5D04(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 8;
        unsigned int b : 4;
        unsigned int c : 20;
    };
    Bits *bits = (Bits *)&p[2];
    bits->b = v;
}
