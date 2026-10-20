#pragma force_active on
struct Inner {
    unsigned int pad[2];
    unsigned int flags;
};

struct Outer {
    unsigned int pad;
    Inner *inner;
};

extern "C" unsigned int fn_27_B1D74(Outer *p)
{
    return (p->inner->flags >> 26) & 7;
}
