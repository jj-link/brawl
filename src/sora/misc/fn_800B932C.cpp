#pragma force_active on
struct Inner {
    char pad[0x4c];
    unsigned long off;
    char* base;
};

struct Mid {
    char pad[0x1d0];
    struct Inner* inner;
};

struct Obj {
    char pad[0x8];
    struct Mid* mid;
};

extern "C" void fn_800B932C(struct Obj* self) {
    struct Inner* in = self->mid->inner;
    in->base[in->off] = 1;
}
