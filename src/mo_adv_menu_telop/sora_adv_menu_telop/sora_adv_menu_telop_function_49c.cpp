#pragma force_active on
struct Telop {
    unsigned char padding[0x4C];
    int state;
};

extern "C" bool fn_38_49C(const Telop* self) {
    return self->state < 6;
}
