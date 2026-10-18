#pragma force_active on
struct FtMarioBitState {
    unsigned char pad[0x1c];
    unsigned int* flags;
};

extern "C" {
void fn_91_A784(FtMarioBitState* state, unsigned int mask, unsigned int index) {
    state->flags[index] &= ~mask;
}
}
