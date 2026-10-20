#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} Fn72Bits;

extern "C" void fn_72_5228(Fn72Bits *p, unsigned int v)
{
    p->b = v;
}
