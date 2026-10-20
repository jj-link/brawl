#pragma force_active on
struct Bits {
    unsigned int pad : 14;
    unsigned int field : 7;
    unsigned int tail : 11;
};

struct Obj {
    unsigned int a[2];
    Bits bits;
};

extern "C" void fn_27_1D0510(Obj* p, unsigned int value)
{
    p->bits.field = value;
}
