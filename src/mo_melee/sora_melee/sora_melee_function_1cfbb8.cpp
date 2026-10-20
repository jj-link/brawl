#pragma force_active on
struct Bits2 {
    unsigned int a : 12;
    unsigned int f : 6;
    unsigned int b : 14;
};

struct Obj2 {
    unsigned int w0;
    unsigned int w1;
    Bits2 w2;
};

extern "C" void fn_27_1CFBB8(Obj2 *obj, unsigned int val)
{
    obj->w2.f = val;
}
