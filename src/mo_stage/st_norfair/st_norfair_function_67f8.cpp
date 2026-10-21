#pragma force_active on

struct S {
    unsigned int pad[2];
    unsigned int field : 2;
    unsigned int : 30;
};

extern "C" void fn_54_67F8(S *s, unsigned int v)
{
    s->field = v;
}
