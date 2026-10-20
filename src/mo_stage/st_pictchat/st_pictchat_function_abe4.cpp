#pragma force_active on
extern "C" void fn_73_ABE4(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int hi : 2;
        unsigned int rest : 30;
    };
    Bits *b = (Bits *)&p[2];
    b->hi = v;
}
