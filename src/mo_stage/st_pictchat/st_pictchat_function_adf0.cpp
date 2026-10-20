#pragma force_active on
struct S {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 8;
    unsigned int f : 4;
    unsigned int b : 20;
};

extern "C" void fn_73_ADF0(struct S *p, unsigned int v)
{
    p->f = v;
}
