#pragma force_active on
struct Inner {
    char pad[0x370];
    unsigned short field;
};

struct Outer {
    char pad[0x24];
    Inner* inner;
};

extern "C" void fn_8004B310(Outer* self, unsigned short val) {
    self->inner->field = val;
}
