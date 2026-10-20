#pragma force_active on
struct fn_54_65DC_S {
    unsigned int a;
    unsigned int b;
    unsigned int top : 2;
    unsigned int rest : 30;
};

extern "C" void fn_54_65DC(struct fn_54_65DC_S *s, unsigned int v)
{
    s->top = v;
}
