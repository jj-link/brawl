#pragma force_active on
extern "C" void fn_66_A3EC(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 4;
        unsigned int b : 2;
        unsigned int c : 26;
    };
    Bits *s = (Bits *)&p[2];
    s->b = v;
}
