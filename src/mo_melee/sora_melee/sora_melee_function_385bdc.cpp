#pragma force_active on
struct Bits {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 12;
};

struct Outer {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_385BDC(Outer *p, unsigned int v)
{
    p->bits.b = v;
}
