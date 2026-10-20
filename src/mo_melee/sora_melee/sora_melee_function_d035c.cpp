#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 7;
    u32 b : 7;
    u32 c : 18;
};

struct Obj {
    u32 unk0;
    u32 unk4;
    Bits bits;
};

extern "C" void fn_27_D035C(Obj *o, u32 v)
{
    o->bits.b = v;
}
