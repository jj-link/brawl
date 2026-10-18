#pragma force_active on
struct Inner {
    char pad[0x70];
    void *value;
};

struct Outer {
    char pad[0xd8];
    Inner *inner;
};

extern "C" void *fn_110_102F8(Outer *o)
{
    return o->inner->value;
}
