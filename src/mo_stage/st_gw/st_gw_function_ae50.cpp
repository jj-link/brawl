#pragma force_active on
struct Bits {
    unsigned int hi : 2;
    unsigned int mid : 2;
    unsigned int lo : 28;
};

struct S {
    unsigned int a;
    unsigned int b;
    Bits flags;
};

extern "C" void fn_63_AE50(S *s, unsigned int v)
{
    s->flags.mid = v;
}
