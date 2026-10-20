#pragma force_active on
struct Bits {
    unsigned int a : 5;
    unsigned int f : 5;
    unsigned int b : 22;
};

struct Obj {
    unsigned int w0;
    unsigned int w1;
    Bits bits;
};

extern "C" void fn_27_1A4DFC(Obj *p, unsigned int v)
{
    p->bits.f = v;
}
