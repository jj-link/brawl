#pragma force_active on
struct S {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 10;
    unsigned int f : 5;
    unsigned int lo : 17;
};

extern "C" void fn_40_30DA0(S *p, unsigned int v)
{
    p->f = v;
}
