#pragma force_active on
extern "C" void fn_8009C9DC(unsigned char* p, unsigned int bit) {
    if (bit < 7) {
        p[0x45] &= ~(unsigned char)(1 << bit);
    }
}
