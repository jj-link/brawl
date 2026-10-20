#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

struct Obj {
    u32 w0;
    u32 w1;
    Bits bits;
};

extern "C" void fn_27_1A1998(Obj *obj, u32 value)
{
    obj->bits.b = value;
}
