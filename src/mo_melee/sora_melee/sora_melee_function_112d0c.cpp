#pragma force_active on
struct Inner {
    char pad[0x4c4];
    float value;
};

struct Outer {
    Inner* inner;
};

extern "C" void fn_27_112D0C(Outer* self, float val) {
    self->inner->value = val;
}
