#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 12;
    unsigned int b : 6;
    unsigned int c : 14;
};

extern "C" void fn_79_5A14(struct S *p, unsigned int v)
{
    p->b = v;
}
