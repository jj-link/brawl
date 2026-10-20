#pragma force_active on
extern "C" void fn_74_6B50(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 4;
        unsigned int b : 2;
        unsigned int c : 26;
    };
    struct Bits *s = (struct Bits *)&p[2];
    s->b = v;
}
