#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" {
void fn_27_1CFA48(Obj* p, u32 v)
{
    p->bits.b = v;
}
}
