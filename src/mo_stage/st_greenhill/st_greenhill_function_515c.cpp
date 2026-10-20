#pragma force_active on
struct S {
    unsigned int a[2];
    unsigned int top : 2;
    unsigned int rest : 30;
};

extern "C" {
void fn_72_515C(S *s, unsigned int v)
{
    s->top = v;
}
}
