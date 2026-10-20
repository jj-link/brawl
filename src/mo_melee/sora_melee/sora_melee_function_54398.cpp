#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 18;
    u32 field : 9;
    u32 lo : 5;
};

struct Obj {
    u32 pad0;
    u32 pad4;
    Bits bits;
};

extern "C" void fn_27_54398(Obj *p, u32 v)
{
    p->bits.field = v;
}
