#pragma force_active on
struct Inner {
    char pad[0x20];
    void *value;
};

struct Outer {
    char pad[0xd8];
    Inner *inner;
};

extern "C" {
void *fn_112_F128(Outer *self)
{
    return self->inner->value;
}
}
