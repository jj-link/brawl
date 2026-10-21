#pragma force_active on

struct S54 {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int field : 2;
    unsigned int b : 26;
};

extern "C" void fn_54_6880(S54 *s, unsigned int v)
{
    s->field = v;
}
