#pragma force_active on
struct Bits
{
    unsigned int pad : 4;
    unsigned int field : 2;
};

struct Obj
{
    unsigned int x[2];
    Bits bits;
};

extern "C" void fn_51_6578(Obj *a, unsigned int b)
{
    a->bits.field = b;
}
