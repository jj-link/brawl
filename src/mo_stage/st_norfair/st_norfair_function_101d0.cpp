#pragma force_active on
struct S54 {
    unsigned int pad[2];
    unsigned int a : 12;
    unsigned int b : 6;
    unsigned int c : 14;
};

extern "C" void fn_54_101D0(S54 *s, unsigned int v)
{
    s->b = v;
}
