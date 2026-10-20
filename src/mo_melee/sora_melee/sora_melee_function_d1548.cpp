#pragma force_active on
extern "C" void fn_27_D1548(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int hi : 10;
        unsigned int f : 5;
        unsigned int lo : 17;
    };
    Bits *b = (Bits *)&p[2];
    b->f = v;
}
