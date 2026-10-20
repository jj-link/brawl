#pragma force_active on
struct S {
    int w0;
    int w1;
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" void fn_52_7608(struct S *p, unsigned int v)
{
    p->b = v;
}
