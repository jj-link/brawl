#pragma force_active on
struct Inner {
    int pad[6];
    unsigned int flags;
};

struct Outer {
    Inner *inner;
};

extern "C" unsigned int fn_90_12F4(Outer *o)
{
    return o->inner->flags & 1;
}
