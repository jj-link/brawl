#pragma force_active on
extern "C" void fn_66_A3FC(unsigned int *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 2;
        unsigned int b : 30;
    };
    Bits *s = (Bits *)&p[2];
    s->a = v;
}
