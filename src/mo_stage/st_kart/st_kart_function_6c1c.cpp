#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int f : 2;
    unsigned int rest : 30;
};

extern "C" void fn_49_6C1C(S *s, unsigned int v)
{
    s->f = v;
}
