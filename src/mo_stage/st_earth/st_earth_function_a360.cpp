#pragma force_active on
struct Bits {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
};

extern "C" void fn_66_A360(struct Bits *p, unsigned int v)
{
    ((struct Bits *)((char *)p + 8))->b = v;
}
