#pragma force_active on
struct Inner {
    unsigned char pad[0x40];
    void* f40;
    void* f44;
};

struct Mid {
    unsigned char pad[0x8];
    Inner* inner;
};

struct Outer {
    unsigned char pad[0x35c];
    Mid* mid;
};

extern "C" void fn_1_7A94(Outer* self, void* a, void* b) {
    Inner* i = self->mid->inner;
    i->f40 = a;
    i->f44 = b;
}
