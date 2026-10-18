#pragma force_active on
struct NessFlagOwner {
    unsigned char pad[0x1c];
    unsigned int* bits;
};

extern "C" {
void fn_101_D380(NessFlagOwner* self, unsigned int mask, unsigned int index) {
    self->bits[index] &= ~mask;
}
}
