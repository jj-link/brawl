#pragma force_active on
typedef unsigned char u8;

struct Inner {
    char pad[0x19];
    u8 flags;
};

struct Outer {
    Inner *inner;
};

extern "C" unsigned int fn_27_1119B8(Outer *p)
{
    return p->inner->flags & 0xF;
}
