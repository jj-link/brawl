#pragma force_active on
struct S {
    unsigned int a[2];
    unsigned int pad : 20;
    unsigned int f : 10;
    unsigned int rest : 2;
};

extern "C" void fn_27_1A69CC(S *p, unsigned int v)
{
    p->f = v >> 0;
}
