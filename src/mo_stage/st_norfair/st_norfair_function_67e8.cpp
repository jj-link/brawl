#pragma force_active on
struct S {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

extern "C" void fn_54_67E8(S *s, unsigned int v)
{
    s->b = v;
}
