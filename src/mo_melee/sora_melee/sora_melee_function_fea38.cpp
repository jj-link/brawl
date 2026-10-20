#pragma force_active on
struct Bits {
    unsigned int a : 3;
    unsigned int b : 3;
    unsigned int c : 26;
};

extern "C" void fn_27_FEA38(void *p, unsigned int v)
{
    struct Bits *s = (struct Bits *)((char *)p + 8);
    s->b = v;
}
