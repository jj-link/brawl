#pragma force_active on
struct Bits {
    unsigned int hi : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_1A52F0(void *p, unsigned int v) {
    struct Bits *b = (struct Bits *)((char *)p + 8);
    b->hi = v;
}
