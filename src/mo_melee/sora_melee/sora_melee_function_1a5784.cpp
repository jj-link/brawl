#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
};

extern "C" void fn_27_1A5784(S *p, unsigned int v)
{
    p->b = v;
}
