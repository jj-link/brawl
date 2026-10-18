#pragma force_active on
struct Inner {
    unsigned int unused;
    unsigned int value;
};

struct Outer {
    Inner *inner;
    unsigned char flag;
};

extern "C" unsigned int fn_113_2357C(Outer *self)
{
    if (self->flag == 1)
        return 0;
    return self->inner->value;
}
