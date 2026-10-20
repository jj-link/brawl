#pragma force_active on
struct BitS {
    unsigned int pad[2];
    unsigned int a : 3;
    unsigned int rest : 29;
};

extern "C" {
void fn_27_19A9C8(BitS *p, unsigned int v)
{
    p->a = v;
}
}
