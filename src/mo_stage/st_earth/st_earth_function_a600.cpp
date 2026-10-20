#pragma force_active on
struct S {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 4;
    unsigned int rest : 28;
};

extern "C" void fn_66_A600(S *p, unsigned int v)
{
    p->hi = v;
}
