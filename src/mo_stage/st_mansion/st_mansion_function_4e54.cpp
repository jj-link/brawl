#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int p : 4;
    unsigned int f : 2;
    unsigned int q : 26;
};

extern "C" void fn_47_4E54(struct S *s, unsigned int v)
{
    s->f = v;
}
