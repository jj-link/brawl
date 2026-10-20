#pragma force_active on
struct S {
    int pad[2];
    unsigned int f : 2;
    unsigned int rest : 30;
};

extern "C" void fn_49_6B54(struct S *s, unsigned int v)
{
    s->f = v;
}
