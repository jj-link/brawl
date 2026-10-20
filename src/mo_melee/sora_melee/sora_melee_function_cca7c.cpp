#pragma force_active on
struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

struct Outer {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_CCA7C(Outer *p, unsigned int v)
{
    p->bits.b = v;
}
