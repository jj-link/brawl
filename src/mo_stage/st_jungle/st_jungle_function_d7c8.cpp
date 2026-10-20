#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int f : 3;
    unsigned int r : 29;
};

extern "C" void fn_51_D7C8(struct S *s, unsigned int v)
{
    s->f = v;
}
