#pragma force_active on
struct S {
    unsigned int pad0[2];
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
};

extern "C" void fn_73_AAB8(struct S *p, unsigned int v)
{
    p->f = v;
}
