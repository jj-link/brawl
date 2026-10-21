#pragma force_active on
struct FZeroState {
    unsigned char padding[8];
    unsigned int : 3;
    unsigned int field : 3;
    unsigned int : 26;
};

extern "C" void fn_61_E748(FZeroState* self, unsigned int value) {
    self->field = value;
}
