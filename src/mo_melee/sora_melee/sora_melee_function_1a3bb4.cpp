#pragma force_active on
struct Bits {
    unsigned int hi : 10;
    unsigned int f : 10;
    unsigned int lo : 12;
};

struct Outer {
    unsigned int w0;
    unsigned int w1;
    Bits b;
};

extern "C" void fn_27_1A3BB4(Outer *p, unsigned int v)
{
    p->b.f = v;
}
