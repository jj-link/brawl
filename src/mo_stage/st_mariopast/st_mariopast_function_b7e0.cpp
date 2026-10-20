#pragma force_active on
struct S {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int a : 7;
    unsigned int f : 7;
    unsigned int rest : 18;
};

extern "C" void fn_48_B7E0(struct S *p, unsigned int v)
{
    p->f = v;
}
