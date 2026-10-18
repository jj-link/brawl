#pragma force_active on
struct FtCaptainBits {
    char pad[0x1c];
    unsigned int* bits;
};

extern "C" void fn_100_9880(FtCaptainBits* self, unsigned int mask, int index) {
    self->bits[index] &= ~mask;
}
