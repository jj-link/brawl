#pragma force_active on
struct S {
    int pad[2];
    unsigned int a : 4;
    signed int b : 4;
    unsigned int c : 24;
};

extern "C" int fn_72_5394(S *s)
{
    return s->b;
}
