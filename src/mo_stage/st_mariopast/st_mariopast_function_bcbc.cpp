#pragma force_active on

struct S {
    unsigned int pad[2];
    unsigned int padbits : 12;
    unsigned int f : 6;
    unsigned int rest : 14;
};

extern "C" void fn_48_BCBC(S *s, unsigned int v)
{
    s->f = v;
}
