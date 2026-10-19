#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 pad0;
    u8 state;
};

struct Outer {
    u8 pad[0x194];
    Inner* inner;
};

extern "C" void fn_51_D344(Outer* self) {
    Inner* in = self->inner;
    if (in == 0) {
        return;
    }
    if (in->state <= 1) {
        return;
    }
    in->state = 4;
}
