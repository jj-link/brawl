#pragma force_active on
extern "C" void fn_48_3E9C(unsigned char *p, unsigned int v)
{
    struct W {
        unsigned int hi : 4;
        unsigned int lo : 28;
    };
    W *w = (W *)(p + 8);
    w->hi = v;
}
