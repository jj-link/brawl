#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int f : 7;
    unsigned int g : 25;
};

extern "C" {
void fn_48_B7C0(struct S *p, unsigned int v)
{
    p->f = v;
}
}
