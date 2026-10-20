#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} Bits;

extern "C" void fn_66_A40C(Bits *p, unsigned int v)
{
    p->f = v;
}
