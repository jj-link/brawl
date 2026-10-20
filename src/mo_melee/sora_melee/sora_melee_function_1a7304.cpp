#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int a : 8;
    unsigned int f : 4;
    unsigned int b : 20;
};

extern "C" void fn_27_1A7304(struct S *p, unsigned int v)
{
    p->f = v;
}
