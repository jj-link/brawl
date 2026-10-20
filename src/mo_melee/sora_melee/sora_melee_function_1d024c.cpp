#pragma force_active on
struct S {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 7;
    unsigned int rest : 25;
};

extern "C" void fn_27_1D024C(S *p, unsigned int v)
{
    p->hi = v;
}
