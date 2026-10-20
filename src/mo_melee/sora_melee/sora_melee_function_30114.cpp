#pragma force_active on
struct Inner {
    char pad[0x6c];
    int value;
};

struct Outer {
    int pad;
    Inner *inner;
};

extern "C" {
int fn_27_30114(Outer *self) {
    return (self->inner->value >> 24) == 1;
}
}
