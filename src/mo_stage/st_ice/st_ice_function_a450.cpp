#pragma force_active on
typedef struct BitS {
    int a;
    int b;
    unsigned int f : 2;
    unsigned int rest : 30;
} BitS;

extern "C" {
void fn_62_A450(BitS *p, unsigned int v)
{
    p->f = v;
}
}
