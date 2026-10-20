#pragma force_active on
extern "C" {
struct Bits {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 4;
    unsigned int f : 2;
    unsigned int rest : 26;
};

void fn_66_A484(struct Bits *p, unsigned int v)
{
    p->f = v;
}
}
