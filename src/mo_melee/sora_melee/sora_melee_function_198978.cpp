#pragma force_active on
struct Bits {
    unsigned int a : 3;
    unsigned int f : 3;
    unsigned int b : 26;
};

struct Obj {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_198978(Obj *obj, unsigned int val)
{
    obj->bits.f = val;
}
