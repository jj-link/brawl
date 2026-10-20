#pragma force_active on
struct S {
    int pad[2];
    unsigned int hi : 2;
    unsigned int x : 2;
    unsigned int rest : 28;
};

extern "C" void fn_27_CDE7C(S* s, unsigned int v)
{
    s->x = v;
}
