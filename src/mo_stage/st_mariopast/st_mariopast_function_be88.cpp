#pragma force_active on
extern "C" void fn_48_BE88(unsigned char *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 6;
        unsigned int b : 6;
        unsigned int c : 20;
    };
    Bits *w = (Bits *)(p + 8);
    w->b = v;
}
