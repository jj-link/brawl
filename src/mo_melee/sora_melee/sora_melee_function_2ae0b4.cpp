#pragma force_active on
struct S {
    unsigned int a;
    unsigned int b;
    unsigned int f : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_2AE0B4(S *s, unsigned int v)
{
    s->f = v;
}
