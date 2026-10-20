#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int :2;
    unsigned int f:2;
    unsigned int :28;
};

extern "C" void fn_52_7590(S *p, unsigned int v)
{
    p->f = v;
}
