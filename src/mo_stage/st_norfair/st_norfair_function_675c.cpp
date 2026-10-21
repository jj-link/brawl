#pragma force_active on

struct S54 {
    unsigned int pad[2];
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_54_675C(S54 *s, unsigned int v)
{
    s->field = v & 3;
}
