#pragma force_active on
struct Inner {
    int pad[154];
    unsigned int flags;
};

struct Outer {
    int pad[9];
    Inner *inner;
};

extern "C" unsigned int fn_8004E7C8(Outer *o)
{
    return o->inner->flags & 1;
}
