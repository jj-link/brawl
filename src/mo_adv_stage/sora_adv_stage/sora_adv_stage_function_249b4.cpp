#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int f : 2;
    unsigned int b : 26;
};

extern "C" void fn_40_249B4(S *p, unsigned int v)
{
    p->f = v;
}
