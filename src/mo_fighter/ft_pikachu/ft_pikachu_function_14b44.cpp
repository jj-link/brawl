#pragma force_active on
struct PikachuState {
    unsigned char padding[0xA4];
    unsigned char : 1;
    unsigned char enabled : 1;
    unsigned char : 6;
};

extern "C" void fn_98_14B44(PikachuState* self, unsigned int value) {
    self->enabled = value;
}
