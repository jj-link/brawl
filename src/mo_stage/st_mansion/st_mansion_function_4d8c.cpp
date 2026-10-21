#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int rest : 26;
} Bits;

extern "C" void fn_47_4D8C(Bits *p, unsigned int v)
{
    p->b = v;
}
