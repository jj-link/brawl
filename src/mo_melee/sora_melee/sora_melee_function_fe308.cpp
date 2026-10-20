#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_FE308(Obj *p, u32 v)
{
    p->bits.b = v;
}
