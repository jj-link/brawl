#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 9;
    u32 b : 3;
    u32 c : 20;
};

struct Inner {
    char pad[8];
    Flags flags;
};

struct Outer {
    char pad[4];
    Inner *inner;
};

extern "C" void fn_27_B1E48(Outer *self, u32 v)
{
    Inner *in = self->inner;
    in->flags.b = v;
}
