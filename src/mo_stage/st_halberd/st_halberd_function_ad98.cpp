#pragma force_active on
struct S {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 3;
    unsigned int b : 3;
    unsigned int c : 26;
};

extern "C" void fn_57_AD98(struct S *s, unsigned int v)
{
    s->b = v;
}
