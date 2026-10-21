#pragma force_active on

struct S {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int rest : 30;
};

extern "C" void fn_57_ACCC(struct S *s, unsigned int v)
{
    s->a = v;
}
