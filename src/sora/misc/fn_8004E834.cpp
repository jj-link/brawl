#pragma force_active on
typedef unsigned int u32;

struct Inner {
    char pad[0x268];
    u32 flags;
};

struct Outer {
    char pad[0x24];
    Inner *inner;
};

extern "C" {
u32 fn_8004E834(Outer *p)
{
    return (p->inner->flags >> 3) & 1;
}
}
