#pragma force_active on
struct FlagPair {
    int pad[2];
    unsigned int m8;
    unsigned int mC;
};

extern "C" void fn_27_7B4BC(FlagPair* self, int idx, unsigned int flag) {
    if (idx <= -1 || idx >= 0x11) {
        return;
    }
    unsigned int bit = 1u << idx;
    self->m8 |= bit;
    if (flag == 1) {
        self->mC |= bit;
    } else {
        self->mC &= ~bit;
    }
}
