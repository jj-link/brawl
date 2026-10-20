#pragma force_active on
typedef unsigned int u32;

struct Inner {
    u32 unk0;
    u32 unk4;
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

struct Outer {
    u32 unk0;
    Inner *inner;
};

extern "C" {
u32 fn_27_B1D98(Outer *p)
{
    return p->inner->b;
}
}
