#pragma force_active on
struct S {
    char pad[8];
    unsigned int a : 4;
    unsigned int f : 4;
    unsigned int rest : 24;
};

extern "C" {
void fn_62_A698(S *s, unsigned int v)
{
    s->f = v;
}
}
