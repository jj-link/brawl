#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int reserved : 4;
    unsigned int f : 2;
    unsigned int rest : 26;
};

extern "C" void fn_49_6CC8(struct S *s, unsigned int v)
{
    s->f = v;
}
