#pragma force_active on
extern "C" void fn_48_BF14(unsigned char *p, unsigned int v)
{
    struct Bits {
        unsigned int a : 12;
        unsigned int b : 6;
        unsigned int c : 14;
    };
    struct Bits *w = (struct Bits *)(p + 8);
    w->b = v;
}
