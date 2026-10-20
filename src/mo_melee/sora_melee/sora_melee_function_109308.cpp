#pragma force_active on
struct Inner {
    char pad[0x10a0];
    unsigned char flag;
};

struct Outer {
    char pad[0x15c];
    Inner *inner;
};

extern "C" {
void fn_27_109308(Outer *self) {
    self->inner->flag = 0;
}
}
